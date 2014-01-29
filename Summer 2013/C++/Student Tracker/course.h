/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#ifndef _COURSE
#define _COURSE
#include <string>

#include "instructor.h"
#include "student.h"

using std::string;

const int MAX_STUDENTS = 20;

class Course
{
public:
	//Default constructor, initalizes 0 values
	Course();
	//Sets the value of Id for an instance of Course
	void setId(string id);
	//Sets the value of Name for an instance of Course
	void setName(string name);
	//Sets the value of instructor for an instance of Course
	void setInstructor(Instructor teacher);
	//Populates the studentList for an instance of Course
	void setStudentList(Student student[], int arrLen);
	//Returns the value of Id
	string getId() const;
	//Returns the value of Name
	string getName() const;
	//Returns the value of instructor
	Instructor getInstructor() const;
	//Returns the values of studentList
	Student getStudentList() const;
private:
	Student studentList[MAX_STUDENTS];
	Instructor instructor;
	string Id;
	string Name;
};
#endif