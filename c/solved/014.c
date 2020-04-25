/*The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)  
n → 3n \+ 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains
10 terms. Although it has not been proved yet (Collatz Problem), it is thought
that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

**NOTE:** Once the chain starts the terms are allowed to go above one million.

---

Using recursiv colatz function with long long int,
checking if n is even and n/2<the current biggest gave speedup by factor ~2

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>

long long int collatz(long long int number, long long int depth){
    if(number==1) return depth;
    else if(number%2==0) return collatz(number/2,depth+1);
    else                 return collatz(number*3+1,depth+1);
}

int main(int argc, char const *argv[]){
    long int a = atoi(argv[1]);

    //using improved loop
    int num=1;
    clock_t start = clock();
    long long int biggest=0,col=0;
    while(num<a){
        if((num%2==1) || (num%2==0 && num/2>col)){
            long long int c=collatz(num,0);
            if(c>biggest) {
                biggest=c;
                col=num;
            }
        }
        num+=1;
    }
    clock_t end = clock();
    float time2 = (float)(end - start)/CLOCKS_PER_SEC;

    printf("%lli has %lli factors needing %lf secs\n", col,biggest, time2);

    //using naive loop
    biggest=0;col=0;num=1;
    start = clock();
    while(num<a){
        long long int c=collatz(num,0);
        if(c>biggest) {
            biggest=c;
            col=num;
        }
        num+=1;
    }
    end = clock();
    float time1 = (float)(end - start)/CLOCKS_PER_SEC;
    printf("%lli has %lli factors needing %lf secs\n", col,biggest, time1);
    printf("Using primfactors is faster by factor %lf secs\n", time1/time2);
    return 0;
}
    