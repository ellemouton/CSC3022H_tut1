

compile:
	g++ -c driver.cpp -o driver.o -std=c++11
	g++ driver.o -o driver -std=c++11

clean:
	rm *.o