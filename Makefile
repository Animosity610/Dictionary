output: main.o myfunctions.o
	g++ myfunctions.o main.o -o myDictionary
main.o: main.cpp
	g++ -c main.cpp
myfunctions.o: myfunctions.h myfunctions.cpp
	g++ -c myfunctions.cpp
clean:
	rm *.o myDictionary

