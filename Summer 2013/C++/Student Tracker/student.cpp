/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#include <string>

#include "student.h"

using std::string;

//Default constructor, sets 0 values
Student::Student()
{
	Id = "";
	CGPA = "";
}

//Sets the value of Id for an instance of Student
void Student::setId(string id)
{
	Id = id;
}

//Sets the value of CGPA for an instance of Student
void Student::setCGPA(string gpa)
{
	CGPA = gpa;
}

//Returns the value of Id for an instnace of Student
string Student::getId() const
{
	return Id;
}

//Returns the value of CGPA for an instance of Student
string Student::getCGPA() const
{
	return CGPA;
}