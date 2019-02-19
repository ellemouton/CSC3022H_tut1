# include <iostream>
# include <string>

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
		// print put options for the user
		std::cout << "0: Add student\n1: Read database\n2: Save database\n3: Display student data\n4: Grade Student\n";
		std::cin >> user_option;

		clear();

		if (user_option == "q" ) break;
		else if(user_option == "0") add_Student();
		else if(user_option == "1") read_DB();
		else if(user_option == "2") save_DB();
		else if(user_option == "3") display_student_data();
		else if(user_option == "4") grade_student();
		else std::cout << "Invalid Input\n";
	}

	return 0;
}

void clear(void) { system("clear"); } // include cstdlib
void add_Student(void){ std::cout << "Adding student\n";}
void read_DB(void){std::cout << "Reading DB\n";}
void save_DB(void){std::cout << "Saving DB\n";}
void display_student_data(void){std::cout << "Displaying data\n";}
void grade_student(void){std::cout << "Showing student grade\n";}