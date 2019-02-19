# include <iostream>
#include <string>

void clear(void);
void add_Student(void);
void read_DB(void);
void save_DB(void);
void display_student_data(void);
void grade_student(void);


int main(int argc, char * argv[])
{

	std::string user_option;
	clear();
	std::cout << "Welcome to the Student DB interface" <<std::endl;
	for (;;) { // loop forever
		// process key press and call relevant functions
		std::cout << "0: Add student\n1: Read database\n2: Save database\n3: Display student data\n4: Grade Student\n";
		std::cin >> user_option;


		if (user_option == "q" ) break;
		clear();
	}

	return 0;
}

void clear(void) { system("clear"); } // include cstdlib
void add_Student(void){ std::cout << "Adding student";}
void read_DB(void){std::cout << "Reading DB";}
void save_DB(void){std::cout << "Saving DB";}
void display_student_data(void){std::cout << "Displaying data";}
void grade_student(void){std::cout << "Showing student grade";}