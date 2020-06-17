CC=clang --target=wasm32
LLE=$(CC) -emit-llvm
LLC=llc -march=wasm32
AR=llvm-ar
