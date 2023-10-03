//Names: Neidy Malaga & Vivian Huynh
//Date: 9/25/2023
//Description: Header file for class Student

#pragma once
#include <string>   //For string
#include <iostream> //For cout
using namespace std;

class Student
{
private:
	string name;       //To contain the student name
	string gradeLevel; //To contain the grade level
	double gpa;        //To contain the student's gpa 0.0...4.0 (*Not fully capitalized to confuse with constant.)

public:
	//CONSTRUCTOR
	Student(); //Default
	Student(const string&, const string&, const double&); //Argument

	//ACCESSORS
	string getName() const;
	string getGradeLevel() const;
	double getGPA() const;

	//MUTATORS
	void setName(const string&);
	void setGradeLevel(const string&);
	void setGPA(const double&);

	//FRIENDS
	friend ostream& operator<<(ostream&, const Student&);
	friend bool operator ==(const Student&, const Student&);
	friend bool operator <(const Student&, const Student&);
};
