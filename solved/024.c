/*A permutation is an ordered arrangement of objects. For example, 3124 is one
possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
are listed numerically or alphabetically, we call it lexicographic order. The
lexicographic permutations of 0, 1 and 2 are:

012 021 102 120 201 210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
5, 6, 7, 8 and 9?

---

Recursivly constructs all the permutations 
with the highest order digits starting to get 
the smallest decimal values first, thus constructing
in alphabetic order. Then halting and printing at #1000000 

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int cnt=0,goon=1;
int chars[10];

void perm(long int number, int digit){
    for (int i = 0; i < 10; ++i){
        if(chars[i]==0 && goon){
            //apply digit add position
            chars[i]=1;
            number+=i*pow(10,digit);
            //if all digits filled
            if(digit==0){
                cnt++;
                if(cnt==1000000){
                    printf("%d: %li\n", cnt, number);
                    goon=0;
                }
                //printf("%d: %d\n", cnt, number);
            }
            if(digit>0) perm(number,digit-1);
            //remove digit add position
            number-=i*pow(10,digit);
            chars[i]=0;
        }
    }
}

int main(int argc, char const *argv[]){
    perm(0,9);
    return 0;
}