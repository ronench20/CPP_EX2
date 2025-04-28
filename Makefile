#ronen.chereshn@msmail.ariel.ac.il

HEADERS = Matrix.hpp SquareMat.hpp
FLAGS = -g -Wall

main: main.o Matrix.o SquareMat.o
	g++ $(FLAGS) -o main main.o Matrix.o SquareMat.o

Main: main
	./main

test: Test.o Matrix.o SquareMat.o
	g++ $(FLAGS) -o test Test.o Matrix.o SquareMat.o
	./test

Matrix.o: Matrix.cpp $(HEADERS)
	g++ $(FLAGS) -c Matrix.cpp

SquareMat.o: SquareMat.cpp $(HEADERS)
	g++ $(FLAGS) -c SquareMat.cpp

main.o: main.cpp $(HEADERS)
	g++ $(FLAGS) -c main.cpp

test.o: Test.cpp $(HEADERS)
	g++ $(FLAGS) -c Test.cpp

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

valgrind-test: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

clean:
	rm -f *.o main test

.PHONY: Main main test valgrind clean