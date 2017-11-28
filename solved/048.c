/*The series, 11 \+ 22 \+ 33 \+ ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 \+ 22 \+ 33 \+ ... + 10001000.

---

A loop using gmp.

Funny for me was comparing it to the python onliner:
sum([i**i for i in range(1000)])
which uses 8888k RAM and and .05sec on my machine compared to
1812k and 0.00sec to the ~20 line c version.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <gmp.h>

int main(int argc, char const *argv[]){
    long int a = atoi(argv[1]);

    mpz_t sum, pow;
    mpz_init (sum);
    mpz_init (pow);
    mpz_set_str (sum, "1", 10);
    mpz_set_str (pow, "0", 10);

    for (unsigned long int m = 1; m < a; ++m){
        mpz_set_ui(pow,m);
        mpz_pow_ui(pow,pow,m);
        mpz_add(sum,sum,pow);
    }
    
    char* res = mpz_get_str(NULL,10,sum);
    printf("%s\n", res); 

    return 0;
}
    