//Names: Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Derived header file for class StudentInfo

#pragma once
#include "ListContainer.h"
#include <string>
#include <iostream>
using namespace std;

class StudentInfo : public ListContainer
{
private:
	string name;    //To contain the student name
	int gradeLevel; //To contain the grade level 0...4
	double gpa;     //To contain the student's gpa

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

	//FRIEND
	friend ostream& operator<<(ostream&, const StudentInfo&);
};
