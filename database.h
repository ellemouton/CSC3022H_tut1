/**
*database.h file:
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>

namespace MTNELL004 {
//void add_student(std::string name, std::string surname, std::string student_numner, std::string class_record);

	//method definitions
	void addStudent(void);
	void readDB(void);
	void saveDB(void);
	void displayStudentData(void);
	void gradeStudent(void);
	void clear(void);

	//structure definitions
	struct StudentRecord{
		std::string name;
		std::string surname;
		std::string studentNumber;
		std::string classRecord;
	};
}

#endif