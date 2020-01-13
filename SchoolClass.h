
#ifndef SCHOOL_CLASS_
#define SCHOOL_CLASS_

#include "Teacher.h"
#include "Student.h"

#define CLASS_MAX_NUM_OF_STUDENTS 30

class SchoolClass
{
public:
	SchoolClass(const char* className, Teacher& homeroomTeacher);
	SchoolClass(const SchoolClass& schoolClass);
	~SchoolClass();
	void addStudent(Student* new_student);
	void removeStudent(Student* student);
	void setClassPres(Student* student);
	void changeHomeRoomTeacher(Teacher& teahcer);
	const char* getClassName() const { return className; };
	Teacher& getHomeroomTeacher() { return homeroomTeacher; };
	const Teacher& getHomeroomTeacher() const { return homeroomTeacher; };
	Student& getClassPres(){return classPresident;}
	const Student& getClassPres()const{return classPresident;};
	Student** getStudentList() { return students; };
	const Student*const* getStudentList() const { return students; };
	void setClassName(const char* className);
	SchoolClass& operator+=(const Student&);
	friend ostream& operator<<(ostream& os, const SchoolClass& schoolClass){
		return os;
	}
private:
	char* className;
	Teacher& homeroomTeacher;
	Student* students[CLASS_MAX_NUM_OF_STUDENTS] = {nullptr};
	Student& classPresident;
};

#endif /* SCHOOL_CLASS_ */
