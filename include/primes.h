#ifndef PRIMES
#define PRIMES 1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//doubly linked list for prim number list
typedef struct primFactor {
    long long int val;
    long long int pow;
    struct primFactor *next,*prev;
} primFactor;

int isPrim_int   (int num);  
int isPrim_lint  (long int num);  
int isPrim_llint (long long int num);

#define isPrim(_1, ...) _Generic((_1),                                  \
                              int:              isPrim_int,             \
                              long int:         isPrim_lint,            \
                              long long int:    isPrim_llint)(_1)

void addPrimfactor(long long int num,primFactor* p);
primFactor* getPrimfactors(long long int num);
void freePrimfactors(primFactor* p);

long long int getKGV(long long int numA,long long int numB);

#endif