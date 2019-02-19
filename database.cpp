/**
*database.cpp file:
*/
# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <sstream>
# include <algorithm>
# include <iterator>
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
	std::cin.ignore();
	std::getline (std::cin, classR, '\n');
	std::cout<<classR << '\n';

	MTNELL004::addNewRecord(name, surname, stuNum, classR);
}

void MTNELL004::addNewRecord(std::string name, std::string surname, std::string stuNum, std::string classR)
{
	//iterate through all student number of entries in the DB to check that this one is not a duplicate
	int unique = -1;

	for(int i=0; i< studentDB.size(); i++){
		if(stuNum.compare(studentDB[i].studentNumber)==0){
			unique = i;
		}
	}

	if(unique==-1){

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
	else{

		//update the students information
		studentDB[unique].name = name;
		studentDB[unique].surname = surname;
		studentDB[unique].classRecord = classR;

		MTNELL004::clear();
		std::cout << "This student already exists in the database. Entry succesfully updated.\n";
	}
	
	std::cout << "Number of student in the database is: "<<studentDB.size()<<"\n";
}

void MTNELL004::readDB(void)
{
	std::cout << "Reading DB\n";

	std::ifstream ifs("databaseEntries.txt");
	std::string str;
	int numEntries = 0;

	//iterates through the entries in the text file
	while(std::getline(ifs, str)){
		numEntries++;

		//split the string into parts determined by the ','
		std::vector<std::string> newStudent = MTNELL004::splitString(str);
		MTNELL004::addNewRecord(newStudent[0],newStudent[1], newStudent[2], newStudent[3]);
	}
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

std::vector<std::string> MTNELL004::splitString(std::string str)
{
	std::stringstream ss(str);
	std::string token;
	std::vector<std::string> cont;

    while (std::getline(ss, token, ',')) {
        cont.push_back(token);
    }
    return cont;
}

