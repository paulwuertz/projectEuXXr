/*Using [names.txt](project/resources/p022_names.txt) (right click and 'Save
Link/Target As...'), a 46K text file containing over five-thousand first
names, begin by sorting it into alphabetical order. Then working out the
alphabetical value for each name, multiply this value by its alphabetical
position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is
worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

---

Simple parser, sorting with library qsort and calculating sum.

*/
#define uint unsigned int
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

//struct containing name and value
typedef struct entry{
    char name[50];
    int val;
} entry;

uint num_en=0;   //number of elements in en
entry en[10000]; //fixed size array for name entries

//read all names and stuff into fix size array
void read_names (const char* file_name){
    FILE* file = fopen (file_name, "r");
    char b;char name[50];
    int open=0,len=0;
      
    while (!feof (file)){  
        fscanf (file, "%c", &b);
        if(b=='\"' && open){
            name[len]='\0';
            strncpy(en[num_en].name, name, len+2);
            len=0;
            num_en++;
            open = open^1;
        } else if(open){
            name[len]=b;
            len++;
        } else if(b=='\"'){
            open = open^1;
        }
    }
    fclose (file);       
}

int main(int argc, char const *argv[]){
    //read the names
    read_names("resources/22.txt"); 

    //calc the score for all elements
    for (int i = 0; i < num_en; ++i){
          for (int j = 0; j < strlen(en[i].name); ++j){
                en[i].val += en[i].name[j]-'A'+1;    
          }
    }

    //sort alphabetically
    qsort (en, num_en, sizeof(entry), strcmp);  

    //calc sum
    uint sum=0;
    for (int i = 0; i < num_en; ++i){
        sum+=(i+1)*en[i].val;
        //printf("%s %d %lu\n", en[i].name, en[i].val, strlen(en[i].name));
    }
    printf("%d\n", sum);
    return 0;
}
    