/*William Freeman
  CS201L
  7/30/2013
  Final Exam - Student Records
  Description: Create a program that helps the school administration to
  maintain student records.*/
#ifndef _STUDENT
#define _STUDENT
#include <string>

using std::string;

class Student
{
private:
	int m_id;
	string m_name;
	double m_cgpa;
public:
	friend class SortedList;

	//Default constructor.
	//Assigns 0 values for member variables for an instance of Student class.
	Student();
	//Constructor.
	//Assigns member variables to the parameters passed for an instnace of
	//Student class.
	Student(int id, string name, double cgpa);
	//Returns the value of m_id for an instance of Student class.
	int GetId() const;
	//Returns the value of m_name for an instance of Student class.
	string GetName() const;
	//Returns the value of m_cgpa for an instance of Student class.
	double GetCgpa() const;
}; //Student class

#endif //_STUDENT