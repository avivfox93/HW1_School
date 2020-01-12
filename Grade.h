
#ifndef GRADE_H_
#define GRADE_H_

#include "Teacher.h"
#include "SchoolClass.h"

#define GRADE_MAX_NUM_OF_CLASSES	4

class Grade{
public:
	Grade(const char* name, Teacher& supervisor);
	~Grade();
	void addNewClass(SchoolClass* new_class);
	void changeSuper(Teacher& teacher);
	const char* getGradeName() const { return grade_name; };
	Teacher& getSuper() { return supervisor; };
	const Teacher& getSuper() const { return supervisor; };
	const SchoolClass* const getClasses() const { return school_classes; };
	void setGradeName(const char* gradeName);
private:
	char* grade_name;
	Teacher& supervisor;
	SchoolClass school_classes[GRADE_MAX_NUM_OF_CLASSES];
};


#endif /* GRADE_H_ */
