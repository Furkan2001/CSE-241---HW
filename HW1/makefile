
all: clean compile run

clean:
	@rm -f *o
	@rm -f a.out

compile: main.cpp tetromino.cpp tetromino.h
	@g++ -std=c++11 main.cpp tetromino.cpp
	
run:
	@./a.out
