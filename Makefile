SRC=$(shell find src -type f -name *.c)
OBJ=$(SRC:.c=.o)

CC = clang
LD = wasm-ld
TARGET ?= wasm32
CFLAGS ?= -O3

libmatter.a: $(OBJ)
	ar rcs libmatter.a $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) --target=$(TARGET) -nostdinc -fno-builtin -Iinclude -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)
