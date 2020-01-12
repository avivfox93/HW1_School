
#ifndef STUDENT_PRES_H_
#define STUDENT_PRES_H_

#include "ClassPres.h"

class StudentPres: public ClassPres, public MessageSender {
public:
	StudentPres(ClassPres& Class_pres);
};


#endif /* STUDENT_PRES_H_ */
