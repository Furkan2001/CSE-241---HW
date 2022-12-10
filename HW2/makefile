all: clean compile run

clean:
	@rm -f *o
	@rm -f a.out

compile: main2.cpp tetromino.cpp tetris.cpp tetromino.h tetris.h
	@g++ -std=c++11 main2.cpp tetromino.cpp tetris.cpp
	
run:
	@./a.out
