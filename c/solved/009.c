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

int find_triangle(int n){
    for (int c = 1; c < n-2; c++){
        for (int b = 1; c*c-b*b>0 && b<n-2 ; b++){
            for (int a = 1; c*c-b*b-a*a>=0 && a<n-2 ; a++){
                if(c*c-b*b-a*a==0 && c+b+a==n){
                    //printf("a %d b %d c %d, a*b*c=%i \n", a,b,c,a*b*c);
                    return a*b*c;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        
        int n; 
        scanf("%d",&n);
        printf("%i\n", find_triangle(n));
    }
    return 0;
}
    