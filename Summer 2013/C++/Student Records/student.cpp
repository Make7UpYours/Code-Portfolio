/*William Freeman
  CS201L
  7/30/2013
  Final Exam - Student Records
  Description: Create a program that helps the school administration to
  maintain student records.*/
#include <string>

#include "student.h"

using std::string;

//Default constructor.
//Assigns 0 values for member variables for an instance of Student class.
Student::Student()
{
	m_id = 0;
	m_name = "name";
	m_cgpa = 0.0;
}

//Constructor.
//Assigns member variables to the parameters passed for an instnace of
//Student class.
Student::Student(int id, string name, double cgpa)
{
	m_id = id;
	m_name = name;
	m_cgpa = cgpa;
}

//Returns the value of m_id for an instance of Student class.
int Student::GetId() const
{
	return m_id;
}

//Returns the value of m_name for an instance of Student class.
string Student::GetName() const
{
	return m_name;
}

//Returns the value of m_cgpa for an instance of Student class.
double Student::GetCgpa() const
{
	return m_cgpa;
}