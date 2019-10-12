
CC = clang
LD = wasm-ld
TARGET ?= wasm32
CFLAGS ?= -Os

SRC=$(shell find -L src/$(TARGET) -type f -name *.c)
OBJ=$(SRC:.c=.o)

libmatter.a: $(OBJ)
	ar -cvq libmatter.a $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) --target=$(TARGET) -nostdinc -fno-builtin -Iinclude -c $< -o $@

.PHONY: clean
clean:
	rm -f $(shell find -L . -type f -name *.o)
