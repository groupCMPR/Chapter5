//Names: Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Chapter 5 Assignments: Vector and List Container
//Group 1 Vectors: Alexis and Angie
//Group 2 List: Vivian and Neidy
//Group 3 Application: Neidy
//Vivian organized the main.cpp. Each group did their section of the main.cpp as well as their header and cpp file.

#include <iostream> //For cout
#include <vector>   //For vector
#include <fstream>  //For files
#include <sstream>  //For tokenizing 

//HEADER FILES
#include "input.h"         //For input validation
#include "ListContainer.h" //For option 2
#include "Student.h"   //Derived class
#include "Application.h"   //For option 3
using namespace std;

//==================================================================================================================
//				     PROTOTYPES
//==================================================================================================================
int mainMenu();

//Option 1 - Vector Container
void vectorContainer();
void displayVector(vector<Student>&);
char caseOneMenu();

//Option 2 - List Container
void listContainer();
void fill_list(ListContainer&, const bool&);
char caseTwoMenu();

//Option 3 - Application using Vector and/or List container
void vectorAndOrListContainer();
char caseThreeMenu();

//Precondition : N/A
//Posctondition: Calls vectorContainer, listContainer, or vectorandorlistcontainer
int main()
{
	do
	{
		system("cls");
		switch (mainMenu())
		{
		case 0: exit(0);
		case 1: system("cls"); vectorContainer(); break;
		case 2: system("cls"); listContainer(); break;
		case 3: system("cls"); vectorAndOrListContainer(); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}

//Precondition : Calls from main
//Posctondition: Returns integer choice
int mainMenu()
{
	cout << "\n\t CMPR131 Chapter 5: Vector and List Container by Group 5 () 9/25/2023";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Vector container";
	cout << "\n\t\t2> List container";
	cout << "\n\t\t3> Application using Vector and/or List container";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0. Exit";
	cout << "\n\t" << string(100, char(205));

	return inputInteger("\n\t\tOption: ", 0, 3);
}

//==================================================================================================================
// Option 1 - Vector container Section
//================================================================================================================== 
//Precondition : Call from main
//Postcondition: clears, reserves, resizes, pushes back, pops back, shows front, shows back, returns iterator at specififed position
//returns begin iterator, returns end iterator, returns all elements, returns rbegin iterator, returns rend iterator,
//returns all elements in reverse order, removes one element, removes element from one iterator to other iterator,
//inserts new entry, swaps with another vector, sorts the list
void vectorContainer()
{
	vector<Student> studentVector;

	do {
		system("cls");
		switch (caseOneMenu()) {
		case '0': return;
		case 'A':
			studentVector.clear();
			cout << "\n\tThe vector has been cleared.";
			break;
		case 'B': {
			int reserveSpace = inputInteger("\n\tEnter the capacity(1..100): ", 1, 100);
			studentVector.reserve(reserveSpace);
			cout << "\n\tThe vector has been reserved " << reserveSpace << " elements.";
			break;
		}
		case 'C': {
			int newSize = inputInteger("\n\tEnter the new size(1..100): ", 1, 100);
			studentVector.resize(newSize);
			cout << "\n\tThe vector has been resized to " << newSize << " elements.";
			break;
		}

		case 'D': {
			ifstream file;
			file.open("input.dat");

			if (!file.is_open()) {
				cout << "\n\tError opening file 'input.dat'." << endl;
				break;
			}

			while (!file.eof()) {
				string line;
				getline(file, line);

				stringstream fileContent(line); //string stream b/c its easier to tokenize

				string name;
				string gradeLevel;
				double GPA;

				if (getline(fileContent, name, ',') && getline(fileContent, gradeLevel, ',') && (fileContent >> GPA)) {
					Student newStudent;
					newStudent.setName(name);
					newStudent.setGradeLevel(gradeLevel);
					newStudent.setGPA(GPA);
					studentVector.push_back(newStudent);
				}
			}
			file.close();
			displayVector(studentVector);
			break;
		}
		case 'E':
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			cout << "\n\tElement, [" << studentVector.size() - 1 << "]: " << studentVector.back() << ", has been removed from the vector.";
			studentVector.pop_back();
			cout << endl;

			displayVector(studentVector);

			break;

		case 'F':
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}

			cout << "\n\tThe element from the front of the vector: [0] " << studentVector.front();
			break;

		case 'G':
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}

			cout << "\n\tThe element from the back of the vector: [" << studentVector.size() - 1 << "] " << studentVector.back();
			break;

		case 'H': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}

			int limit = studentVector.size() - 1;

			int number = inputInteger("\n\tEnter the index(0.." + to_string(limit) + "): ", 0, limit);

			cout << "\n\tvector.at(" << number << "): " << studentVector.at(number);
			cout << "\n\tvector[" << number << "]: " << studentVector[number];

			break;
		}

		case 'I': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			auto it = studentVector.begin();

			cout << "\n\tThe iterator referring the first element: ";
			cout << &it;
			cout << "(" << *it << ")";

			break;
		}

		case 'J': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			auto it = studentVector.end();

			cout << "\n\tThe iterator referring to the past-the-end element: ";
			cout << &it;

			break;
		}
		case 'K': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			vector <Student>::iterator start;
			cout << "\n\t\tUsing begin() and end(), the vector contains:\n";
			for (start = studentVector.begin(); start != studentVector.end(); ++start)
				cout << "\t\t" << addressof(*start) << "(" << *start << ")\n";

			break;
		}
		case 'L': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			auto it = studentVector.rbegin();
			cout << "\n\t\tThe reverse iterator pointing to the last element:" << &it << " " << "(" << *it << ")";
			break;
		}
		case 'M': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			vector <Student>::reverse_iterator end = studentVector.rend();

			cout << "\n\tThe reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &end;

			break;
		}
		case 'N': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}

			cout << "\n\tUsing rbegin() and rend(), the vector contains reversed elments: " << endl;

			for (vector<Student>::reverse_iterator start = studentVector.rbegin(); start != studentVector.rend(); ++start)
				cout << "\t\t" << addressof(*start) << "(" << *start << ")\n";

			break;
		}
		case 'O': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			vector<Student>::iterator start = studentVector.begin() + 1;

			studentVector.erase(start);

			cout << "\n\tAn element after the begin iterator " << &start << " has been removed.\n";

			break;
		}
		case 'P': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			vector<Student>::iterator start = studentVector.begin();
			vector<Student>::iterator end = studentVector.end();

			studentVector.erase(start, end);

			cout << "\n\t\tAll elements starting at begin iterator " << &start << " and going up to end iterator " << &end << " has been removed.\n";

			break;
		}
		case 'Q': {

			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}

			Student newStudent;

			string names[] = { "Freshman", "Sophmore", "Junior", "Senior" };


			newStudent.setName(inputString("\n\t\tEnter a new student name: ", true));

			int number = inputInteger("\n\t\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);

			newStudent.setGradeLevel(names[number - 1]);
			newStudent.setGPA(inputDouble("\n\t\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));

			auto it = studentVector.begin() + 1;

			studentVector.insert(it, newStudent);

			cout << "\n\t\tThe new element has been inserted after the begin iterator.";

			break;
		}
		case 'R': {
			vector<Student> studentVector2;
			cout << "\n\t\tvector (v2) is initially empty.\n";
			studentVector2.swap(studentVector);

			cout << "\n\t\tvector (v1) is empty after swapped with vector (v2).\n";
			cout << "\n\t\tvector (v2) after swapped with vector (v1).\n";

			for (int i = 0; i < studentVector2.size(); i++)
				cout << "\t\t[" << i << "]" << studentVector2[i] << "\n";

			break;
		}
		case 'S': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			cout << "\n\tVector has been sorted";

			cout << endl;
			sort(studentVector.begin(), studentVector.end());

			for (int i = 0; i < studentVector.size(); i++)
				cout << "\t\t[" << i << "]" << studentVector[i] << "\n";

			break;
		}
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);
}

