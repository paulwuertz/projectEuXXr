/*Starting in the top left corner of a 2×2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner.

![](project/images/p015.gif)

How many such routes are there through a 20×20 grid?

---

Did this riddle some years ago in school, really like it ;)

There is only one possibility for the sides so, first row and col are all = 1
the rest is the sum of the possibilities above and left from the gridpoint
the resulting number over the grid form the triangle of pascal :)

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

long long int grid[21][21];
int size=21;

int main(int argc, char const *argv[]){
    for (int i = 0; i < size; ++i){
        grid[i][0]=1;
        grid[0][i]=1;
    }
    for (int x = 1; x < size; x++){
        for (int y = 1; y < size; y++){
            grid[x][y]=grid[x-1][y]+grid[x][y-1];
        }
    }
    printf("%llu\n", grid[size-1][size-1]);
    return 0;
}
    