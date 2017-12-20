/*Surprisingly there are only three numbers that can be written as the sum of
fourth powers of their digits:

> 1634 = 14 \+ 64 \+ 34 \+ 44  
>  8208 = 84 \+ 24 \+ 04 \+ 84  
>  9474 = 94 \+ 44 \+ 74 \+ 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers
of their digits.

---

Test until 354294, because for y=9**5*n n==6 is the first where y<10**n.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "numbers.h"


double powNum(double a) {
    double sum=0;
    for (int i = 0; a > pow(10,i); ++i){
        sum+=pow(decimalDigit(((int)a),i),5);
    }
    return sum;
}

int main(int argc, char const *argv[]){
    int sum=0;
    for (double i = 1; i < 354294; i+=1){
        if(i == powNum(i)) sum+=i;
    }
    printf("%d\n", sum);
    return 0;
}
    