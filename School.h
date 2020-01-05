/*
 * School.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef SCHOOL_H_
#define SCHOOL_H_

#include "Grade.h"
#include "Department.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Message.h"

#define NUM_OF_GRADES 6

class School{
public:
	School(const char* name, Person& president);
	School(const School& school);
	~School();
	void addDepartment(Department& department);
	Department& findDepartment(const char* name);
	void setName(const char* name);
	const char* getName()const{return name;};
	Person& getPresident(){return president;};
	Student** getAllStudents();
	Teacher** getAllTeachers();
	Person** getAllPersons();
	void sendMessage(Message& msg);

private:
	char* name;
	Person& president;
	int numOfDepartments = 0;
	Department** departments;
	Grade* grades[NUM_OF_GRADES];
	int numOfMessages = 0;
};



#endif /* SCHOOL_H_ */
