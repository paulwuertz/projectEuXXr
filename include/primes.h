#ifndef PRIMES
#define PRIMES 1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//doubly linked list for prim number list
typedef struct primFactor {
    long long int val;
    long long int pow;
    struct primFactor *next,*prev;
} primFactor;

int isPrim_int   (int num);  
int isPrim_lint  (long int num);  
int isPrim_llint (long long int num);

#define isPrim(_1, ...) _Generic((_1),                                  \
                              int:              isPrim_int,             \
                              long int:         isPrim_lint,            \
                              long long int:    isPrim_llint)(_1)

void addPrimfactor(long long int num,primFactor* p);
primFactor* getPrimfactors(long long int num);
void freePrimfactors(primFactor* p);

long long int getKGV(long long int numA,long long int numB);

//the return value, is weather the number is prim(1) or nonprim(0)
int isPrim_int(int num){
    if(num%2==0 || num<2) return 0;
    int sqr=sqrt(num);
    for (int i = 3; i < sqr+1; i+=2){
        if (num%i==0) return 0;
    }
    return 1;
}
int isPrim_lint(long int num){
    if(num%2==0 || num<2) return 0;
    long int sqr=sqrtl(num);
    for (long int i = 3; i < sqr+1; i+=2){
        if (num%i==0) return 0;
    }
    return 1;
}
int isPrim_llint(long long int num){
    if(num%2==0 || num<2) return 0;
    long long int sqr=sqrt(num);
    for (long long int i = 3; i < sqr+1; i+=2){
        if (num%i==0) return 0;
    }
    return 1;
}

//adds one new primfactor to the end of p
//the p list is circular
void addPrimfactor(long long int num,primFactor* p){
    primFactor* n=malloc(sizeof(primFactor));
    assert(n && "Prim malloc failed...");
    //next element
    n->val=num;
    n->pow=1;
    n->prev=p->prev;
    n->next=p;
    //circle link with begining
    p->prev->next=n;
    p->prev=n;
    return;
}

//returns the primfactors of num
primFactor* getPrimfactors(long long int num){
    primFactor* p=malloc(sizeof(primFactor));
    assert(p && "Prim malloc failed...");
    p->next=p;
    p->prev=p;
    p->val=0;
    long long int maxNum=((long long int)sqrt(num))+1;

    for (long long int i = 2; i <= maxNum && num!=1; i++){
       if (num%i==0){
           if (!p->val){
                p->val=i;
                p->pow=1;
           } else {
                if(p->prev->val==i) p->prev->pow++;
                else                addPrimfactor(i,p);
           }
           //test i again, if pow>1
           num/=i;
           i--;
        }
    }
    if(num!=1) addPrimfactor(num,p);
    return p;
}

//takes two ints, calcs their KGV(smallest common dinominator) 
//based on both ints primfactors
long long int getKGV(long long int numA,long long int numB){
    primFactor *p1 = getPrimfactors(numA),*p2 = getPrimfactors(numB);
    primFactor* p1i=p1, *p2i=p2;
    long long int kgv=1;
    int p1t=1,p2t=1;
    do {
        if(p1->val==p2->val){
            int biggest = p1->pow > p2->pow ? p1->pow : p2->pow;
            kgv*=((long long int)pow(p1->val,biggest));
            p1=p1->next;
            p2=p2->next;
            p1t=0;p2t=0;
        } else if((p1->val<p2->val || (p2==p2i && !p2t)) && (p1!=p1i || p1t)){
            kgv*=((long long int)pow(p1->val,p1->pow));
            p1=p1->next;
            p1t=0;
        } else if((p1->val>p2->val || (p1==p1i && !p1t)) && (p2!=p2i || p2t)){
            kgv*=((long long int)pow(p2->val,p2->pow));
            p2=p2->next;
            p2t=0;
        }
    } while(p1!=p1i || p2!=p2i || p1t || p2t);
    freePrimfactors(p1);
    freePrimfactors(p2);
    return kgv;
}

// frees all the members of the primfactors
void freePrimfactors(primFactor* p){
    primFactor *n=p->next;
    free(p);
    while(n!=p){
        n=n->next;
        free(n->prev);
    }
}

#endif