Name: Elle Mouton
Student Number: MTNELL004
CSC3022H (CSC3023F) Tutorial 1
________________________________________________________________________________________
CONTENT:
1. How to compile and run the program
2. Description of each of the files used in the program
________________________________________________________________________________________

1. Compiling and running:

To compile the files, navigate into the project folder and type 'make' in the terminal.
To run the program, either type: './driver' or 'make run'

2. Description of each file

___________
driver.cpp:
-----------

The driver program is used to display the various options to the user and to respond to the users option choice. 
The driver.cpp file contains the main function. The main funciton runs a in a continuous event loop so that many menu selections can be processed.

_____________
database.cpp:
-------------

The database.cpp file is where the methods and the vector of records is defined. 
Depending on what options the user chooses, the driver.cpp program will call corresponding methods in the database.cpp file

___________
database.h:
-----------

The database.h header file contains all the method declarations that are defined in the database.cpp file.
All the functions as well as the StudentRecord struct are declared in this header file in the namespace called: MTNELL004.

_________
Makefile:
----------

The Makefile contains various dependency rules required for compilation. It also contains 'run' and 'clean' rules.

___________________
databaseEntries.txt
-------------------

This is a text file used by the program to read/write database records too.