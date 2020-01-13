/*
 * Person.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Address.h"
#include "Message.h"
#include "Date.h"
#include "School.h"
#include <iostream>

#define PHON_NUM_LENGTH		10
#define MAX_NUM_OF_MESSAGES 2048

using namespace std;

class School;
class Messages;

class Person{
public:
	Person(const Person& p);
	Person(Address& address, int id, const char* phoneNum, Date& DOB,
			const char* fName, const char* lName, const char* email);
	~Person();
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
	void setSchool(School* school);
	School* getSchool(){return school;}
	School* const getSchool()const{return school;}
	virtual void toOs(ostream& os)const{};
	friend ostream& operator<<(ostream& os, const Person& person){
		return os;
	}
private:
	School* school;
	Address address;
	int id;
	char phoneNum[PHON_NUM_LENGTH];
	Date DOB;
	char* fName;
	char* lName;
	char* email;
	Messages* messages[MAX_NUM_OF_MESSAGES];
};


#endif /* PERSON_H_ */
