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
	void addSubject(Subject* subject);
	Department& findDepartment(const char* name);
	void setName(const char* name);
	const char* getName()const{return name;};
	Person* getPersonByID(int id);
	Person& getPresident(){return president;};
	Subject** getAllSubjects(){return subjects;}
	Staff** getAllStaff(){return stuffMembers;}
	Person** getAllPersons();
	int getNumOfSubjects() const {return numOfSubjects;}
	int getNumOfStaff() const {return numOfStaff;}
	Grade& getGrade(int grade){return grades[grade];};
	const Grade& getGrade(int grade)const{return grades[grade];};
	void sendMessage(Message& msg);
	School& operator+=(const Department& department);
	School& operator+=(const Subject& department);
	School& operator+=(const Staff& department);
	School& operator+=(const Teacher& teacher);
	friend ostream& operator<<(ostream& os, const School& school){
		return os;
	}

private:
	char* name;
	Person& president;
	int numOfDepartments = 0;
	int numOfStudents,numOfTeachers,numOfStaff,numOfSubjects;
	Department** departments;
	Grade grades[NUM_OF_GRADES];
	Subject** subjects;
	Staff** stuffMembers;
	int numOfMessages = 0;
};



#endif /* SCHOOL_H_ */
