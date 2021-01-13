#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Student.h"
#include "Degree.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "Roster.h"

using namespace std;



Roster::Roster() {}


//Updating the classRosterArray
void Roster::add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, Degree degree) {
	int nmDaysIn[] = { day0, day1, day2 };
	if (degree == Degree::NETWORK) {
		classRosterArray[addIndex++] = new NetworkStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SECURITY) {
		classRosterArray[addIndex++] = new SecurityStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SOFTWARE) {
		classRosterArray[addIndex++] = new SoftwareStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
}

//printing entire roster
void Roster::printAll() {
	cout << "Displaying roster:" << '\n';
	cout << endl;
	for (int i = 0; i < 5; i++) {
		(*classRosterArray[i]).print();
	}
	cout << '\n';
}

//printing the average days to complete 3 courses
void Roster::printnumDays(string studentID) {
	for (int i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).getStudentID() == studentID) {
			int avg = 0;
			avg = ((*classRosterArray[i]).getNumDays()[0] + (*classRosterArray[i]).getNumDays()[1]
				+ (*classRosterArray[i]).getNumDays()[2]) / 3;
			cout << "The average days it took the student with studentID: " << studentID << " to finish 3 courses: " << avg << '\n';
		}
	}
	cout << '\n';
}

// Printing studnts by degree program
void Roster::printByDegree(string degree) {
	Degree testDeg = Degree::SOFTWARE;
	if (degree == "SECURITY") {
		testDeg = Degree::SECURITY;
		cout << "Displaying students in the Security degree: " << endl;
	}
	if (degree == "NETWORK") {
		testDeg = Degree::NETWORK;
		cout << "Displaying students in the Network degree: " << endl;
	}
	if (degree == "SOFTWARE") {
		testDeg = Degree::SOFTWARE;
		cout << "Displaying students in the Software degree: " << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		if (testDeg == (*classRosterArray[i]).getDegree()) {
			(*classRosterArray[i]).print();
		}
	}
	cout << '\n';
}

// Checking Emails and displayign invalid ones
void Roster::printBadEmails() {
	cout << "Displaying invalid emails:" << '\n';
	cout << endl;
	for (int i = 0; i < 5; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmailAddress();
		for (char& c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << (*classRosterArray[i]).getEmailAddress() << '\n';
		}
	}
	cout << '\n';
}

// Removing student from roster by Student ID
void Roster::remove(string studentID) {
	bool removed = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				classRosterArray[i] = nullptr;
				removed = true;
			}
		}
	}
	if (!removed) {
		cout << "The student with the ID: " << studentID << " was not found." << '\n';
	}
}



int main()
{

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Aaron,George,ageor88@wgu.edu,20,25,30,31,SOFTWARE"
	};

	//Creating Roster Instance
	Roster classRoster;

	// Creating Degree Instance
	Degree myDegree;

	// adding each student to the classRoster
	for (int i = 0; i < 5; i++) {
		stringstream ss(studentData[i]);

		vector<string> result;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			result.push_back(substr);
		}
		if (result[8] == "SECURITY") {
			myDegree = Degree::SECURITY;
		}
		if (result[8] == "SOFTWARE") {
			myDegree = Degree::SOFTWARE;
		}
		if (result[8] == "NETWORK") {
			myDegree = Degree::NETWORK;
		}
		classRoster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]),
			stoi(result[6]), stoi(result[7]), myDegree);
	}



	//printing  Personal Info 
	cout << "Scripting and Programming - Applications C867" << endl;
	cout << "C++" << endl;
	cout << "Student ID# 001384512" << endl;
	cout << "Aaron George" << endl;
	cout << endl;

	// printing all results
	classRoster.printAll();

	classRoster.printBadEmails();

	classRoster.printnumDays("A1");

	classRoster.printByDegree("SOFTWARE");

	classRoster.remove("A3");

	classRoster.remove("A3");
}

//Deconstructor
Roster::~Roster() {}