CC=g++
CCFLAGS=-std=c++11

main: main.cpp Perceptron.cpp
	$(CC) -c main.cpp -o bin/main.o $(CCFLAGS)
	$(CC) -c Perceptron.cpp -o ./bin/perceptron.o $(CCFLAGS)
	$(CC) -o main bin/main.o bin/perceptron.o $(CCFLAGS)

run:
	./main

clean:
	rm main
	rm bin/*.o

