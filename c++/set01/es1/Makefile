es1.exe: main.o Hex.o Buffer.o
	g++ main.o Hex.o Buffer.o -o es1

Buffer.o: Buffer.cpp Buffer.h
	g++ -g -c Buffer.cpp

Hex.o: Hex.cpp Hex.h
	g++ -g -c Hex.cpp

main.o: main.cpp Hex.h
	g++ -g -c main.cpp
