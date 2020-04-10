VPATH = ../../libs

es1.exe: main.o Hex.o Buffer.o
	g++ main.o Hex.o Buffer.o -o es1

main.o: main.cpp Hex.h Buffer.h
	g++ -c main.cpp

Buffer.o: Buffer.cpp Buffer.h Hex.h
	g++ -c ../../libs/Buffer.cpp -o ./Buffer.o

Hex.o: Hex.cpp Hex.h 
	g++ -c ../../libs/Hex.cpp -o ./Hex.o


