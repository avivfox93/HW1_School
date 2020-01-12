/*
 * Address.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_


class Address{
public:
	Address();
	Address(const Address& address);
	Address(const char* street, const char* town, int number);
	~Address();
	const char* getStreet()const{return street;}
	const char* getTown()const{return town;}
	int getNumber()const{return number;};
	void setStreet(const char* newName);
	void setTown(const char* newTown);
	void setNumber(int newNumber);
private:
	char* street;
	char* town;
	int number;
};


#endif /* ADDRESS_H_ */
