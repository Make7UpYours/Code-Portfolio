/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#ifndef _INSTRUCTOR
#define _INSTRUCTOR
#include <string>

#include "person.h"

using std::string;

class Instructor : public Person
{
public:
	//Default constructor, initalizes 0 values
	Instructor();
	//Sets the value of Office for an instance of Instructor
	void setOffice(string office);
	//Sets the value of Designation for an instance of Instructor
	void setDesignation(string designation);
	//Returns the value of Office
	string getOffice() const;
	//Returns the value of Designation
	string getDesignation() const;
private:
	string Office;
	string Designation;
};
#endif