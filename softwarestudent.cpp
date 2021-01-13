#include "SoftwareStudent.h"
#include <iostream>

SoftwareStudent::SoftwareStudent() {}

SoftwareStudent::SoftwareStudent(string studID, string fiName, string laName, string emAddr, int a, int* nmDays, Degree deg) : Student(studID, fiName, laName, emAddr, a, nmDays) {
	degree = deg;
}

Degree SoftwareStudent::getDegree() {
	return degree;
}

void SoftwareStudent::print() {
	cout << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
		<< "\t" << "daysInCourse: {"; cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}";
	cout << " Degree Program: Software" << '\n';
}