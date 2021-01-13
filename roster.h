#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"
#include <array>

class Roster {
public:
	Roster();

	virtual ~Roster();

	void printAll();

	void add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, Degree);

	void remove(string studentID);

	void printByDegree(string degree);

	void printnumDays(string);

	void printBadEmails();

	int addIndex = 0;

private:

	// Declaring array pointers
	Student* classRosterArray[5];
};

#endif 