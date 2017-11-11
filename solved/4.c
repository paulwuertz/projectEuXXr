/*

A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

---

Gets nth digit by dividing ints by powers nth power of 10,
then compares digit i with len-i for i..len/2
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//returns the Nth decimal digit of a number
//ie. (134,2)-> 1, (134,1)-> 3, (134,0)-> 4
int decimalDigit(int number,int pos){
    return ((int)(number/pow(10,pos)))%10;
}

int main(int argc, char const *argv[]){
    int largest=0;
    //multiply all 3 digit numbers
    for (int i = 100; i < 1000; ++i){
        for (int j = 100; j < 1000 && j<=i; ++j){
            int num = i*j;
            int digits = ((int)log(num)/log(10));
            int comparisions = (digits+1)/2;
            int isPal = 1;
            //test if is palindrom
            for (int k = 0; k < comparisions; ++k){
                // if number is no palindrom skip number
                if(decimalDigit(num,k)!=decimalDigit(num,digits-k)){
                    isPal=0;
                    break;
                }
            }
            //refresh biggest
            if (isPal && num>largest) largest=num;
        }
    }
    printf("%d\n", largest);
    return 0;
}