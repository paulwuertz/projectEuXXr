/*_n_! means _n_ × ( _n_ − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,  
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

---

My first use of the gmplib. Interesting.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include <math.h>

int main(){
    mpz_t a;
    mpz_init (a);
    mpz_set_str (a, "1", 10); 
    for (long int m = 1; m < 100; ++m)
        mpz_mul_si(a,a,m);
    
    char* res = mpz_get_str(NULL,10,a);
    int sum=0;
    for (int i = 0; i < strlen(res); ++i)
        sum+=res[i]-'0';
    printf("%d\n", sum); 
    return 0; 
}