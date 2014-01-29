/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS 303
  11/27/2013
  Project 3 - Student Enrollment
  Description: Implement a system that allows students to enroll in courses. A
  student can enroll in multiple courses. A course can have multiple enrolled
  students. Each student has a title and a unique id as well. Upon enrollment,
  a record should be kept of the date and time when a student enrolls in a
  course.
  --Enrollment.h is the header file for class Enrollment--
  Enrollment will be used to keep track of the courses and students and will
  allow the manipulation of both as needed.
*/
#ifndef _ENROLLMENT_H_
#define _ENROLLMENT_H_
#include <map>
#include <set>
#include <string>
#include "Student.h"
#include "Course.h"
#include "DateTime.h"

using std::map;
using std::set;
using std::string;

class Enrollment
{
private:
	//const private member variables
	const int MAX_COURSES; //Max number of courses a student may enroll in.
	
	//Private member variables
	DateTime m_date; //Used to obtain system time information.
	//Stores information about a student, their courses and times of enrollment.
	map<Student, map<Course, DateTime> > m_enrollmentMap;
	set<Course> m_courseList; //A list of courses to be enrolled in.
	
	//Private member functions
	/** Returns the list of courses that a student is enrolled in.
		Is a private function to limit user error if an incorrect studentID
		is passed as a parameter.
		@param studentID - The id of the student.
	*/
	map<Course, DateTime> EnrolledCourses(string& studentID) const;
public:
	//Constructors
	Enrollment()
		:MAX_COURSES(5)
	{}
	Enrollment(const set<Course>& courses, const set<Student>& students)
		:MAX_COURSES(5)
	{
		//Loads active courses.
		m_courseList = courses;
		set<Student>::const_iterator itrStudent;
		for (itrStudent = students.begin();
			 itrStudent != students.end();
			 ++itrStudent)
		{
			m_enrollmentMap[*itrStudent];
		}
	}

	//Public member functions
	/** Adds a student to m_enrollmentMap, checks to see if the 
		student id is already in use and will let the user know if it is.
		@param name - The student's name.
		@param id - The student's id.
	*/
	void AddStudent(string& name, string& id);
	/** Searches for a student based upon their id and changes their name.
		If the student is not found lets the user know.
		@param id - The student's id.
		@param newName - The new name of the student.
	*/
	void EditStudent(string& id, string& newName);
	/** Searches for a student based upon their student and deletes the
		student if found. Lets the user know if the deletion was successful
		or not.
		@param id - The student's id.
	*/
	void DeleteStudent(string& id);
	/** Adds a course to m_courseList, checks to see if the course exists.
		Lets the user know if the course already existed.
		@param title - The course title.
		@param id - The course id.
	*/
	void AddCourse(string& title, string& id);
	/** Edits the title of a course according to the id supplied by the user.
		Checks to see if the course can be found then proceeds to update the
		information for that course.
		@param id - The course id.
		@param newTitle - The new title for the course.
	*/
	void EditCourse(string& id, string& newTitle);
	/** Removes a course based upon the id supplied by the user.
		Will search for the course by it's id and attempt to remove that course
		from the listing.
		If the course is not found, will let the user know.
		@param id - The course id.
	*/
	void DeleteCourse(string& id);
	/** Drops a course from a student's enrollment based upon the course id and
		student id supplied by the user.
		Checks to see if the student can be found & if the student is indeed
		enrolled in the specified course.
		@param studentId - The student's id.
		@param courseId - The course's id.
	*/
	void DropCourse(string& studentId, string& courseId);
	/** Outputs the current list of courses to choose from. */
	void OutputCourseList() const;
	/** Outputs the current lits of active students. */
	void ViewActiveStudents() const;
	/** Outputs the courses that a student is currently enrolled in based upon
		the student id provided by the user.
		Will let the user know if a student is not found or has not enrolled for
		any courses.
		@param id - The student id.
	*/
	void ViewEnrolledCourses(string& id) const;
	/** Enrolls a student into a course based upon the id of the 
		student and the id of the course.
		Determines if the student is already enrolled in a course.
		@param studentId - The id of the student.
		@param courseId - The id of the course.
	*/
	void EnrollCourse(string& studentId, string& courseId);
}; //end class Enrollment

#endif //_ENROLLMENT_H_