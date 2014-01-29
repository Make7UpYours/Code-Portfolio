/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS 303
  11/27/2013
  Project 3 - Student Enrollment
  Description: Implement a system that allows students to enroll in courses. A
  student can enroll in multiple courses. A course can have multiple enrolled
  students. Each student has a title and a unique id as well. Upon enrollment,
  a record should be kept of the date and time when a student enrolls in a
  course.
  --Course.h is the header file for class Course--
  Course will be used to store course information that a student may enroll
  or be enrolled in.
*/
#ifndef _COURSE_H_
#define _COURSE_H_
#include <map>
#include <fstream>
#include "Student.h"

using std::map;
using std::ostream;

//class to course information and activities
class Course
{
public:
	//Constructors
	Course()
		:m_id("id"), m_title("title")
	{}
	Course(string& id)
		:m_id(id), m_title("title")
	{}
	Course(string& title, string& id)
		:m_id(id), m_title(title)
	{}

	//Public member functions.
	/** Returns the value of m_title for an instance of Course class.*/
	string GetTitle() const
	{
		return m_title;
	}

	//Operator overloads.
	/** Less-than operator overload, used to sort within a set.*/
	friend bool operator<(const Course& c1, const Course& c2)
	{
		return c1.m_id < c2.m_id;
	}
	/** Output stream operator overload, used for outputing an instance of 
		the Course class.
	*/
	friend ostream& operator<<(ostream& out, const Course& course)
	{
		return out << course.m_id << " - " << course.m_title;
	}

private:
	//Private member variables.
	string m_id;
	string m_title;
};

#endif /*_COURSE_H_*/

