all: main main_test runTest runMain

main:
	gcc -std=c89 main.c src.c -o main

main_test:
	gcc -std=c89 -o main_test test.c src.c

runTest:
	./main_test 

runMain:
	./main 
