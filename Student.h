/*
 * Student.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"
#include "Grade.h"
#include "Subject.h"
#define NUM_OF_SPECIAL_CLASSES		2
#define MIN_NUM_OF_SPECIAL_CLASSES	1

class Student : Person{
public:
    Student(Person& person, Subject* specialClass);
    const Subject*const* getSpecialClasses() const { return special_classes; };
    void addSpecialClass(Subject* classes);
    void changeSpecialClass(Subject* newClass, int index);
protected:
    int chosenClasses = MIN_NUM_OF_SPECIAL_CLASSES;
    Subject* special_classes[NUM_OF_SPECIAL_CLASSES] = {nullptr};
};


#endif /* STUDENT_H_ */
