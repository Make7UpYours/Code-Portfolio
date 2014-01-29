/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#include <string>

#include "person.h"

using std::string;

//Default constructor. Initalizes empty strings
Person::Person()
{
	Name = "";
	DOB = "";
}

//Sets the Name of an instance of class Person
void Person::setName(string name)
{
	Name = name;
}

//Sets the DOB of an instance of class Person
void Person::setDOB(string dob)
{
	DOB = dob;
}

//Returns the Name of an instance of class Person
string Person::getName() const
{
	return Name;
}

//Returns the DOB of an instance of class Person
string Person::getDOB() const
{
	return DOB;
}