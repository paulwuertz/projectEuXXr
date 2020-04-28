/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

---

### project euler

Just a loop and a condition, boring...

### hacker rank

The loop thing was to slow for two test.
I changed it to use the euler formular for sums.

*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){    
        int a;
        scanf("%d",&a);
        a--;
        unsigned long long s3 = (a/3);
        unsigned long long s5 = (a/5);
        unsigned long long s15 = (a/15);
        
        unsigned long long sum3 =  3* ((s3*s3+s3)/2);
        unsigned long long sum5 =  5* ((s5*s5+s5)/2);
        unsigned long long sum15 = 15*((s15*s15+s15)/2);
        printf("%lu\n", sum3+sum5-sum15);
    }
    return 0;
}