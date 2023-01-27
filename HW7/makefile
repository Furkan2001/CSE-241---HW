all: clear compile run clean

clear:
	@clear

compile:
	@javac Main.java
	@javac Main2.java
	@javac Tetris.java
	@javac Tetromino.java

run:
	@echo "\n\n---------------------------------\n"
	@echo "Running driver1.."
	@echo "\n---------------------------------\n\n"
	@java Main
	@echo "\n\n---------------------------------\n"
	@echo "Running driver2.."
	@echo "\n---------------------------------\n\n"
	@java Main2

clean:
	@rm -f *.class
	
