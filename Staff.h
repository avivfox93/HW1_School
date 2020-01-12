

#ifndef STAFF_H_
#define STAFF_H_

#include "Person.h"
#include "Department.h"
#include "MessageSender.h"

class Staff:public Person, public MessageSender {
public:
    Staff(const Person& person);
private:
};


#endif /* STAFF_H_ */
