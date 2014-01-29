/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#include <string>

#include "instructor.h"

using std::string;

//Default constructor, initalizes 0 values
Instructor::Instructor()
{
	Office = "";
	Designation = "";
}

//Sets the value of Office for an instance of Instructor
void Instructor::setOffice(string office)
{
	Office = office;
}

//Sets the value of Designation for an instance of Instructor
void Instructor::setDesignation(string designation)
{
	Designation = designation;
}

//Returns the value of Office
string Instructor::getOffice() const
{
	return Office;
}

//Returns the value of Designation
string Instructor::getDesignation() const
{
	return Designation;
}