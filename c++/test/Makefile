VPATH = ../libs

test: main.o Buffer.o Hex.o
	g++  main.o Buffer.o Hex.o -o test

main.o: test_buffer.cpp Hex.h Buffer.h 	
	g++ -c -Wall -g  test_buffer.cpp -o main.o

Buffer.o: Buffer.cpp Buffer.h Hex.h
	g++ -c -Wall -g  ../libs/Buffer.cpp

Hex.o: Hex.cpp Hex.h
	g++ -c -Wall -g ../libs/Hex.cpp