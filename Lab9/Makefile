output: test.o MapClass.o
	g++ -std=c++11 test.o MapClass.o -o output

test.o: test.cpp
	g++ -c -std=c++11 test.cpp	

MapClass.o: MapClass.cpp MapClass.h
	g++ -c -std=c++11 MapClass.cpp

clean:
	rm *.o output
