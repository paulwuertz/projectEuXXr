/*By starting at the top of the triangle below and moving to adjacent numbers on
the row below, the maximum total from top to bottom is 23.

**3**  
 **7** 4  
2 **4** 6  
8 5 **9** 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in
[triangle.txt](project/resources/p067_triangle.txt) (right click and 'Save
Link/Target As...'), a 15K text file containing a triangle with one-hundred
rows.

**NOTE:** This is a much more difficult version of [Problem 18](problem=18).
It is not possible to try every route to solve this problem, as there are 2 99
altogether! If you could check one trillion (1012) routes every second it
would take over twenty billion years to check them all. There is an efficient
algorithm to solve it. ;o)

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int *values=NULL, size=0, level=0;

void read_pyramid (const char* file_name){
    FILE* file = fopen (file_name, "r");
    size=0;
    values = malloc (size * sizeof(int));
    if (values==NULL){ puts ("Error mallocating memory"); exit (1); }
      
    while (!feof (file)){  
        size++;      
        values = (int*) realloc (values, size * sizeof(int));
        if (values==NULL){ puts ("Error (re)allocating memory"); exit (1); }
        fscanf (file, "%d", values+size-1);
    }
    fclose (file);       
}

int getpy(int ele, int level){
    assert(ele<=level && "Element # max == level");
    return *(values+((level*level+level)/2+ele));
}

void addpy(int val, int ele, int level){
    assert(ele<=level && "Element # max == level");
    *(values+((level*level+level)/2+ele))+=val;
}

int main(int argc, char const *argv[]){
    read_pyramid("resources/67.txt");
    level=(int)(sqrt(2*size));
    //like in 18.c
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
    