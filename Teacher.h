/*
 * Teacher.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef TEACHER_H_
#define TEACHER_H_

#include "Subject.h"
#include "Student.h"

class Student;
class Subject;

class Teacher : Person{
public:
    Teacher(Address& address, int id, const char* phoneNum, const char* DOB,
        const char* fName, const char* lName, const char* email, Subject& subject);
    Teacher(Person& person, Subject& subject);
    void changeMarks(Student& student, int mark);
    const Subject& getSubject() const { return subject;};
    Subject& getSubject() { return subject;};
    void setSubject(Subject& subject);
protected:
    Subject& subject;
};


#endif /* TEACHER_H_ */
