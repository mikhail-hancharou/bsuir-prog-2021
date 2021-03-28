all: main main_test runTest

main:
	gcc -std=c89 main.c calculate.c -o main -lm

main_test:
	gcc -std=c89 -o main_test test.c calculate.c -lm

runTest:
	./main_test 

