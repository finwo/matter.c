CC=clang --target=wasm32-unknown-unknown-wasm
LLE=$(CC) -emit-llvm
LLC=llc -march=wasm32
AR=llvm-ar
