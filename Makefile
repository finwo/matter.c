TARGET ?= wasm32

include arch/$(TARGET)/config.mk

SRC=$(shell find -L arch/$(TARGET)/src -type f -name \*.c)
SRC+=$(shell find -L src -type f -name \*.c)
OBJ=$(SRC:.c=.o)

INCLUDES?=
INCLUDES+=-Iarch/$(TARGET)/include
INCLUDES+=-Iinclude

CFLAGS?=
CFLAGS+=-nostdinc -Wl,--allow-undefined

libmatter.a: $(OBJ)
	rm -f $@
	$(AR) -cvq $@ $(OBJ)

libmatter.so: $(OBJ)
	$(CC) -fPIC --shared $(CFLAGS) $(INCLUDES) -o $@ $(SRC)

%.o: %.c
	$(LLE) -Ofast -S $(CFLAGS) $(INCLUDES) -c $< -o $(@:.o=.ll)
	$(LLC) -filetype=obj -O3 $(@:.o=.ll)

.PHONY: clean
clean:
	rm -f $(shell find -L . -type f -name *.o)
	rm -f $(shell find -L . -type f -name *.ll)
