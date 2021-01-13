#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "Student.h"

class SecurityStudent : public Student {
public:
	SecurityStudent();

	SecurityStudent(string, string, string, string, int, int*, Degree);

	Degree getDegree() override;

	void print() override;
private:
	Degree degree;
};


#endif
