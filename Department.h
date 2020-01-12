
#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include "Staff.h"

class Department {
public:
	Department(const Department& department);
	Department(const char* name, Staff& supervisor);
	~Department();
	const char* getDepName() const { return dep_name; };
	Staff& getSuper() { return supervisor; };
	void setDepName(const char* name);
	void setSuper(Staff& staff);
	void addStaff(Staff& staff);
	void removeStaff(Staff& staff);
private:
	char* dep_name;
	Staff& supervisor;
	Staff** staffMembers;
};


#endif /* DEPARTMENT_H_ */
