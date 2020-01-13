
#ifndef GRADE_H_
#define GRADE_H_

#include "Teacher.h"
#include "SchoolClass.h"

#define GRADE_MAX_NUM_OF_CLASSES	4

class Grade{
public:
	Grade();
	Grade(Teacher& supervisor);
	~Grade();
	void addNewClass(SchoolClass* newClass);
	void setSuper(Teacher& teacher);
	Teacher& getSuper() { return supervisor; };
	const Teacher& getSuper() const { return supervisor; };
	const SchoolClass * const* getClasses() const { return schoolClasses; };
	SchoolClass ** getClasses() { return schoolClasses; };
	void setGradeName(const char* gradeName);
	int getNumberOfClasses() const {return numOfClasses;}
	Grade& operator+=(const SchoolClass& schoolClass);
	friend ostream& operator<<(ostream& os, const Grade& grade){
		return os;
	}
private:
	int numOfClasses = 0;
	Teacher& supervisor;
	SchoolClass* schoolClasses[GRADE_MAX_NUM_OF_CLASSES];
};


#endif /* GRADE_H_ */
