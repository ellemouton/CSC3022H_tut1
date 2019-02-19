
# Makefile for Student Database program

CC = g++
CCFLAGS = -std=c++11

driver: driver.o database.o
	$(CC) $(CCFLAGS) driver.o database.o -o driver
	
driver.o: driver.cpp
	$(CC) $(CCFLAGS) driver.cpp -c

database.o: database.cpp database.h
	$(CC) $(CCFLAGS) database.cpp -c

run:
	./driver

clean:
	rm *.o