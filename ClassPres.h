
#ifndef STUDENT_CLASS_PRES_H_
#define STUDENT_CLASS_PRES_H_

#include "Student.h"
#include "MessageSender.h"

class ClassPres: public Student , public MessageSender{
public:
	ClassPres(Student& student);
};


#endif /* STUDENT_CLASS_PRES_H_ */
