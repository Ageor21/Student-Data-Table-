#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include "Degree.h"
using namespace std;

class Student
{

public:

	//constructor
	Student();

	//string
	Student(string, string, string, string, int, int*);

	//getter 
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getStudentID();
	int getAge();
	int* getNumDays();


	//setter
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setStudentID(string studentID);
	void setNumDays(int day0, int day1, int day2);
	void setDegree(string degree);

	virtual void print();
	virtual Degree getDegree();

	//Deconstructor
	~Student();

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[3];
};


#endif 
