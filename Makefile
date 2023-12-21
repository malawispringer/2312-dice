#
# A simple makefile for compiling a c++ project
#
.DEFAULT_GOAL := main.cpp

all: clean test

main.cpp: 
    gcc -o ./target/main.out ./src/main/main.cpp

run: main.cpp
    ./target/main.out 10

test: main.cpp
    ./target/main.out 10000

clean: 
    rm -rf ./target/*.out