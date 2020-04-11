VPATH = ../../libs

es2.exe: main.o Hex.o Buffer.o
	g++ main.o Hex.o Buffer.o -o es2

main.o: main.cpp Hex.h Buffer.h
	g++ -c -g -Wall main.cpp

Buffer.o: Buffer.cpp Buffer.h Hex.h
	g++ -c -g -Wall ../../libs/Buffer.cpp -o ./Buffer.o

Hex.o: Hex.cpp Hex.h 
	g++ -c -g -Wall ../../libs/Hex.cpp -o ./Hex.o

.PHONY: clean
clean:
	rm -rf *.o main