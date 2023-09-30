#include "ListContainer.h"

//Default Constructor:
ListContainer::ListContainer() {}

//Mutator
void ListContainer::set_Clear() {
	Student_List.clear();
}

void ListContainer::set_Resize(const int& size) {

	if (size < Student_List.size()) {
		for (size_t i = Student_List.size(); i > size; --i)
			Student_List.pop_back();
	}
	else if (size > Student_List.size()) {
		for (size_t i = Student_List.size(); i < size; ++i)
			Student_List.push_back(StudentInfo());
	}
	else
		throw invalid_argument("ERROR: could not be resized");

}

void ListContainer::set_List(const StudentInfo& info, const bool& choice) {
	switch (choice) {
	case true: Student_List.push_front(info); break;
	case false: Student_List.push_back(info); break;
	}
}

void ListContainer::set_Pop_Front() {
	Student_List.pop_front();
}

void ListContainer::set_Pop_Back() {
	Student_List.pop_back();
}

//Accessor
size_t ListContainer::get_Size() const {
	return Student_List.size();
}

bool ListContainer::get_Empty() const {
	return Student_List.empty();
}

string ListContainer::get_Front() const {
	ostringstream ostream;
	ostream << Student_List.front();
	return ostream.str();
}

string ListContainer::get_Back() const {
	ostringstream ostream;
	ostream << Student_List.back();
	return ostream.str();
}

list<StudentInfo>::const_iterator ListContainer::get_First_Iter() const {
	return Student_List.begin();
}

ostream& operator<<(ostream& out, const ListContainer& obj) {
	for (list<StudentInfo>::const_iterator iter = obj.Student_List.begin(); iter != obj.Student_List.end(); ++iter)
		out << "\n\t" << *iter;

	return out;
}
