/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long int biggest=0,input=0;
double max=0;

//either divide and primPart rest or increas factor
//in principle divides number down and lowers the bar always to sqrt i.e.

// input-> 105, test to 11 -> 105 div by 2? -> no, 105 div by 3 -> yes, 105/3=35
// 35, new max 6 -> 35 div by 3 -> no, 35 div by 4 -> no, 35 div by 5 -> yes, 35/5=7, 
// test if 7 is prime -> yes, biggest = 7

//the return value, is weather the number is prim(1) or nonprim(0)
int primPart(long int num, long int fac){
    if(num%fac==0){
        long int nNum=num/fac;
        max=sqrt(nNum)+1;
        int prim=primPart(nNum,fac);
        if(fac>biggest && input%fac==0) biggest=fac;
        if(prim==1 && nNum>biggest && input%nNum==0) biggest=nNum;
        return 0;
    }
    if(fac<=max) return primPart(num, fac+1);
    if(fac>biggest && input%fac==0) biggest=fac;
    return 1;
}

int main(int argc, char const *argv[]){
    //reads the number 2 determine biggest prim factor
    long int a = atol(argv[1]);
    input=a;
    max=sqrt(a)+1;

    //determine biggest primfactor
    primPart(a,2);
    printf("%lu\n", biggest);
    return 0;
}