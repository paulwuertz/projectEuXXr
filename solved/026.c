/*A unit fraction contains 1 in the numerator. The decimal representation of the
unit fractions with denominators 2 to 10 are given:

> 1/2| = | 0.5  
> ---|---|---  
> 1/3| = | 0.(3)  
> 1/4| = | 0.25  
> 1/5| = | 0.2  
> 1/6| = | 0.1(6)  
> 1/7| = | 0.(142857)  
> 1/8| = | 0.125  
> 1/9| = | 0.(1)  
> 1/10| = | 0.1  
  
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
seen that 1/7 has a 6-digit recurring cycle.

Find the value of _d_ < 1000 for which 1/ _d_ contains the longest recurring
cycle in its decimal fraction part.

---

Checks the reminder by storing reminder=10%n and then
reminder=(10*reminder)%n in an array and breaks
if the reminder is repeated and compares the length to maxlen.

Breaks if reminder==0.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int num=1,maxlen=1;
    int reste[1000];
    for (int n = 1; n < 1000; ++n){
        int len=0,rest=10;
        while(rest!=0){
            rest=(rest*10)%n;
            reste[len]=rest;
            for (int i = 0; i < len; ++i){
                if (reste[i]==rest){
                    rest=0; //to break the loop
                    if(len>maxlen){
                        num=n;
                        maxlen=len;
                    } 
                }
            }
            len++;
        }
    }
    printf("%d %d \n",num, maxlen);
}
    