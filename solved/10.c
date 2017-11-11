/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "primes.h"

int main(int argc, char const *argv[]){
    long int a = atoi(argv[1]);
    long int sum=2;
    for (int i = 3; i <= a; i+=1){
        if(isPrim(i)) sum+=i;
    }
    printf("%li\n", sum);
    return 0;
}
    