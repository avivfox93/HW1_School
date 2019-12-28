/*
 * Person.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Address.h"
//#include "Message.h"
#include "Date.h"

#define PHON_NUM_LENGTH		10

class Person{
public:
	Person();
	Person(Person& p);
	Person(Address& address, int id, const char* phoneNum, const char* DOB,
			const char* fName, const char* lName, const char* email);
	virtual ~Person();
	const Address& getAddress()const{return address;}
	Address& getAddress(){return address;}
	int getId()const{return id;}
	const char* getPhoneNum()const{return phoneNum;}
	const Date& getDOB()const{return DOB;}
	Date& getDOB(){return DOB;}
	const char* getFName()const{return fName;};
	const char* getLName()const{return lName;};
	const char* getEmail()const{return email;};
	void setId(int id);
	void setAddress(const Address& newAddress);
	void setPhoneNum(const char* newNum);
	void setDOB(const char* newDOB);
	void setFName(const char* newName);
	void setLName(const char* newName);
	void setEmail(const char* newEmail);
	void readMessages()const;
private:
	Address address;
	int id;
	char phoneNum[PHON_NUM_LENGTH];
	Date DOB;
	char* fName;
	char* lName;
	char* email;
};


#endif /* PERSON_H_ */
