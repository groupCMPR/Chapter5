//Names: Neidy Malaga & Vivian Huynh
//Date: 9/25/2023
//Description: cpp file for class ListContainer

#include "ListContainer.h"

//Precondition : N/A
//Postcondition: N/A
ListContainer::ListContainer() {}

//---------------------------------------------------------------------------
//                                MUTATORS
//---------------------------------------------------------------------------
//Precondition : N/A
//Postcondition: Clears list
void ListContainer::set_Clear() {
	Student_List.clear();
}
//Precondition : Receives new size that must be from 1...100
//Postcondition: Adds in elements if size is greater, pops elements if size is smaller
//               or throws in error if anything unexpected occurs
void ListContainer::set_Resize(const int& size) {

	//for loop iterates until it is the same size
	if (size < Student_List.size()) {
		for (size_t i = Student_List.size(); i > size; --i)
			Student_List.pop_back();
	}
	else if (size > Student_List.size()) {
		for (size_t i = Student_List.size(); i < size; ++i)
			Student_List.push_back(Student());
	}
	else
		throw invalid_argument("ERROR: could not be resized");
}
//Precondition : Class student, bool choice 
//Postcondition: Pushes class into list, if true pushes it to front, false pushes it back
void ListContainer::set_List(const Student& info, const bool& choice) {
	switch (choice) {
	case true: Student_List.push_front(info); break;
	case false: Student_List.push_back(info); break;
	}
}
//Precondition : List must not be empty
//Postcondition: Deletes first student class from list
void ListContainer::set_Pop_Front() {
	Student_List.pop_front();
}
//Precondition : List must not be empty
//Postcondition: Deletes last student class from list
void ListContainer::set_Pop_Back() {
	Student_List.pop_back();
}

//---------------------------------------------------------------------------
//                                ACCESSORS
//---------------------------------------------------------------------------
//Precondition : N/A
//Postcondition: Returns size of list
size_t ListContainer::get_Size() const {
	return Student_List.size();
}
//Precondition : N/A
//Postcondition: Returns true if list is empty
bool ListContainer::get_Empty() const {
	return Student_List.empty();
}
//Precondition : List must not be empty
//Postcondition: Returns a string containing information of the 
//overloaded << function of the first StudentInfo class stored in list
string ListContainer::get_Front() const {
	ostringstream ostream;
	ostream << Student_List.front();
	return ostream.str();
}
//Precondition : List must not be empty
//Postcondition: Returns a string containing information of the 
//overloaded << function of the last StudentInfo class stored in list
string ListContainer::get_Back() const {
	ostringstream ostream;
	ostream << Student_List.back();
	return ostream.str();
}
//Precondition : List must not be empty
//Postcondition: Returns a const iterator that cannot be changed in main.cpp
list<Student>::const_iterator ListContainer::get_First_Iter() const {
	return Student_List.begin();
}
//Precondition : List must not be empty
//Postcondition: Returns a const iterator that cannot be changed in main.cpp
list<Student>::const_iterator ListContainer::get_Past_End_Iter() const {
	return Student_List.end();
}
//string ListContainer::get_RBegin() const {
//
//}
//string ListContainer::get_REnd() const {
//
//}

//---------------------------------------------------------------------------
//                                FRIEND
//---------------------------------------------------------------------------
//Precondition : Class object ListContainer
//Postcondition: Returns ostream (will contain overloaded << StudentInfo)
ostream& operator<<(ostream& out, const ListContainer& obj) {
	for (list<Student>::const_iterator iter = obj.Student_List.begin(); iter != obj.Student_List.end(); ++iter)
		out << "\n\t" << *iter;

	return out;
}
