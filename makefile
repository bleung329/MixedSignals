all: signal.c
	gcc -o "run" signal.c
run: all
	./run
