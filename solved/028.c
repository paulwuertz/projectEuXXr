/*Starting with the number 1 and moving to the right in a clockwise direction a
5 by 5 spiral is formed as follows:

43 44 45 46 47 48 49
42 21 22 23 24 25 26   
41 20  7  8  9 10 27   
40 19  6 *1* 2 11 28   
39 18  5  4  3 12 29  
38 17 16 15 14 13 30
37 36 35 34 33 32 31 

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
formed in the same way?

---

Analyticly calculated the formular 
for the series of the 4 corners and summed them up
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/*
//Formulars for the for directions
int ur(int x){
    return 4*x*x+4*x+1;
}

int dr(int x){
    return 4*x*x-2*x+1;
}

int dl(int x){
    return 4*x*x+1;
}

int ul(int x){
    return 4*x*x+2*x+1;
}
//sum of the 4 formulas
long int cornerSum(int x){
    long int a=;
    return a;
}
*/

int main(int argc, char const *argv[]){
    long int a = 1;
    for (int x = 1; x <= 500; ++x){
        a+=16*x*x+4*x+4;
    }
    printf("%li\n", a);
    return 0;
}
    