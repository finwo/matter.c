
TARGET ?= wasm32

SRC=$(shell find -L src/arch/$(TARGET) -type f -name *.c)
OBJ=$(SRC:.c=.o)

libmatter.a: $(OBJ)
	ar -cvq libmatter.a $(OBJ)

%.o: %.c
	clang -Os -S -emit-llvm $(CFLAGS) --target=$(TARGET) -nostdinc -fno-builtin -Iinclude -c $< -o $(@:.o=.ll)
	llc -march=$(TARGET) -filetype=obj -O3 $(@:.o=.ll)


.PHONY: clean
clean:
	rm -f $(shell find -L . -type f -name *.o)
	rm -f $(shell find -L . -type f -name *.ll)
