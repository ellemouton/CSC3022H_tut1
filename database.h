/**
*database.h file:
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>

namespace MTNELL004 {
//void add_student(std::string name, std::string surname, std::string student_numner, std::string class_record);

	//structure definitions
	struct StudentRecord{
		std::string name;
		std::string surname;
		std::string studentNumber;
		std::string classRecord;
	};


	//method definitions
	void addStudent(void);
	void addNewRecord(std::string name, std::string surname, std::string stuNum, std::string classR);
	void readDB(void);
	void saveDB(void);
	void displayStudentData(void);
	void gradeStudent(void);
	void clear(void);
	std::vector<std::string> splitString(std::string str, char delim);
}

#endif