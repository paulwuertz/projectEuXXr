/*If the numbers 1 to 5 are written out in words: one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in
words, how many letters would be used?

  

**NOTE:** Do not count spaces or hyphens. For example, 342 (three hundred and
forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
letters. The use of "and" when writing out numbers is in compliance with
British usage.

---

One part for part < 100 (8 conditions), one for < 100 (one condition) + const for 1000

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int numLetters[12] = {3,3,5,4,4,3,5,5,4,3,6,6};

int main(int argc, char const *argv[]){
    long int a = 1000;
    int sum=0;
    for (int i = 1; i <= a; ++i){
        int sumO=sum;
        if (i==1000) {
            sum+=11;
            continue;
        }

        int gt100 = i - i%100;
        int lt100 = i%100;
        if(gt100>=100)  sum+=numLetters[gt100/100-1]+3*(lt100!=0)+7; // 3 for and const if lt100!=0 + 1-9 const + 7 const for 100

        if(lt100<13)   sum+=numLetters[lt100-1]; // 1-13 const
        else if(lt100==13)  sum+=8; // drop in t exception
        else if(lt100==15)  sum+=7; // drop in e exception
        else if(lt100==18)  sum+=8; // drop in t exception
        else if(lt100<20)   sum+=numLetters[lt100%10-1]*(lt100%10!=0)+4; // 1-9 + const 4 for teen
        else if(lt100<40)   sum+=numLetters[lt100%10-1]*(lt100%10!=0)+6; // 1-9 const; const 6 for 20&30ty 
        else if(lt100<70)   sum+=numLetters[lt100%10-1]*(lt100%10!=0)+5; // 1-9 const; const 6 for 60ty&50&40ty 
        else if(lt100<80)   sum+=numLetters[lt100%10-1]*(lt100%10!=0)+7; // 1-9 const; const 7 for 70ty 
        else if(lt100<100)  sum+=numLetters[lt100%10-1]*(lt100%10!=0)+6; // 1-9 const; const 6 for 80&90ty 
    }
    printf("%d\n", sum);
    return 0;
}
    