/*The Fibonacci sequence is defined by the recurrence relation:

> F _n_ = F _n_ −1 \+ F _n_ −2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

> F1 = 1  
>  F2 = 1  
>  F3 = 2  
>  F4 = 3  
>  F5 = 5  
>  F6 = 8  
>  F7 = 13  
>  F8 = 21  
>  F9 = 34  
>  F10 = 55  
>  F11 = 89  
>  F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000
digits?

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char const *argv[]){
    mpz_t a,b,c;
    mpz_init (a);
    mpz_init (b);
    mpz_init (c);
    mpz_set_str (a, "1", 10);
    mpz_set_str (b, "1", 10);

    int ind=2;
    char* res; 
    while (strlen(res)<1000){
        mpz_add(c,a,b);
        mpz_set(a,b);
        mpz_set(b,c);
        res = mpz_get_str(NULL,10,c);
        ind++;
    }
    printf("%d\n", ind); 
    return 0; 
}
    