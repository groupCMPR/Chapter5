//Names: Neidy Malaga & Vivian Huynh
//Date: 9/25/2023
//Description: Derived header file for class StudentInfo

#pragma once
#include <string>   //For string
#include <iostream> //For cout
using namespace std;

class StudentInfo
{
private:
	string name;       //To contain the student name
	string gradeLevel; //To contain the grade level
	double gpa;        //To contain the student's gpa 0.0...4.0

public:
	//CONSTRUCTOR
	StudentInfo(); //Default
	StudentInfo(const string&, const string&, const double&); //Argument

	//ACCESSORS
	string getName() const;
	string getGradeLevel() const;
	double getGPA() const;

	//MUTATORS
	void setName(const string&);
	void setGradeLevel(const string&);
	void setGPA(const double&);

	//FRIEND
	friend ostream& operator<<(ostream&, const StudentInfo&);
	friend bool operator ==(const StudentInfo&, const StudentInfo&);
	friend bool operator <(const StudentInfo&, const StudentInfo&);
};
