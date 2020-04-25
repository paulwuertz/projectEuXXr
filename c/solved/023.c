/*A perfect number is a number for which the sum of its proper divisors is
exactly equal to the number. For example, the sum of the proper divisors of 28
would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than
n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
number that can be written as the sum of two abundant numbers is 24. By
mathematical analysis, it can be shown that all integers greater than 28123
can be written as the sum of two abundant numbers. However, this upper limit
cannot be reduced any further by analysis even though it is known that the
greatest number that cannot be expressed as the sum of two abundant numbers is
less than this limit.

Find the sum of all the positive integers which cannot be written as the sum
of two abundant numbers.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "Array.h"
#include "numbers.h"

int getAboundandsBelow(Array* arr, int lim){
    for (int i = 0; i < lim; ++i){
        if (getFactorSum(i)>i){
            addArray(arr,i);
        }
    }
}

int getAboundandSumsPos(Array* arr, Array* abundants,int lim){
    for (int i = 0; i < abundants->used; ++i){
        for (int j = 0; j < abundants->used; ++j){
            if (getArray(abundants,i)+getArray(abundants,j)<=lim){
                setArray(arr,getArray(abundants,i)+getArray(abundants,j),1);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int lim=28123;
    
    Array arr;
    initArray(&arr,32);
    getAboundandsBelow(&arr,lim);

    Array neg;
    initArray(&neg,lim);
    getAboundandSumsPos(&neg,&arr,lim);

    int sum=0,ind=0;
    for (int i = 0; i < lim; ++i){
        if (getArray(&neg,i)!=1){
            sum+=i;
        }
    }
    printf("%d\n", sum);


    freeArray(&arr);
    freeArray(&neg);
    return 0;
}
    