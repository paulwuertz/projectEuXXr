/*Let d( _n_ ) be defined as the sum of proper divisors of _n_ (numbers less
than _n_ which divide evenly into _n_ ).  
If d( _a_ ) = _b_ and d( _b_ ) = _a_ , where _a_ ≠ _b_ , then _a_ and _b_ are
an amicable pair and each of _a_ and _b_ are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55
and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71
and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "numbers.h"

int getFactorSum(int a){
    Array arr;
    initArray(&arr,160);
    getFactors(a, &arr, NULL);

    int sum=0;
    for (int i = 0; i < arr.used-1; ++i){
        sum+= *(arr.arr+i);
    }
    freeArray(&arr);
    return sum;
}


int main(int argc, char const *argv[]){
    int sum=0;
    for (int i = 0; i <=10000; ++i){
        int t=getFactorSum(i);
        if(getFactorSum(t)==i && i!=t){
           sum+=i;
            //printf("%d %d\n", i,t);
        }
    }
    printf("%d\n", sum);
    return 0;
}