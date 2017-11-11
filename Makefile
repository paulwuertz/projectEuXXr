NUMBERS := $(shell ls solved| sed 's/\(.*\)\..*/\1/')
FILES := $(shell ls solved)
.PHONY: all ${FILES}

INC := -Iinclude
LNK := -Llib
LIBS := -lprimes -lm

ALL := --std=c11 $(INC) $(LNK) 

all: ${FILES} primes
	echo "Success building $@"

${FILES}: 
	gcc $(ALL) solved/$*.c -o bin/$* $(LIBS)

${NUMBERS}: 
	gcc $(ALL) solved/$@.c -o bin/$@ $(LIBS)

primes: include/primes.o
	gcc -c include/primes.c -o include/primes.o -lm
include/primes.o: include/primes.c
	ar -rcs lib/libprimes.a include/primes.o