

CC = g++
CCFLAGS = -std=c++11

#compile:
#	g++ -c driver.cpp -o driver.o -std=c++11
#	g++ driver.o -o driver -std=c++11
driver: driver.o database.o
	$(CC) $(CCFLAGS) driver.o database.o -o driver
	
driver.o: driver.cpp
	$(CC) $(CCFLAGS) driver.cpp -c

database.o: database.cpp database.h
	$(CC) $(CCFLAGS) database.cpp -c



clean:
	rm *.o