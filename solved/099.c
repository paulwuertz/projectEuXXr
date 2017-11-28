/*Comparing two numbers written in index form like 211 and 37 is not difficult,
as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more
difficult, as both numbers contain over three million digits.

Using [base_exp.txt](project/resources/p099_base_exp.txt) (right click and
'Save Link/Target As...'), a 22K text file containing one thousand lines with
a base/exponent pair on each line, determine which line number has the
greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example
given above.

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen("resources/99.txt", "r");
    if (fp == NULL) exit(EXIT_FAILURE);

    int linenum=0,bigln=-1;
    double base=0, exp=0;
    double biggest=0;
    //while ((read = getline(&line, &len, fp)) != -1) {
    //    linenum++;
    //    sscanf("%lf,%lf",line,&base,&exp);
    //    printf("%lf eee %lf\n",base,exp );
    //}

    while(fscanf(fp,"%lf,%lf\n",&base,&exp) == 2){
        linenum++;
        if(exp*log(base)>biggest){
            bigln=linenum;
            biggest=exp*log(base);
        } 
    }

    printf("%d\n", bigln);

    fclose(fp);
    if (line) free(line);
    exit(EXIT_SUCCESS);
}