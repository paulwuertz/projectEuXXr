/*215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <gmp.h>
#include <string.h>

int main(){
    mpz_t a;
    mpz_init (a);
    mpz_set_str (a, "2", 10); 
    mpz_pow_ui(a,a,1000);
    
    char* res = mpz_get_str(NULL,10,a);
    int sum=0;
    for (int i = 0; i < strlen(res); ++i)
        sum+=res[i]-'0';
    printf("%d\n", sum); 
    return 0;
}
    