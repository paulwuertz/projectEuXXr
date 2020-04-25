/*In England the currency is made up of pound, £, and pence, p, and there are
eight coins in general circulation:

> 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

> 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

---

Using recursive function subtracting all possibble amounts of every coin from
the given starting value.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//tries to take a given amount of money down into all
//possible coin combinations recursivly
//
// amount - the initial amount
// buf    - the tolerance buffer to deal with numerical uncertaincies
// coins  - an array of coin values
// coinXofN- the actual coin, use 0 to start the function
// coinN  - number of coins
// possib.- number of possibilities
void divide(int amount, int* coins, int coinXofN, int coinN, long int* possibilities){
    //money split up evenly
    if(amount==0){
        (*possibilities)++;
        return;
    }
    //dont execeed array
    if (coinXofN >= coinN) return;
    //if not split up yet
    if(amount>0) {
        //actual coin
        int aCoin=*(coins+coinXofN);
        for (int i = 0; i <= amount/aCoin; ++i){
            divide(amount-i*aCoin,coins,coinXofN+1,coinN,possibilities);
        }
    }
}

int main(int argc, char const *argv[]){
    long int pos=0;
    int coins[]={200,100,50,20,10,5,2,1};
    divide(200, coins, 0, sizeof(coins)/sizeof(coins[0]),&pos);
    printf("%li\n", pos);
    return 0;
}
    