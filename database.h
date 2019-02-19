/**
*database.h file:
*/

#ifndef DATABASE_H
#define DATABASE_H


namespace STUDENT_NO {
//void add_student(std::string name, std::string surname, std::string student_numner, std::string class_record);

	void add_Student(void);
	void read_DB(void);
	void save_DB(void);
	void display_student_data(void);
	void grade_student(void);

}

void clear(void);

#endif