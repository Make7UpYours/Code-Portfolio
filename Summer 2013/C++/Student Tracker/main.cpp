/*William Freeman
  CS 201L
  6/25/2013
  Lab Assignment 4 - Class Inheritance and Composition
  Description: Create 4 classes, Person, Student, Instructor, and Course.
  The Student and Instructor class inherit form the Person class while the
  Course class contains variables of type Student and Instructor, demonstrating
  class composition.*/
#include <iostream>
#include <fstream>
#include <string>

#include "person.h"
#include "student.h"
#include "instructor.h"
#include "course.h"

using namespace std;

const int MAX_NUM_STUDENTS = 20;

void initalizeStudents(Student students[]);
//Iterates through students.txt and fills the students arry with values.

void initalizeInstructor(Instructor& teacher);
//Iterates through instructor.txt and assigns values for the Instructor calss

void initalizeCourse(Student students[], Instructor& instructor, Course& course);
//Iterates through course.txt and assigns values for the Course class

int main()
{
	Student students[MAX_NUM_STUDENTS];
	Instructor instructor;
	Course course;
	initalizeStudents(students);
	initalizeInstructor(instructor);
	initalizeCourse(students, instructor, course);

	system("PAUSE");
	return 0;
}

void initalizeStudents(Student students[])
{
	ifstream inFile;
	string name, dob, id, gpa;
	char fileInput[100];
	int index = 0;
	inFile.open("students.txt");
	//Iterate through file until the end of file
	//Assign values for each student
	while (!inFile.eof())
	{
		inFile.getline(fileInput, 100);
		name = string(fileInput);
		students[index].setName(name);
		inFile.getline(fileInput, 100);
		id = string(fileInput);
		students[index].setId(id);
		inFile.getline(fileInput, 100);
		dob = string(fileInput);
		students[index].setDOB(dob);
		inFile.getline(fileInput, 100);
		gpa = string(fileInput);
		students[index].setCGPA(gpa);
		index++;
	}
	inFile.close();
}

void initalizeInstructor(Instructor& teacher)
{
	ifstream inFile;
	string office, name, dob, designation;
	char fileInput[100];
	inFile.open("instructor.txt");
	//Iterate through file until the end of file
	//Assign values for the instructor
	while (!inFile.eof())
	{
		inFile.getline(fileInput, 100);
		name = string(fileInput);
		teacher.setName(name);
		inFile.getline(fileInput, 100);
		dob = string(fileInput);
		teacher.setDOB(dob);
		inFile.getline(fileInput, 100);
		office = string(fileInput);
		teacher.setOffice(office);
		inFile.getline(fileInput, 100);
		designation = string(fileInput);
		teacher.setDesignation(designation);
	}
	inFile.close();
}

void initalizeCourse(Student students[], Instructor& instructor, Course& course)
{
	ifstream inFile;
	inFile.open("course.txt");
	string name, id, enrolledStudents;
	int numStudents;
	char fileInput[100];
	//Iterate through file and assign values
	while (!inFile.eof())
	{
		inFile.getline(fileInput, 100);
		name = string(fileInput);
		course.setName(name);
		inFile.getline(fileInput, 100);
		id = string(fileInput);
		course.setId(id);
		inFile.getline(fileInput, 100);
		enrolledStudents = string(fileInput);
	}
	numStudents = atoi(enrolledStudents.c_str());
	course.setStudentList(students, numStudents);
	course.setInstructor(instructor);
	inFile.close();
}