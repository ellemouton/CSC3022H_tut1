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
		std::vector<std::string> newStudent = MTNELL004::splitString(str, ',');
		MTNELL004::addNewRecord(newStudent[0],newStudent[1], newStudent[2], newStudent[3]);
	}
}

void MTNELL004::saveDB(void)
{
	std::cout << "Saving DB\n";

	//open and truncate

	std::ofstream ofs;
	ofs.open("databaseEntries.txt", std::ofstream::out | std::ofstream::trunc);
	


	for(int i=0; i < studentDB.size(); i++){
		//get next student record entry
		MTNELL004::StudentRecord sr = studentDB[i];

		//variabled for output string
		std::ostringstream output;
		std::string outputString;

		if(i>0){ofs << "\n";}

		//construct output string
		output << sr.name << ","<<sr.surname<<","<<sr.studentNumber<<","<<sr.classRecord;
		outputString = output.str();
		ofs << outputString;
	}

	ofs.close();
}

void MTNELL004::displayStudentData(void)
{
	std::cout << "Displaying data\n";

	//get studentnumber
	std::string stuNum;
	std::cout << "Enter Student Number: ";
	std::cin >> stuNum;

	//iterate through DB to find corresponding entry

	int index = -1;

	for(int i=0; i< studentDB.size(); i++){
		if(stuNum.compare(studentDB[i].studentNumber)==0){
			index = i;	
		}
	}

	//print out info (or say that it doesnt exist)
	if(index==-1){
		std::cout << "No such student exists.\n";
	}
	else{
		MTNELL004::StudentRecord sr = studentDB[index];
		std::cout << "Name: "<<sr.name<<"\nSurname: "<<sr.surname<<"\nStudent Number: "<<sr.studentNumber<<"\nClass Record: "<<sr.classRecord<<"\n";
	}

}

void MTNELL004::gradeStudent(void)
{
	std::cout << "Showing student grade\n";

	//get studentnumber
	std::string stuNum;
	std::cout << "Enter Student Number: ";
	std::cin >> stuNum;

	//iterate through DB to find corresponding entry

	int index = -1;

	for(int i=0; i< studentDB.size(); i++){
		if(stuNum.compare(studentDB[i].studentNumber)==0){
			index = i;	
		}
	}

	//get grades (or say that entry doesnt exist)
	if(index==-1){
		std::cout << "No such student exists.\n";
	}
	else{
		//split the string into a vector of individual grades
		std::string grades = studentDB[index].classRecord;
		std::vector<std::string> gradesSplit = MTNELL004::splitString(grades, ' ');

		double total = 0;

		//loop through the grades, convert them to doubles and add then to the total
		for(int i=0; i<gradesSplit.size(); i++){
			double grade = std::stod(gradesSplit[i]);
			total += grade;
		}

		double average = total/gradesSplit.size();
		std::cout << "The average grade for this student is: "<<average << "\n";

	}
}

std::vector<std::string> MTNELL004::splitString(std::string str, char delim)
{
	std::stringstream ss(str);
	std::string token;
	std::vector<std::string> cont;

    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
    return cont;
}

