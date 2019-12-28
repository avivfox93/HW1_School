/*
 * Message.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "Person.h"
#include "Date.h"

class Message{
public:
	Message();
	Message(const Message& msg);
	Message(const char* title, const char* body, Person& sender,Person& receiver, const DateTime& date);
	const char* getTitle()const{return title;}
	const Person& getSender()const{return sender;}
	const Person& getReceiver()const{return receiver;}
	Person& getSender(){return sender;}
	Person& getReceiver(){return receiver;}
	const DateTime& getDate()const{return date;}
	DateTime& getDate(){return date;}
	void setTitle(const char* newTitle);
	void setSender(Person& newSender);
	void setReceiver(Person& newReceiver);
	void setDate(DateTime& date);
private:
	char* title;
	char* body;
	Person& sender;
	Person& receiver;
	DateTime date;
};


#endif /* MESSAGE_H_ */