//Precondition : Passing vector 
//Postcondition: Displays size and contents of vectors
void displayVector(vector<Student>& studentVector) {
	cout << "\n\tThe vector now has " << studentVector.size() << " elements.";
	cout << endl;
	for (int i = 0; i < studentVector.size(); i++) {
		cout << "\n\t[" << i << "]: " << studentVector[i];
	}
}

//Precondition : Called from vectorContainer
//Postcondition: Returns choice character
char caseOneMenu() {
	cout << "\n\tVectors are sequence containers representing arrays that can change in size.";
	cout << endl;
	cout << "\n\t1> Vector's member functions";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)";
	cout << "\n\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements";
	cout << "\n\t\tC> resize(n) - Resizes the container so that it contains n elements";
	cout << "\n\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector";
	cout << "\n\t\tE> pop_back() - Removes the last element in the vector";
	cout << "\n\t\tF> front() - Returns a reference to the first element in the vector";
	cout << "\n\t\tG> back() - Returns a reference to the last element in the vector";
	cout << "\n\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector";
	cout << "\n\t\tI> begin() - Returns an iterator pointing to the first element in the vector";
	cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector";
	cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the vector";
	cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector";
	cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first";
	cout << "\n\t\t\t    element in the vector";
	cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the vector";
	cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
	cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements(using iterators)";
	cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
	cout << "\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type";
	cout << "\n\t\tS> Sort - Sorts the vector.";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));

	return inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHIJKLMNOPQRS0"));
}

