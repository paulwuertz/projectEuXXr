#include "primes.h"
#include <stdlib.h>

//doubly linked list for prim number list
typedef struct Array {
    int used,size;
    int* arr;
} Array;

int compare( const void* a, const void* b){
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

void initArray(Array* arr,int size){
    arr->used=0;
    arr->size=size;
    arr->arr = (int*) malloc (size*sizeof(int));
    if(arr->arr==NULL) assert("Init of Array failed...");
}


void freeArray(Array* arr){
    free(arr->arr);
}

void addArray(Array* arr,int ele){
    arr->used++;
    if(arr->used>arr->size){ 
        arr->size*=2;
        arr->arr = (int*) realloc (arr->arr, arr->size * sizeof(int));
    }
    if(arr->arr==NULL) assert("Resize of Array failed...");
    *(arr->arr+arr->used-1)=ele;
}

//recursive function to get all divisors of a number in an dynamic array
//returns the Array of sorted divisors
//init call like  getFactors(45,arr,NULL)
void getFactors(int val, Array* arr, primFactor* p){      
    //get the primfactors on init call
    if(p==NULL){
        p=getPrimfactors(val); 
        val=1;
    }
    if(p->val<p->next->val){
        for(int i=0;i<=p->pow;i++) getFactors(val*(long long int)pow(p->val,i),arr,p->next);
    } else {
        for(int i=0;i<=p->pow;i++){
            addArray(arr,val*(long long int)pow(p->val,i));
        }
    }
    //free the primfactors on init call
    if (p->prev->val>=p->val && val==1) freePrimfactors(p);
    qsort( arr->arr, arr->used, sizeof(int), compare );
}