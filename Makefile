build: 
	gcc main.c -o compiled.out

run: 
	./compiled.out

all: build run
