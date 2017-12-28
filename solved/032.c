/*We shall say that an n-digit number is pandigital if it makes use of all the
digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity
can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only
include it once in your sum.

---

Checks if product is pandigital and unique.
Tests from 1.. the sqrt of biggest pandigital
breaks the brute force loop if strlen(i,j,i*j)>j for inner loop

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "Array.h"

//checks if all chars from 1..9 are in the three numbers
int isPandigital(char* digits){
    if(strlen(digits)!=9) return 0;
    for (char i = '1'; i <= '9'; ++i){
        if(strchr(digits,i)==NULL) return 0;
    }
    return 1;
}

int main(int argc, char const *argv[]){
    double lim=sqrt(987654321)+1;
    char tri[36];
    int sum=0;
    //array for the product
    Array products;
    initArray(&products,20);
    //iter all numbers from 1.. the sqrt of biggest pandigital
    for (int i = 1; i < lim; ++i){
        for (int j = 1; j < lim; ++j){
            //put i,j,i*j as a string 
            sprintf(tri,"%d%d%d",i,j,i*j);
            //if the products is to big increasing 
            //the number will lead to no more results
            if(strlen(tri)>9) break;
            //if is pandigital and product is unique
            if(isPandigital(tri) && !isInArray(&products,i*j)){
                addArray(&products,i*j);
                sum+=i*j;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
    