//Names: Neidy Malaga & Vivian Huynh
//Date: 9/25/2023
//Description: Header file for class ListContainer

#pragma once
#include "Student.h" //For composition
#include <iostream>      //For overloaded << or cout
#include <string>        //For string
#include <sstream>       //For displaying data types
#include <list>          //For linked list
using namespace std;

class ListContainer {
private:
	list <Student> Student_List; // Composition, is a list of StudentInfo's objects
	//                                  allows you to change elements (by either passing a StudentInfo constructor or obj)
	//                                  allows you to display elements: iter->get_ or *iter (which will display overloaded <<
	//                                  function of studentInfo)

public:
	//CONSTRUCTOR
	ListContainer(); //Default

	//MUTATORS
	void set_Clear();
	void set_Resize(const int&);
	void set_List(const Student&, const bool&);
	void set_Pop_Front();
	void set_Pop_Back();
	void set_Erase(int);
	void set_Erase(int, int);
	void set_Insert(int, const Student&);

	//ACCESSORS
	size_t get_Size() const;
	string get_Front() const;
	string get_Back() const;
	bool get_Empty() const;
	list<Student>::const_iterator get_First_Iter() const;
	list<Student>::const_iterator get_Past_End_Iter() const;
	string get_RBegin() const;
	string get_REnd() const;

	//FRIEND
	friend ostream& operator<<(ostream&, const ListContainer&);
};
