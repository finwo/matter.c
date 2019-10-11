SRC=$(shell find src -type f -name *.c)
OBJ=$(SRC:.c=.o)

CC = clang
LD = wasm-ld
TARGET ?= wasm32
CFLAGS ?= -O3

matter.a: $(OBJ)
	ar rcs matter.a $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) --target=$(TARGET) -nostdinc -fno-builtin -Iinclude -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)
