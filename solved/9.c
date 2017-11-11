/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 \+ b2 = c2

For example, 32 \+ 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a \+ b \+ c = 1000.  
Find the product abc.

---

Excessive loops.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main(int argc, char const *argv[]){
    for (int c = 1; c < 998; ++c){
        for (int b = 1; c*c-b*b>0 && b<998 ; ++b){
            for (int a = 1; c*c-b*b-a*a>=0 && a<998 ; ++a){
                if(c*c-b*b-a*a==0 && c+b+a==1000) printf("a %d b %d c %d, a*b*c=%i \n", a,b,c,a*b*c);
            }
        }
    }
    return 0;
}
    