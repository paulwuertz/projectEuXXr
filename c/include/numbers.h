#ifndef NUMBERS
#define NUMBERS 1
#include "Array.h"
#include "primes.h"
#include <stdlib.h>

//compare function for qsort, assumuning a&&b > 0
int compare( const void* a, const void* b){
     return ( *(int*)a - *(int*)b );
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

//returns the Nth decimal digit of a number
//ie. (134,2)-> 1, (134,1)-> 3, (134,0)-> 4
int decimalDigit(double number,int pos){
    return ((int)(number/pow(10,pos)))%10;
}

//return the sum of int a's factors
int getFactorSum(int a){
    Array arr;
    initArray(&arr,64);
    getFactors(a, &arr, NULL);

    int sum=0;
    for (int i = 0; i < arr.used-1; ++i){
        sum+= *(arr.arr+i);
    }
    freeArray(&arr);
    return sum;
}

#endif