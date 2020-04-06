es1.exe: main.o Hex.o
	g++ main.o Hex.o -o es1

Hex.o: Hex.cpp Hex.h
	g++ -g -c Hex.cpp

main.o: main.cpp Hex.h
	g++ -g -c main.cpp
