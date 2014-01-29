/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#ifndef _PERSON
#define _PERSON
#include <string>

using std::string;

class Person
{
public:
	//Default constructor. Initalizes empty strings
	Person();
	//Sets the Name of an instance of class Person
	void setName(string name);
	//Sets the DOB of an instance of class Person
	void setDOB(string dob);
	//Returns the Name of an instance of class Person
	string getName() const;
	//Returns the DOB of an instance of class Person
	string getDOB() const;
private:
	string Name;
	string DOB;
};
#endif