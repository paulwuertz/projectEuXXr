/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
that the 6th prime is 13.

What is the 10 001st prime number?

---

Loop and cnt var checking for primes, skipping even numbers...

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "primes.h"

int main(int argc, char const *argv[]){
    int a = atoi(argv[1]),cnt=1;
    for(int i=3;1;i+=2){
        if (isPrim(i)){
            cnt++;
            if (cnt==a){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
    