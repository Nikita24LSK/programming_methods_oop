all: lab_oop

lab_oop: main.o interfaces.o
	g++ main.o interfaces.o -o lab_oop

main.o: main.cpp
	g++ -c main.cpp

interfaces.o: interfaces.cpp
	g++ -c interfaces.cpp

clean:
	rm -rf *.o
