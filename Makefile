NUMBERS := $(shell ls solved| sed 's/\(.*\)\..*/\1/')
FILES := $(shell ls solved)
.PHONY: all ${FILES}

all: ${FILES}
	echo "Success building $@"

${FILES}:
	gcc solved/$*.c -o bin/$* -lm

${NUMBERS}:
	gcc solved/$@.c -o bin/$@ -lm
