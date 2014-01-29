/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#include <string>

#include "course.h"
#include "instructor.h"
#include "student.h"

using std::string;
//Default constructor, initalizes 0 values
Course::Course()
{
	instructor.setDesignation("");
	instructor.setDOB("");
	instructor.setName("");
	instructor.setOffice("");
	Id = "";
	Name = "";
	for(int i = 0; i < MAX_STUDENTS; i++)
	{
		studentList[i].setCGPA("");
		studentList[i].setDOB("");
		studentList[i].setId("");
		studentList[i].setName("");
	}
}

//Sets the value of Id for an instance of Course
void Course::setId(string id)
{
	Id = id;
}

//Sets the value of Name for an instance of Course
void Course::setName(string name)
{
	Name = name;
}

//Sets the value of instructor for an instance of Course
void Course::setInstructor(Instructor teacher)
{
	instructor = teacher;
}

//Populates the studentList for an instance of Course
void Course::setStudentList(Student student[], int arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		studentList[i] = student[i];
	}
}

//Returns the value of Id
string Course::getId() const
{
	return Id;
}

//Returns the value of Name
string Course::getName() const
{
	return Name;
}

//Returns the value of instructor
Instructor Course::getInstructor() const
{
	return instructor;
}

//Returns the values of studentList
Student Course::getStudentList() const
{
	return studentList[MAX_STUDENTS];
}