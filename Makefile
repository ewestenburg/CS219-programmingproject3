assemblyReader: assemblyReader.o main.o
	g++ -g main.o assemblyReader.o -o assemblyReader

main.o: main.cpp assemblyReader.h 
	g++ -c main.cpp assemblyReader.h

assemblyReader.o: assemblyReader.cpp
	g++ -c assemblyReader.cpp

clean:
	rm *.o
