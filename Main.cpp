
#include <iostream>
#include "School.h"
#include "Person.h"

#define STR_MAX		100

using namespace std;


void illegalChoiceError(int input){
	cout << input << " Is Illegal Choice!" << endl;
}

Person& findPerson(School& school){
	int id; bool ok = false;Person* person = nullptr;
	while(!ok){
		cout << "Please Enter Person ID: ";
		cin >> id;
		person = school.getPersonByID(id);
		if(person)
			ok = true;
	}
	return *person;
}

Address createAddress(){
	char street[STR_MAX],town[STR_MAX]; int num;
	cout << "Please Enter Town Name: ";
	cin >> town;
	cout << "Please Enter Street Name: ";
	cin >> street;
	cout << "Please Enter House num: ";
	cin >> num;
	return Address(street,town,num);
}
Date createDOB(){
	int day,month,year;
	cout << "Please Enter DOB day: ";
	cin >> day;
	cout << "Please Enter DOB month: ";
	cin >> month;
	cout << "Please Enter DOB year: ";
	cin >> year;
	Date result(day,month,year);
	return result;
}

Person createPerson(){
	char fName[STR_MAX],lName[STR_MAX],phone[STR_MAX],email[STR_MAX]; int id;
	cout << "Please Enter first name: ";
	cin >> fName;
	cout << "Please Enter last name: ";
	cin >> lName;
	cout << "Please Enter phone number: ";
	cin >> phone;
	cout << "Please Enter Email: ";
	cin >> email;
	cout << "Please Enter ID number: ";
	cin >> id;
//	Person p(createAddress(),id,phone,createDate(),fName,lName,email);
	Address address = createAddress();
	Date dob = createDOB();
	Person result(address,id,phone,dob,fName,lName,email);
	return result;
}

Teacher createTeacher(){
	Person p = createPerson();
	Teacher result(p);
	return result;
}

Teacher& findTeacher(School& school){
	int i;
	for(i = 0 ; i < school.getNumOfSubjects() ; i++)
		cout << i+1 << "- " << school.getAllSubjects()[i]->getSuper() << endl;
	int input; bool ok = false;
	while(!ok){
		cout << "Please Choose Teacher: ";
		cin >> input;
		if(input > i || input < 1){
			illegalChoiceError(input);
			continue;
		}
		ok = true;
	}
	return school.getAllSubjects()[input-1]->getSuper();
}

Subject createNewSubject(School& school){
	char name[STR_MAX];
	Teacher& teacher = findTeacher(school);
	Subject result(name,teacher);
	return result;
}

Student createStudent(SchoolClass* schoolClass, School& school){
	Person p = createPerson();
	if(!school.getNumOfSubjects())
		school += createNewSubject(school);
	int i;
	for(i = 0 ; i < school.getNumOfSubjects() ; i++)
		cout << i+1 << "- " << *school.getAllSubjects()[i] << endl;
	int input; bool ok = false;
	while(!ok){
		cout << "Please Choose Subject: ";
		cin >> input;
		if(input > i || input < 1){
			illegalChoiceError(input);
			continue;
		}
		ok = true;
	}
	Subject* subject = school.getAllSubjects()[input-1];
	Student result(p,subject);
	return result;
}

Staff createStaff(){
	Person p = createPerson();
	Staff result(p);
	return result;
}

SchoolClass createNewClass(School& school){
	char name[STR_MAX];
	cout << "Please Choose name: ";
	cin >> name;
	Teacher& teacher = findTeacher(school);
	SchoolClass result(name,teacher);
	return result;
}

SchoolClass& selectClass(School& school, Grade& grade){
	int i,in; bool ok = false;
	if(!grade.getNumberOfClasses())
		createNewClass(school);
	while(!ok){
		for(i = 0 ; i < grade.getNumberOfClasses() ; i++)
			cout << i+1 << "- " << *grade.getClasses()[i] << endl;
		cout << "Please Choose Grade: ";
		cin >> in;
		if(in > grade.getNumberOfClasses() || in < 1){
			illegalChoiceError(in);
			continue;
		}
		ok = true;
	}
	return *grade.getClasses()[in];
}

Message createNewMessage(MessageSender* from){
	char msg[STR_MAX],title[STR_MAX];
	cout << "Please Choose Reciever" << endl;
	Person& reciever = findPerson(*from->getSchool());
	cout << "Please Enter Message: ";
	cin >> msg;
	cout << "Please Enter Title: ";
	cin >> title;
	DateTime date;
	Message result(msg,title,reciever,date);
	return result;
}

void sendNewMessage(Person* user){
	MessageSender* sender = dynamic_cast<MessageSender*>(user);
	if(!sender){
		cout << "The current user is not allowed to send Messages!" << endl;
		return;
	}
	Message message = createNewMessage(sender);
	sender->sendMessage(message);
}

Grade& selectGrade(School& school){
	int i; bool ok = false;
	cout << "Please select grade number: ";
	cin >> i;
	while(!ok){
		cout << "Please select grade number: ";
		cin >> i;
		if(i > NUM_OF_GRADES || i < 1){
			illegalChoiceError(i);
			continue;
		}
		ok = true;
	}
	return school.getGrade(i-1);
}

void printPromtMessage(){
	int i = 1;
	cout << "Please choose one of the following:" << endl;
	cout << i++ << "- Set current User" << endl;
	cout << i++ << "- Select Grade" << endl;
	cout << i++ << "- Select Class" << endl;
	cout << i++ << "- Add new Student" << endl;
	cout << i++ << "- Add new SchoolClass" << endl;
	cout << i++ << "- Add new Teacher" << endl;
	cout << i++ << "- Add new StuffMember" << endl;
	cout << i++ << "- Add new Subject" << endl;
	cout << i++ << "- Send New Message" << endl;
	cout << i++ << "- Set student as Class President" << endl;
	cout << i++ << "- Print School" << endl;
	cout << i++ << "- Print current Grade" << endl;
	cout << i++ << "- Print current Class" << endl;
	cout << i++ << "- Print current User" << endl;
	cout << "99- Quit" << endl;
}


int main() {
	Address address("stam","TLV",15);
	Date date(15,3,1975);
	Person president(address,1,"0508118786",date,"Mar","Menahel","Menahel@school.ac.il");
	School school("afeka",president);
	Teacher teacher(president);
	Subject subject("Madaim",teacher);
	Grade grade0 = school.getGrade(0);

	SchoolClass* classA = grade0.getClasses()[0];

	address.setStreet("Menachem Begin");
	date.setYear(2000);
	Person newPerson(address,1020,"0504992834",date,"Yeled","Ashpatot","Eled123@gmail.com");
	Student newStudent(newPerson,&subject);
	classA->addStudent(&newStudent);

	bool quit = false;
	int input;

	Person* selectedPerson = nullptr;
	Grade* selectedGrade = nullptr;
	SchoolClass* selectedClass = nullptr;

	while(!quit){
		printPromtMessage();
		cin >> input;
		switch(input){
		case 1:
			selectedPerson = &findPerson(school);
			break;
		case 2:
			selectedGrade = &selectGrade(school);
			break;
		case 3:
			if(!selectedGrade)break;
			selectedClass = &selectClass(school,*selectedGrade);
			break;
		case 4:
			*selectedClass += createStudent(selectedClass,school);
			break;
		case 5:
			*selectedGrade += createNewClass(school);
			break;
		case 6:
			school += createTeacher();
			break;
		case 14:
			cout << *selectedPerson << endl;
			break;
		case 99: quit = true; break;
		default: illegalChoiceError(input); break;
		}
	}

	return 0;
}
