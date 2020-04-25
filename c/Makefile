NUMBERS := $(shell ls solved/*c | xargs -n1 basename | sed 's/\(.*\)\..*/\1/')
FILES := $(shell ls solved/*.c | xargs -n1 basename)
.PHONY: all ${FILES} run

INC := -Iinclude
LNK := -Llib
LIBS := -lm -lgmp

ALL := --std=c11 -O2 -g $(INC) $(LNK) 

all: ${FILES} 
	echo "Success building $@"

${FILES}: 
	gcc $(ALL) solved/$*.c -o bin/`basename $*` $(LIBS)

${NUMBERS}: 
	gcc $(ALL) solved/$@.c -o bin/$@ $(LIBS)

