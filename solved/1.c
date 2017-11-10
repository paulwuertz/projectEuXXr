/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

---

Just a loop and a contition, boring...
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int a = atoi(argv[1]);
    int sum=0;
    //process from one to 'a'
    for (int i = 0; i < a; ++i){
        //add if divisible by 3 or 5 to sum
        if(i%3==0 || i%5==0) sum+=i;
    }
    printf("%i\n", sum);
    return 0;
}