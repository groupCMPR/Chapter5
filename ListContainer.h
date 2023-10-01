#pragma once
//Names: Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Header file for class ListContainer

#pragma once
#include "StudentInfo.h" //for composition
#include <iostream> //for overloaded << or cout
#include <string>
#include <sstream> //for displaying data types
#include <list> //linked list
using namespace std;

class ListContainer{
private:
	list <StudentInfo> Student_List; // Composition, is a list of StudentInfo's objects
									 //allows you to change elements (by either passing a StudentInfo constructor or obj)
									 //allows you to display elements: iter->get_ or *iter (which will display overloaded << function of studentInfo)


public:
	//Default CONSTRUCTOR
	ListContainer();


	//MUTATORS
	void set_Clear();
	void set_Resize(const int&);
	void set_List(const StudentInfo&, const bool&);
	void set_Pop_Front();
	void set_Pop_Back();

	//ACCESSORS
	size_t get_Size() const;
	string get_Front() const;
	string get_Back() const;
	bool get_Empty() const;
	list<StudentInfo>::const_iterator  get_First_Iter() const;

	//Friend
	friend ostream& operator<<(ostream&, const ListContainer&);
};
