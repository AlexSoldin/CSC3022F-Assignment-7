CC=g++
CCFLAGS=-std=c++11

main: main.cpp
	$(CC) -c main.cpp -o bin/main.o $(CCFLAGS)
	$(CC) -o main bin/main.o $(CCFLAGS)

run:
	./main

clean:
	rm main
	rm bin/*.o

