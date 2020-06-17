TARGET ?= wasm32

include arch/$(TARGET)/config.mk

SRC=$(shell find -L arch/$(TARGET)/src -type f -name \*.c)
SRC+=$(shell find -L src -type f -name \*.c)
OBJ=$(SRC:.c=.o)

libmatter.a: $(OBJ)
	rm -f $@
	$(AR) -cvq $@ $(OBJ)

%.o: %.c
	$(LLE) -Ofast -S $(CFLAGS) -nostdinc -fno-builtin -Iinclude -Iarch/$(TARGET)/include -c $< -o $(@:.o=.ll)
	$(LLC) -filetype=obj -O3 $(@:.o=.ll)

.PHONY: clean
clean:
	rm -f $(shell find -L . -type f -name *.o)
	rm -f $(shell find -L . -type f -name *.ll)
