ifeq ($(shell uname),Darwin)
    EXT := dylib
else
    EXT := so
endif

all: target/librust_ffi.$(EXT)

target/librust_ffi.$(EXT): src/lib.rs Cargo.toml
	cargo build
	(cd target && ln -nsf debug/librust_ffi-*$(EXT) librust_ffi.$(EXT))
clean:
	rm -rf target
