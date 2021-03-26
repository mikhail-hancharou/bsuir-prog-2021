all: main main_test runTest

main:
	gcc -std=c89 Lab1_C.c coup.c -o main -lm

main_test:
	gcc -std=c89 -o main_test main_test.c coup.c -lm

runTest:
	./main_test 
