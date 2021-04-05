all: main_test runTest

main:
	gcc main.c src.c -o main -lm

main_test:
	gcc -o main_test src.c test.c -lm

runTest:
	./main_test

