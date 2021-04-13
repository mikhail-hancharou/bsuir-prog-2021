all: main main_test runTest

main:
	gcc -std=c89 main.c src.c -o main -lm

main_test:
	gcc -std=c89 -o main_test test.c src.c -lm

runTest:
	./main_test


