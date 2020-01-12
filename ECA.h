

#ifndef ECA_H_
#define ECA_H_

#include "Staff.h"
#include "Student.h"
class ECA {
public:
    ECA(const char* name, Staff& supervisor);
    ECA(const ECA& eca);
    ~ECA();
    void addStudent(Student* new_student);
    void removeStudent(Student& student);
    void setSuper(Staff& staff);
    void setECAName(const char* name);
    const char* getECAName() const { return eca_name; };
    Staff& getSupervisor() { return supervisor; };
    const Staff& getSupervisor() const { return supervisor; };
    Student** getStudents() { return students; };
    const Student*const* getStudents() const { return students; };
private:
    char* eca_name;
    Staff& supervisor;
    Student** students;
};


#endif /* ECA_H_ */
