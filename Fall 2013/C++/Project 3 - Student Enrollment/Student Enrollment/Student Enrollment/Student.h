/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS 303
  11/27/2013
  Project 3 - Student Enrollment
  Description: Implement a system that allows students to enroll in courses. A
  student can enroll in multiple courses. A course can have multiple enrolled
  students. Each student has a title and a unique id as well. Upon enrollment,
  a record should be kept of the date and time when a student enrolls in a
  course.
  --Student.h is the header file for class Student--
  Student will be used to store information about a student that will be 
  enrolling in courses.
*/
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <fstream>

using std::string;
using std::ostream;

class Student
{
private:
	//Private member variables.
	string m_id;
	string m_name;
public:
	//Constructors.
	Student()
		:m_id("id"), m_name("name")
	{}
	Student(string& id)
		:m_id(id), m_name("name")
	{}
	Student(string& id, string& name)
		:m_id(id), m_name(name)
	{}

	//Public member functions.
	/** Returns the value of m_name for an instance of Student.*/
	string GetName() const
	{
		return m_name;
	}

	//Operator overloads.
	/** Less-than operator overload, used for sorting purposes for a 
		container of type Student.
	*/
	friend bool operator<(const Student& s1, const Student& s2)
	{
		return s1.m_id < s2.m_id;
	}
	/** Output stream operator overload, used for outputing an instance of 
		the Student class.
	*/
	friend ostream& operator<<(ostream& out, const Student& student)
	{
		return out << student.m_id << " - " << student.m_name;
	}
};

#endif /*_STUDENT_H_*/
