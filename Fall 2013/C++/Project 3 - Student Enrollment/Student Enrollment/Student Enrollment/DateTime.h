/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS 303
  11/27/2013
  Project 3 - Student Enrollment
  Description: Implement a system that allows students to enroll in courses. A
  student can enroll in multiple courses. A course can have multiple enrolled
  students. Each student has a title and a unique id as well. Upon enrollment,
  a record should be kept of the date and time when a student enrolls in a
  course.
  --DateTime.h is the header file for class DateTime--
  DateTime will be used to store information about the current date and time
  on the local machine. Also used to keep track of when a student enrolls in
  a particular course.
*/
#ifndef _DATE_TIME_H_
#define _DATE_TIME_H_
#include <string>
#include <fstream>

using std::string;
using std::ostream;

class DateTime
{
private:
	//Private member variables.
	string m_weekday;
	string m_month;
	string m_monthdate;
	string m_time;
	string m_year;
public:
	//Constructors
	DateTime()
		:m_weekday("Weekday"), m_month("Month"), m_monthdate("0"), 
		 m_time("00:00:00"), m_year("0000")
	{}

	//Public member functions.
	/** Obtains the current time and date from the system.
		Assigns values to the member variables according to their placement
		obtained from the system time.
	*/
	void SetCurTime();

	//Operator overloads
	/** Outstream operator overload, used to output the proper DateTime
		format using <<.
	*/
	friend ostream& operator<<(ostream& out, const DateTime& date)
	{
		return out << date.m_time << " - " << date.m_weekday << ", " 
				<< date.m_month << " " << date.m_monthdate << " " 
				<< date.m_year;
	}
};

#endif //_DATE_TIME_H_