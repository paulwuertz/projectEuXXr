/*The sum of the squares of the first ten natural numbers is,

12 \+ 22 \+ ... + 102 = 385

The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.

---

A loop for summing squares
the famous euler form for summing ,then squared
and the difference of both.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){    
        int a;
        scanf("%d",&a);

        long int sumOS=0;
        for (long int i = 0; i <= a; ++i){
            sumOS+=i*i;
        }
        long int sqrtOS=(a*a+a)/2;
        sqrtOS*=sqrtOS;

        printf("%lu\n", sqrtOS-sumOS);
    }
    return 0;
}
    