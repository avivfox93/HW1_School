/*
 * Subject.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "Teacher.h"

using namespace std;

class Teacher;

class Subject{
public:
    Subject(const char* name, Teacher& supervisor);
    ~Subject();
    Teacher& getSuper() { return supervisor; };
    const Teacher& getSuper() const { return supervisor; };
    const char* getSubjectName() const { return name; };
    void setName(const char* name);
    void setSuper(Teacher& teacher);
    friend ostream& operator<<(ostream& os, const Subject& subject);
    friend ostream& operator<<(ostream& os, const Subject& subject){
		return os;
	}
private:
    char* name;
    Teacher& supervisor;
};


#endif /* SUBJECT_H_ */
