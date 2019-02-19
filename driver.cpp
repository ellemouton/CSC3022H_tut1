# include <iostream>
# include <string>
# include <cstdlib>
#include "database.h"

int main(int argc, char * argv[])
{
	//define variables
	std::string user_option;

	//clear terminal and print welcome message
	clear();
	std::cout << "Welcome to the Student DB interface" <<std::endl;
	
	for (;;) { // loop forever

		// print put options for the user
		std::cout << "0: Add student\n1: Read database\n2: Save database\n3: Display student data\n4: Grade Student\nq: Quit\nEnter a number (or q to quit) and press return...\n";
		
		//get user input
		std::cin >> user_option;

		//clear the terminal
		clear();

		//Print out option that user entered and call corresponsing function.
		if (user_option == "q" ) break;
		else if(user_option == "0") STUDENT_NO::add_Student();
		else if(user_option == "1") STUDENT_NO::read_DB();
		else if(user_option == "2") STUDENT_NO::save_DB();
		else if(user_option == "3") STUDENT_NO::display_student_data();
		else if(user_option == "4") STUDENT_NO::grade_student();
		else std::cout << "Invalid Input\n";
	}

	return 0;
}



