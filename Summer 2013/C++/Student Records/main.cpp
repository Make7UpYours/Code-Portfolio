/*William Freeman
  CS201L
  7/30/2013
  Final Exam - Student Records
  Description: Create a program that helps the school administration to
  maintain student records.*/
#include <iostream>
#include <fstream>

#include "student.h"
#include "sortedList.h"

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

enum MenuOptions{ADD_STUDENT = 1, SEARCH_STUDENT, SHOW_LIST, TOPPER, EXIT};

void ReadStudents(SortedList& list);
//Reads "students.txt" and adds Students to list.
int Menu();
//Displays the menu and asks for user's input for an option.
void CallFunc(int choice, SortedList& list);
//Calls the correct function based upon the user's menu selection.
void AddStudent(SortedList& list);
//Obtains input from user for a new student and adds them to the list.
void SearchStudents(SortedList& list);
//Asks user to input the id of the student to search for.
//Attempts to find the requested student.
void DisplayStudents(SortedList& list);
//Displays the Students contained within list.

int main()
{
	SortedList studentList;
	ReadStudents(studentList);

	int menuChoice;
	do
	{
		menuChoice = Menu();
		CallFunc(menuChoice, studentList);
	} while(menuChoice != EXIT);

	return 0;
}

void ReadStudents(SortedList& list)
{
	ifstream inFile;
	inFile.open("students.txt");
	int id;
	double cgpa;
	string name;
	while (inFile >> id >> name >> cgpa)
	{
		Student student(id, name, cgpa);
		list.AddStudent(student);
	}
	inFile.close();
}

int Menu()
{
	int choice;
	do
	{
		cout << ADD_STUDENT << ". Add student\n"
			 << SEARCH_STUDENT << ". Search student\n"
			 << SHOW_LIST << ". Show student list\n"
			 << TOPPER << ". Find the school topper\n"
			 << EXIT << ". Exit\n"
			 << "Enter menu selection : ";
		cin >> choice;
		if (choice < ADD_STUDENT || choice > EXIT)
		{
			cout << "\nMenu selection is invalid try again.\n\n";
		}
	} while (choice < ADD_STUDENT || choice > EXIT);

	return choice;
}

void CallFunc(int choice, SortedList& list)
{
	switch (choice)
	{
	case ADD_STUDENT:
		{
			cout << endl;
			AddStudent(list);
			cout << endl;
			break;
		}
	case SEARCH_STUDENT:
		{
			cout << endl;
			SearchStudents(list);
			cout << endl;
			break;
		}
	case SHOW_LIST:
		{
			cout << endl;
			DisplayStudents(list);
			cout << endl;
			break;
		}
	case TOPPER:
		{
			break;
		}
	case EXIT:
		{
			cout << "\nExiting program...\n";
		}
	}
}

void AddStudent(SortedList& list)
{
	int id;
	double cgpa;
	string name;
	cout << "Enter student's id: ";
	cin >> id;
	cout << "Enter student's name: ";
	cin >> name;
	cout << "Enter students's CGPA: ";
	cin >> cgpa;
	Student newStudent(id, name, cgpa);
	list.AddStudent(newStudent);
}

void SearchStudents(SortedList& list)
{
	int id;
	Student student;
	cout << "Enter the student's id: ";
	cin >> id;
	student = list.SearchById(id);
	
	cout << "Student's information:\n";
	cout << student.GetId() << " " << student.GetName() << " " 
		 << student.GetCgpa() << endl;
}

void DisplayStudents(SortedList& list)
{
	Student* students = new Student[list.GetNumOfStudents()];
	students = list.GetSortedItems();
	cout << "Id\t Name\t\tCGPA\n";
	for (int index = 0; index < list.GetNumOfStudents(); index++)
	{
		cout << students[index].GetId() << "    " << students[index].GetName()
			 << "\t\t" << students[index].GetCgpa() << endl;
	}
}