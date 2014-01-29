/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS 303
  11/27/2013
  Project 3 - Student Enrollment
  Description: Implement a system that allows students to enroll in courses. A
  student can enroll in multiple courses. A course can have multiple enrolled
  students. Each student has a title and a unique id as well. Upon enrollment,
  a record should be kept of the date and time when a student enrolls in a
  course.
  --DateTime.cpp is the implementation file for class DateTime--
  DateTime will be used to store information about the current date and time
  on the local machine. Also used to keep track of when a student enrolls in
  a particular course.
*/
#include <ctime>
#include "DateTime.h"

/** Obtains the current time and date from the system.
	Assigns values to the member variables according to their placement
	obtained from the system time.
*/
void DateTime::SetCurTime()
{
	/*Code snippit obtained from:
	  http://www.cplusplus.com/reference/ctime/ctime/
	  modified slightly from version on website.
	*/
	time_t rawtime;
	char buffer[100];
	time(&rawtime);
	ctime_s(buffer, 100, &rawtime);
	string dateAndTime = string(buffer);
	//Section up dateAndTime accordingly and store proper values.
	m_weekday =	dateAndTime.substr(0,3);
	m_month = dateAndTime.substr(4,3);
	m_monthdate = dateAndTime.substr(8,2);
	m_time = dateAndTime.substr(11,8);
	m_year = dateAndTime.substr(20, 4);
}