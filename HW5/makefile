all: clean clear driver1 driver2

clean:
	@rm -f *.out *.txt

clear:
	@clear

driver1:
	@g++ -std=c++11 driver1.cpp tetromino.cpp vector.cpp array.cpp adapter.cpp -o main1.out
	@./main1.out

driver2:
	@g++ -std=c++11 driver2.cpp tetromino.cpp vector.cpp array.cpp adapter.cpp -o main2.out
	@./main2.out
