
TARGET ?= wasm32

SRC=$(shell find -L src/$(TARGET) -type f -name *.c)
OBJ=$(SRC:.c=.o)

libmatter.a: $(OBJ)
	ar -cvq libmatter.a $(OBJ)

%.ll: %.c
	clang -Os $(CFLAGS) --target=$(TARGET) -nostdinc -fno-builtin -Iinclude -c $< -o $@

%.o: %.ll
	llc -march=$(TARGET) -filetype=obj -O3 $<

.PHONY: clean
clean:
	rm -f $(shell find -L . -type f -name *.o)
