#pragma once
#include "ListContainer.h"
#include <string>
using namespace std;

class StudentInfo : public ListContainer
{

private:
	string name;
	int gradeLevel;
	double gpa;

public:
	//CONSTRUCTOR
	StudentInfo();

	//ACCESSORS
	string getName() const;
	string getGradeLevel() const;
	double getGpa() const;

	//MUTATORS
	void setName(string);
	void setGradeLevel(int);
	void setGpa(double);
};