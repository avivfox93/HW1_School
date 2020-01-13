/*
 * MessageSender.h
 *
 *  Created on: 12 Jan 2020
 *      Author: Aviv
 */

#ifndef MESSAGESENDER_H_
#define MESSAGESENDER_H_

#include "Message.h"

class MessageSender : virtual public Person{
public:
	virtual ~MessageSender();
	virtual void sendMessage(Message& message);
};


#endif /* MESSAGESENDER_H_ */
