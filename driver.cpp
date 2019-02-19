# include <iostream>
# include <string>
# include "database.h"

int main(int argc, char * argv[])
{
	//define variables
	std::string userInput;

	//clear terminal and print welcome message
	MTNELL004::clear();
	std::cout << "Welcome to the Student DB interface" <<std::endl;
	
	for (;;) { // loop forever

		// print put options for the user
		std::cout << "0: Add student\n1: Read database\n2: Save database\n3: Display student data\n4: Grade Student\nq: Quit\nEnter a number (or q to quit) and press return...\n";
		
		//get user input
		std::cin >> userInput;

		//clear the terminal
		MTNELL004::clear();

		//Print out option that user entered and call corresponsing function.
		if (userInput == "q" ) break;
		else if(userInput == "0") MTNELL004::addStudent();
		else if(userInput == "1") MTNELL004::readDB();
		else if(userInput == "2") MTNELL004::saveDB();
		else if(userInput == "3") MTNELL004::displayStudentData();
		else if(userInput == "4") MTNELL004::gradeStudent();
		else std::cout << "Invalid Input\n";
	}

	return 0;
}



