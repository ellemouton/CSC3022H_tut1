/**
*database.cpp file:
*/
# include <iostream>
# include <string>

# include "database.h"


//vector definitions
std::vector<MTNELL004::StudentRecord> studentDB;


void MTNELL004::clear(void) 
{
	system("clear"); 
} 

void MTNELL004::addStudent(void)
{
	std::cout << "Adding student\n";

	//initialize variables to hold user input
	std::string name; 
	std::string surname; 
	std::string stuNum; 
	std::string classR; 
	
	//get info from user.
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Surname: ";
	std::cin >> surname;
	std::cout << "Student Number: ";
	std::cin >> stuNum;
	std::cout << "Class Record: ";
	std::cin >> classR;

	//create new object of type StudentRecord
	StudentRecord newStudent;
	newStudent.name = name;
	newStudent.surname = surname;
	newStudent.studentNumber = stuNum;
	newStudent.classRecord = classR;

	//add the new object to the vector studentDB
	studentDB.push_back(newStudent);
	
	MTNELL004::clear();
	std::cout << "New Student successfully added to the database\n";
}

void MTNELL004::readDB(void)
{
	std::cout << "Reading DB\n";
}

void MTNELL004::saveDB(void)
{
	std::cout << "Saving DB\n";
}

void MTNELL004::displayStudentData(void)
{
	std::cout << "Displaying data\n";
}

void MTNELL004::gradeStudent(void)
{
	std::cout << "Showing student grade\n";
}

