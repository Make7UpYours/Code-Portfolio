/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#ifndef _STUDENT
#define _STUDENT
#include <string>

#include "person.h"

using std::string;

class Student : public Person
{
public:
	//Default constructor, sets 0 values
	Student();
	//Sets the value of Id for an instance of Student
	void setId(string id);
	//Sets the value of CGPA for an instance of Student
	void setCGPA(string gpa);
	//Returns the value of Id for an instnace of Student
	string getId() const;
	//Returns the value of CGPA for an instance of Student
	string getCGPA() const;
private:
	string Id;
	string CGPA;
};
#endif