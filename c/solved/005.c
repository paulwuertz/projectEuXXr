/*
2520 is the smallest number that can be divided by each of the numbers from 1
to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the
numbers from 1 to 20?

---

Makes a doubly linked list of two numbers primfactors,
then compares each of the factors and takes the maximum of each
to calc their smallest common multiple c.

The c and the next number are processed till 20 is reached.
For some reason only works till finding the scm of 1..30 and for 31
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//doubly linked list for prim number list
typedef struct primFactor {
    long long int val;
    long long int pow;
    struct primFactor *next,*prev;
} primFactor;


void freePrimfactors(primFactor* p);


//adds one new primfactor to the end of p
//the p list is circular
void addPrimfactor(long long int num,primFactor* p){
    primFactor* n=malloc(sizeof(primFactor));
    //printf("new i %lu\n", num);
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
       }  //else {printf("%lu %lu nono\n", i,num);}
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
    while(n!=p){
        n=n->next;
        free(n->prev);
    }
    //free(p); 
}

int main(int argc, char const *argv[]){
    //read Number to calc to
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){    
        int a;
        scanf("%d",&a);
   
        //calcs common KGV from 2..a
        long long int c=2;
        for (long long int i = 3; i <= a; ++i){
            c=getKGV(c,i);
        }
        printf("%lli\n", c);
    }
    return 0;
}