//==================================================================================================================
// Option 2 - List container Section
//================================================================================================================== 
//Precondition : Call from main
//Postcondition: clears, resizes, pushes front, pops front, shows first element, pushes back, shows last element
// returns begin iterator, returns end iterator, returns all elements, returns rbegin iterator, returns rend iterator,
//returns all elements in reverse order, removes one element, removes element from one iterator to other iterator,
//inserts new entry, swaps with another list, sorts the list
void listContainer()
{
	ListContainer link_list;
	do
	{
		system("cls");
		switch (caseTwoMenu())
		{
		case '0': return;
		case 'A': {
			link_list.set_Clear();
			cout << "\n\tThe list has been cleared.";
		}; break;
		case 'B': link_list.set_Resize(inputInteger("\n\tEnter the new size(1..100):", 1, 100)); break;
		case 'C': fill_list(link_list, true); break;
		case 'D': {
			if (link_list.get_Empty()) {
				cout << "\n\tList is empty.";
				break;
			}
			cout << "\n\tFirst element, (" << link_list.get_Front() << "), has been removed from the list";
			link_list.set_Pop_Front();
			cout << "\n\tThe list now has " << link_list.get_Size() << " elements\n";
			cout << link_list;
		};  break;
		case 'E': {
			if (link_list.get_Empty()) {
				cout << "\n\tList is empty.";
				break;
			}

			cout << "\n\tFirst element from the list is (" << link_list.get_Front() << ").";

		}break;
		case 'F': fill_list(link_list, false); break;
		case 'G': {
			if (link_list.get_Empty()) {
				cout << "\n\tList is empty.";
				break;
			}
			cout << "\n\tLast element, (" << link_list.get_Back() << "), has been removed from the list";
			link_list.set_Pop_Back();
			cout << "\n\tThe list now has " << link_list.get_Size() << " elements\n";
			cout << link_list;
		} break;
		case 'H': {
			if (link_list.get_Empty()) {
				cout << "\n\tList is empty.";
				break;
			}

			cout << "\n\tLast element from the list is (" << link_list.get_Back() << ").";

		} break;
		case 'I': {
			if (link_list.get_Empty()) {
				cout << "\n\tList is empty.";
				break;
			}

			cout << "\n\tThe iterator referring the first element: " << &(*link_list.get_First_Iter()) << " (" << (*link_list.get_First_Iter()) << ").";

		} break;
		case 'J': {
			if (link_list.get_Empty()) {
				cout << "\n\tList is empty.";
				break;
			}

			cout << "\n\tThe iterator referring to the past-the-end element: " << &(*link_list.get_Past_End_Iter()) << " (" << (*link_list.get_Past_End_Iter()) << ").";

		}break;
		case 'K': {
			if (link_list.get_Empty()) {
				cout << "\n\tList is empty.";
				break;
			}

			for (auto it = link_list.get_First_Iter(); it != link_list.get_Past_End_Iter(); it++)
			{
				cout << "\n\t" << &it << " (" << *it << ")";
			}
		}break;
		case 'L': {

		}break;
		case 'M':
		{

		}break;
		case 'N':
		{

		}break;
		case 'O':
		{

		}break;
		case 'P':
		{

		}break;
		case 'Q':
		{

		}break;
		case 'R':
		{

		}break;
		case 'S':
		{

		}break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

//Precondition : Call from listContainer, needs class and bool
//Postcondition: Pushes elements from file to front or back 
void fill_list(ListContainer& link_list, const bool& front_or_back) {
	string file_Name = inputString("\n\tInput name of file (input.dat): ", false);
	string line;

	if (file_Name.find(".dat") == string::npos) {
		file_Name += ".dat";
	}

	ifstream input_File(file_Name);

	//error check
	if (!input_File.is_open()) {
		cout << "\n\tERROR: " << file_Name << " cannot be opened";
		return;
	}

	//checks if there is a next character, if not returns eof() 
	if (input_File.peek() == ifstream::traits_type::eof()) {
		cout << "\n\tERROR: " << file_Name << " is empty";
		input_File.close();
		return;
	}

	//gets one line, tokenizes, find classlevel, sets using constructor
	//if true will set as push front, false is push back 
	while (getline(input_File, line)) {
		istringstream stream(line);
		int level = 0;
		string tokenize[3];

		for (int i = 0; i < 3; ++i) {
			getline(stream, tokenize[i], ',');
		}

		link_list.set_List(Student(tokenize[0], tokenize[1], stod(tokenize[2])), front_or_back);
	}

	input_File.close();

	cout << "\n\tThe list now has " << link_list.get_Size() << " elements.";
}

//Precondition : Called from listContainer
//Postcondition: Returns choice character
char caseTwoMenu() {
	cout << "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the";
	cout << "\n\tsequence, and iteration in both directions.\n";

	cout << "\n\t2> List container";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> clear() - Destroys all elements from the list";
	cout << "\n\t\tB> resize(n) - Changes the list so that it contains n elements";
	cout << "\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list";
	cout << "\n\t\tD> pop_front() - Deletes the first element";
	cout << "\n\t\tE> front() - Accesses the first element";
	cout << "\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list";
	cout << "\n\t\tG> pop_back() - Delete the last element";
	cout << "\n\t\tH> back() Accesses the last element";
	cout << "\n\t\tI> begin() - Returns an iterator referring to the first element in the list";
	cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list";
	cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the list";
	cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list";
	cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element";
	cout << "\n\t\t            in the list";
	cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list";
	cout << "\n\t\tO> erase(it) - Removes from the list a single element(using an iterator)";
	cout << "\n\t\tP> erase(start_it,end_it) - Removes from the list a range of elements(using iterators)";
	cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
	cout << "\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type";
	cout << "\n\t\tS> Sort - Sorts the list.";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));

	return inputChar("\n\t\tOption: ", static_cast<string>("0ABCDEFGHIJKLMNOPQRS"));
}

//==================================================================================================================
// Option 3 - Application using Vector and/or List container Section
//================================================================================================================== 
//Precondition : Call from main
//Postcondition: Will add an integer, delete an integer, display all integers, and display all frequencies of integers
void vectorAndOrListContainer()
{
	Application list_Apply;
	do
	{
		system("cls");

		switch (caseThreeMenu())
		{
		case '0': return;
		case 'A': list_Apply.set_List(inputInteger("\n\tAdd an integer: ")); break;
		case 'B': {
			//if value is not in list, error
			int user_Value = inputInteger("\n\t Delete an integer: ");
			try {
				list_Apply.delete_List(user_Value);
			}
			catch (const invalid_argument& error) {
				cout << "\n\t" << error.what() << to_string(user_Value) << ".";
			}
		}break;
		case 'C': {
			if (list_Apply.get_Empty()) {
				cout << "\n\tERROR: Empty List. Please input integer (Option A)";
				break;
			}

			cout << list_Apply;
		}; break;
		case 'D': {
			if (list_Apply.get_Empty()) {
				cout << "\n\tERROR: Empty List. Please input integer (Option A)";
				break;
			}

			cout << list_Apply.get_Freq();
		}; break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

//Precondition : Called from vectorAndOrListContainer
//Postcondition: Returns choice character
char caseThreeMenu() {
	cout << "\n\t3> Application using Vector and/or List container";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> Add an integer";
	cout << "\n\t\tB> Delete an integer";
	cout << "\n\t\tC> Display input integers";
	cout << "\n\t\tD> Display frequencies of integers";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));

	return inputChar("\n\t\tOption: ", static_cast<string>("0ABCD"));
}
