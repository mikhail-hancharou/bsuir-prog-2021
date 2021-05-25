all: main main_test runTest

main:
	g++ PawnShop.cpp getData.cpp -o main

main_test:
	g++ -ftest-coverage -fprofile-arcs -O0 -o main_test test.cpp getData.cpp

runTest:
	./main_test
	gcov -abcfu getData.cpp

 
