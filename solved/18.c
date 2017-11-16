/*By starting at the top of the triangle below and moving to adjacent numbers on
the row below, the maximum total from top to bottom is 23.

**3**  
 **7** 4  
2 **4** 6  
8 5 **9** 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75  
95 64  
17 47 82  
18 35 87 10  
20 04 82 47 65  
19 01 23 75 03 34  
88 02 77 73 07 63 67  
99 65 04 28 06 16 70 92  
41 41 26 56 83 40 80 70 33  
41 48 72 33 47 32 37 16 94 29  
53 71 44 65 25 43 91 52 97 51 14  
70 11 33 28 77 73 17 78 39 68 17 57  
91 71 52 38 17 14 91 43 58 50 27 29 48  
63 66 04 68 89 53 67 30 73 16 69 87 40 31  
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

**NOTE:** As there are only 16384 routes, it is possible to solve this problem
by trying every route. However, [Problem 67](problem=67), is the same
challenge with a triangle containing one-hundred rows; it cannot be solved by
brute force, and requires a clever method! ;o)

---

Puts the pyramid into a 1-d indexed array.
Adds the values of the level above to bottom one, so that the result is maximal.
For each number it choses the bigger of the two neighbours on the top,
expect for the two elements on the sides, where there is only one option.

Then it searches on the last level for the biggest element.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int level=15;
int py[] = {75,  
95, 64,  
17, 47, 82,  
18, 35, 87, 10,  
20,  4, 82, 47, 65,  
19,  1, 23, 75,  3, 34,  
88,  2, 77, 73,  7, 63, 67,  
99, 65,  4, 28,  6, 16, 70, 92,  
41, 41, 26, 56, 83, 40, 80, 70, 33,  
41, 48, 72, 33, 47, 32, 37, 16, 94, 29,  
53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,  
70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,  
91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,  
63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,  
04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23};

int getpy(int ele, int level){
    assert(ele<=level && "Element # max == level");
    return py[(level*level+level)/2+ele];
}

void addpy(int val, int ele, int level){
    assert(ele<=level && "Element # max == level");
    py[(level*level+level)/2+ele]+=val;
}

int main(int argc, char const *argv[]){
    for (int l = 1; l < level; ++l){
        for (int e = 0; e <= l; ++e){
            if(e!=0 && e!=l) {
                if(getpy(e-1,l-1)>getpy(e,l-1))
                    addpy(getpy(e-1,l-1),e,l);
                else
                    addpy(getpy(e,l-1),e,l);
            }
            else if(e==0) addpy(getpy(0,l-1),e,l);
            else if(e==l) addpy(getpy(e-1,l-1),e,l);
        }
    }

    int biggest=0;
    for (int i = 0; i < level; ++i){
        if(getpy(i,level-1)>biggest) biggest=getpy(i,level-1);
    }
    printf("%d\n", biggest);
    return 0;
}
    