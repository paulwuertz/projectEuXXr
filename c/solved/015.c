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

long long int grid[501][501];

int main(int argc, char const *argv[]){
    int t; 
    scanf("%d",&t);
    int sizeX, sizeY;
    for (int i = 0; i < 501; ++i){
        grid[i][0]=1;
    }
    for (int i = 0; i < 501; ++i){
        grid[0][i]=1;
    }
    for(int a0 = 0; a0 < t; a0++){    
        scanf("%d %d", &sizeX, &sizeY);
        sizeX++; sizeY++;
        for (int x = 1; x < sizeX; x++){
            for (int y = 1; y < sizeY; y++){
                grid[x][y]= (grid[x-1][y]+grid[x][y-1]) % (1000000000+7);
            }
        }
        printf("%llu\n", grid[sizeX-1][sizeY-1] % (1000000000+7));
    }
    return 0;
}
    