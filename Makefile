# GNU C++ Compiler
CC = g++
ARG = -std=c++11 -O3
STATIC = -static

# Naming stuffs
MAIN = ccipher.cpp
ifeq ($(OS),Windows_NT)
	NAME = ccipher.exe
else
	NAME = ccipher
endif

# Versioning
VER := $(shell git describe --tags)
ifdef VER
BUILD_VER =_CCIPHER_VERSION=\"$(VER)\"
GCC_BUILD = -D$(BUILD_VER)
endif

all: gcc-static

gcc-static:
	$(CC) $(MAIN) -o $(NAME) $(ARG) $(STATIC) $(GCC_BUILD)

gcc:
	$(CC) $(MAIN) -o $(NAME) $(ARG) $(GCC_BUILD)

clean:
	$(RM) $(NAME)
	$(RM) *.obj
