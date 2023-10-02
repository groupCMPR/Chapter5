#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "input.h"

using namespace std;

int mainMenu();
void displayVector(vector<Student>&);
void caseOne();
char caseOneMenu();


int main() {

	do {
		system("cls");
		switch (mainMenu()) {
		case 0: return EXIT_SUCCESS;
		case 1: caseOne(); break;

		}
		cout << "\n\n\t";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

int mainMenu() {
	cout << "\n\tCMPR131 Chapter 5: Vector and List Container";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Vector container";
	cout << "\n\t\t2> List container";
	cout << "\n\t\t3> Application using Vector and/or List container";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));

	return inputInteger("\n\t\tOption: ", 0, 3);
}

void caseOne() {
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

			if (!file) {
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
			vector <Student>::reverse_iterator end;
			end = studentVector.rend();

			cout << "\n\tThe reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &end;

			break;
		}
		case 'N': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			vector<Student>::reverse_iterator start;

			cout << "\n\tUsing rbegin() and rend(), the vector contains reversed elments: " << endl;

			for (start = studentVector.rbegin(); start != studentVector.rend(); ++start)
				cout << "\t\t" << addressof(*start) << "(" << *start << ")\n";

			break;
		}
		case 'O': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			vector<Student>::iterator start;
			start = studentVector.begin() + 1;

			studentVector.erase(start);

			cout << "\n\tAn element after the begin iterator " << &start << " has been removed.\n";

			break;
		}
		case 'P': {
			if (studentVector.empty()) {
				cout << "\n\tThe vector is empty.";
				break;
			}
			vector<Student>::iterator start;
			vector<Student>::iterator end;

			start = studentVector.begin();
			end = studentVector.end();

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


		}
		cout << "\n\n\t";
		system("pause");
	} while (true);
}

void displayVector(vector<Student>& studentVector) {
	cout << "\n\tThe vector now has " << studentVector.size() << " elements.";
	cout << endl;
	for (int i = 0; i < studentVector.size(); i++) {
		cout << "\n\t[" << i << "]: " << studentVector[i];
	}
}

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
	cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
	cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
	cout << "\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type";
	cout << "\n\t\tS> Sort - Sorts the vector.";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));

	return inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHIJKLMNOPQRS0"));
}
