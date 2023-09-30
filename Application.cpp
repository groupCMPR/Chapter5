#include "Application.h"
//Default constructor
Application::Application() {}

//---------------------------------------------------------------------------
//                                MUTATORS
//---------------------------------------------------------------------------
//Precondition: integer new_Value
//PostconditionL pushes in typedef value into back of list
void Application::set_List(const value_type& new_Val) {
	user_val_list.push_back(new_Val);
}

//Precondition: integer user_Val
//Postcondition: either returns if element is not in list, or erases it
void Application::delete_List(const value_type& user_Val) {
	list<value_type>::iterator find_element = find(user_val_list.begin(), user_val_list.end(), user_Val);

	if (find_element == user_val_list.end()) {
		throw invalid_argument("list does not contain");
	}

	user_val_list.erase(find_element);
}

//---------------------------------------------------------------------------
//                                ACCESOR
//---------------------------------------------------------------------------
//Precondition: None
//Postcondtion: returns true if list is empty, else false
bool Application::get_Empty() const {
	return (user_val_list.empty());
}

//Precondition: class must be filled in
//Postcondition: returns string showing frequencies of each number
string Application::get_Freq() const {
	ostringstream ostream;
	map<value_type, int> Sorted_Map;
	ostream << "\n\tcontainer:";

	for (auto begin = user_val_list.begin(); begin != user_val_list.end(); ++begin) {
		++Sorted_Map[(*begin)];
	}

	for (auto begin = Sorted_Map.begin(); begin != Sorted_Map.end(); ++begin) {
		ostream <<"\n\t" << begin->first << ": " << begin->second;
	}

	return ostream.str();
}

//Precondition: ostream, and class object, list must not be empty
//Postcondtion: returns an ostream for display
ostream& operator <<(ostream& out, const Application& obj) {
	out << "\n\tcontainer: ";

	for (auto begin = obj.user_val_list.begin(); begin != obj.user_val_list.end(); ++begin){
		out << (*begin) << " ";
	}

	return out;
}
