/*
 * Date.h
 *
 *  Created on: 28 Dec 2019
 *      Author: Aviv
 */

#ifndef DATE_H_
#define DATE_H_

#include <ctime>

class Date{
public:
	Date();//Now Date
	Date(int day, int month, int year);
	int getDay()const{return day;}
	int getMonth()const{return month;}
	int getYear()const{return year;}
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void toOs(ostream& os)const{};
	friend ostream& operator<<(ostream& os, const Date& date){
		return os;
	}
private:
	int day;
	int month;
	int year;
};

class DateTime : public Date{
public:
	DateTime();//Now date and time
	DateTime(int day, int month, int year, int hour, int minutes);
	int getHours()const{return hours;}
	int getMinutes()const{return minutes;}
	void setHours(int hours);
	void setMinutes(int minutes);
private:
	int hours;
	int minutes;
};


#endif /* DATE_H_ */
