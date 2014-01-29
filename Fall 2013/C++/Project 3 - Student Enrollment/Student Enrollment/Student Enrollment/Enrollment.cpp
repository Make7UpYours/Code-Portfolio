/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS 303
  11/27/2013
  Project 3 - Student Enrollment
  Description: Implement a system that allows students to enroll in courses. A
  student can enroll in multiple courses. A course can have multiple enrolled
  students. Each student has a title and a unique id as well. Upon enrollment,
  a record should be kept of the date and time when a student enrolls in a
  course.
  --Enrollment.cpp is the implementation file for class Enrollment--
  Enrollment will be used to keep track of the courses and students and will
  allow the manipulation of both as needed.
*/
#include <iostream>
#include "Enrollment.h"

using std::pair;
using std::cout;
using std::endl;

/** Returns the list of courses that a student is enrolled in.
	Is a private function to limit user error if an incorrect studentID
	is passed as a parameter.
	@param studentID - The id of the student.
*/
map<Course, DateTime> Enrollment::EnrolledCourses(string& studentID) const
{
	Student student(studentID);
	return m_enrollmentMap.at(student);
}

/** Adds a student to m_enrollmentMap, checks to see if the 
	student id is already in use and will let the user know if it is.
	@param name - The student's name.
	@param id - The student's id.
*/
void Enrollment::AddStudent(string& name, string& id)
{
	Student newStudent(id, name);
	/*Code snippet was gathered from: 
	  http://www.cplusplus.com/reference/map/map/find/
	*/
	map<Student, map<Course, DateTime> >::iterator itrInsertionCheck;
	itrInsertionCheck = m_enrollmentMap.find(newStudent);
	if (itrInsertionCheck == m_enrollmentMap.end())
	{
		//newStudent has not already been inserted.
		m_enrollmentMap[newStudent];
		cout << "Student id: " << id << "\nStudent name: " << name
			 << "\nAdded to the enrollment list.\n\n";
	}
	else
	{
		cout << "Student id: " << id << " is already in use.\n\n";
	}
	
}

/** Searches for a student based upon their id and changes their name.
	If the student is not found lets the user know.
	@param id - The student's id.
	@param newName - The new name of the student.
*/
void Enrollment::EditStudent(string& id, string& newName)
{
	Student student(id, newName);
	map<Student, map<Course, DateTime> >::iterator itrStudent;
	itrStudent = m_enrollmentMap.find(student);
	if (itrStudent == m_enrollmentMap.end())
	{
		//student not found.
		cout << "Student id: " << id << " was not found.\n\n";
	}
	else
	{
		//Change the name of the student.
		string oldName = itrStudent->first.GetName();
		map<Course, DateTime> studentCourses = EnrolledCourses(id);
		m_enrollmentMap.erase(itrStudent);
		m_enrollmentMap[student] = studentCourses;
		cout << "Student id: " << id << "\nName has been updated from, "
			 << oldName << " to " << newName << ".\n\n";
	}
}

/** Searches for a student based upon their student and deletes the
	student if found. Lets the user know if the deletion was successful
	or not.
	@param id - The student's id.
*/
void Enrollment::DeleteStudent(string& id)
{
	Student student(id);
	map<Student, map<Course, DateTime> >::iterator itrStudent;
	itrStudent = m_enrollmentMap.find(student);
	if (itrStudent == m_enrollmentMap.end())
	{
		//student not found.
		cout << "Student id: " << id << " was not found.\n\n";
	}
	else
	{
		cout << "Student id: " << id << "\nStudent name: "
			 << itrStudent->first.GetName() 
			 << "\nRemoved from enrollment list.\n\n";
		m_enrollmentMap.erase(itrStudent);
		
	}
}

/** Adds a course to m_courseList, checks to see if the course exists.
	Lets the user know if the course already existed.
	@param title - The course title.
	@param id - The course id.
*/
void Enrollment::AddCourse(string& title, string& id)
{
	Course newCourse(title, id);
	/*Code snippet was gathered from:
	  http://www.cplusplus.com/reference/set/set/insert/
	*/
	pair<set<Course>::iterator,bool> insertionCheck;
	insertionCheck = m_courseList.insert(newCourse);
	if (insertionCheck.second == false)
	{
		//newCourse already exists
		cout << "Course id: " << id << "\nCourse title: " << title
			 << "\nCourse id is already in use.\n\n";
	}
	else
	{
		cout << "Course id: " << id << "\nCourse title: " << title
			 << "\nAdded to the course list.\n\n";
	}
}

/** Edits the title of a course according to the id supplied by the user.
	Checks to see if the course can be found then proceeds to update the
	information for that course.
	@param id - The course id.
	@param newTitle - The new title for the course.
*/
void Enrollment::EditCourse(string& id, string& newTitle)
{
	Course updatedCourse(newTitle, id);
	set<Course>::iterator itrCourse;
	itrCourse = m_courseList.find(updatedCourse);
	if (itrCourse == m_courseList.end())
	{
		//Course not found.
		cout << "Course id: " << id << "\nWas not found for editing.\n\n";
	}
	else
	{
		//Change the name of the course.
		string oldTitle = itrCourse->GetTitle();
		//Update m_courseList.
		m_courseList.erase(itrCourse);
		m_courseList.insert(updatedCourse);
		//Search and update m_enrollmentMap.
		map<Student, map<Course, DateTime> >::iterator itrCourseMap;
		for (itrCourseMap = m_enrollmentMap.begin();
			 itrCourseMap != m_enrollmentMap.end();
			 ++itrCourseMap)
		{
			/*Iterate though every student in m_enrollmentMap & search
			for the course.*/
			map<Course, DateTime>::iterator itrEnrolledCourse;
			itrEnrolledCourse = itrCourseMap->second.find(updatedCourse);
			if (itrEnrolledCourse != itrCourseMap->second.end())
			{
				DateTime time = itrEnrolledCourse->second;
				//Update the information for the course.
				itrCourseMap->second.erase(itrEnrolledCourse);
				itrCourseMap->second[updatedCourse] = time;
			}
		}
		cout << "Course id: " << id << "\nTitle has been updated from, "
			 << oldTitle << " to " << newTitle <<".\n\n";
	}
}

/** Removes a course based upon the id supplied by the user.
	Will search for the course by it's id and attempt to remove that course
	from the listing.
	If the course is not found, will let the user know.
	@param id - The course id.
*/
void Enrollment::DeleteCourse(string& id)
{
	Course course(id);
	set<Course>::iterator itrCourse;
	itrCourse = m_courseList.find(course);
	if (itrCourse == m_courseList.end())
	{
		//Course not found.
		cout << "Course id: " << id << "\nWas not found for deletion.\n\n";
	}
	else
	{
		//Remove the course.
		cout << "Course id: " << id << "\nCourse title: "
			 << itrCourse->GetTitle() 
			 << "\nHas been removed from the course listing.\n\n";
		m_courseList.erase(itrCourse);
		//Search through m_enrollmentMap and remove enrolled courses.
		map<Student, map<Course, DateTime> >::iterator itrCourseMap;
		for (itrCourseMap = m_enrollmentMap.begin();
			 itrCourseMap != m_enrollmentMap.end();
			 ++itrCourseMap)
		{
			map<Course, DateTime>::iterator itrEnrolledCourse;
			itrEnrolledCourse = itrCourseMap->second.find(course);
			if (itrEnrolledCourse != itrCourseMap->second.end())
			{
				//Remove the course.
				itrCourseMap->second.erase(itrEnrolledCourse);
			}
		}
	}
}

/** Drops a course from a student's enrollment based upon the course id and
	student id supplied by the user.
	Checks to see if the student can be found & if the student is indeed
	enrolled in the specified course.
	@param studentId - The student's id.
	@param courseId - The course's id.
*/
void Enrollment::DropCourse(string& studentId, string& courseId)
{
	Course course(courseId);
	Student student(studentId);
	map<Student, map<Course, DateTime> >::iterator itrCourseMap;
	itrCourseMap = m_enrollmentMap.find(student);
	if (itrCourseMap == m_enrollmentMap.end())
	{
		//Student not found.
		cout << "Student id: " << studentId << "\nWas not found.\n\n";
	}
	else
	{
		//Check to see if the student is enrolled in any courses.
		if (itrCourseMap->second.size() == 0)
		{
			cout << "Student id: " << studentId << "\nStudent name: "
				 << itrCourseMap->first.GetName() 
				 << "\nHas not enrolled in any courses.\n\n";
		}
		//Attempt to find the enrolled course.
		map<Course, DateTime>::iterator itrCourse;
		itrCourse = itrCourseMap->second.find(course);
		if (itrCourse == itrCourseMap->second.end())
		{
			//Course not found.
			cout << "Course id: " << courseId << "\nWas not found.\n\n";
		}
		else
		{
			//Drop the course.
			cout << "Course id: " << courseId << "\nCourse title: "
				 << itrCourse->first.GetTitle() << endl
				 << itrCourseMap->first 
				 << " dropped the course successfully.\n\n";
			itrCourseMap->second.erase(itrCourse);
		}
	}
}

/** Outputs the current list of courses to choose from. */
void Enrollment::OutputCourseList() const
{
	cout << "ACTIVE COURSES:\n"
		 << "COURSE ID - COURSE TITLE\n";
	int count = 1;
	for (set<Course>::const_iterator itr = m_courseList.begin();
		 itr != m_courseList.end();
		 ++itr)
	{
		cout << count << ". " << *itr << endl;
		count++;
	}
	cout << endl;
}

/** Outputs the current lits of active students. */
void Enrollment::ViewActiveStudents() const
{
	cout << "ACTIVE STUDENTS:\n"
		 << "STUDENT ID - STUDENT NAME\n";
	int count = 1;
	map<Student, map<Course, DateTime> >::const_iterator itr;
	for (itr = m_enrollmentMap.begin();
		 itr != m_enrollmentMap.end();
		 ++itr)
	{
		cout << count << ". " << itr->first << endl;
		count++;
	}
	cout << endl;
}

/** Outputs the courses that a student is currently enrolled in based upon
	the student id provided by the user.
	Will let the user know if a student is not found or has not enrolled for
	any courses.
	@param id - The student id.
*/
void Enrollment::ViewEnrolledCourses(string& id) const
{
	Student student(id);
	map<Student, map<Course, DateTime> >::const_iterator itrStudent;
	itrStudent = m_enrollmentMap.find(student);
	if (itrStudent == m_enrollmentMap.end())
	{
		cout << "Student id: " << id << " was not found.\n\n";
	}
	else
	{
		map<Course, DateTime> courses = EnrolledCourses(id);
		if (courses.size() == 0)
		{
			//Student hasn't enrolled in any courses.
			cout << "Student id: " << id << "\nStudent name: "
				 << itrStudent->first.GetName() 
				 << "\nHas not enrolled for any courses yet.\n\n";
		}
		else
		{
			int count = 1;
			cout << "Student id: " << id << "\nStudent name: " 
				 << itrStudent->first.GetName() << "\nENROLLED COURSES:\n"
				 << "COURSE ID - COURSE TITLE, ENROLLMENT TIME - DATE\n";
			map<Course, DateTime>::const_iterator itrCourses;
			for (itrCourses = courses.begin();
				 itrCourses != courses.end();
				 ++itrCourses)
			{
				cout << count << ". " << itrCourses->first 
					 << ", " << itrCourses->second << endl;
				count++;
			}
			cout << endl;
		}
	}
}

/** Enrolls a student into a course based upon the id of the 
	student and the id of the course.
	Determines if the student is already enrolled in a course.
	@param studentId - The id of the student.
	@param courseId - The id of the course.
*/
void Enrollment::EnrollCourse(string& studentId, string& courseId)
{
	Student curStudent(studentId);
	Course curCourse(courseId);
	map<Student, map<Course, DateTime> >::iterator itrStudent;
	set<Course>::iterator itrCourse;
	itrStudent = m_enrollmentMap.find(curStudent);
	itrCourse = m_courseList.find(curCourse);
	if (itrStudent == m_enrollmentMap.end())
	{
		//curStudent not found.
		cout << "Student id: " << studentId << " was not found.\n\n";
	}
	else if (itrCourse == m_courseList.end())
	{
		//curCourse not found.
		cout << "Course id: " << courseId << " was not found.\n\n";
	}
	else
	{
		if (itrStudent->second.size() >= MAX_COURSES)
		{
			//Cannot enroll in anymore courses.
			cout << "Student id: " << studentId
				 << "\nStudent name: " << itrStudent->first.GetName()
				 << "\nCannot enroll in more than 5 courses.\n"
				 << "Must drop a course in order to enroll for " << *itrCourse
				 << ".\n\n";

		}
		else
		{
			//Proceed with enrollment.
			map<Course, DateTime>::iterator itrDupCourseCheck;
			itrDupCourseCheck = itrStudent->second.find(curCourse);
			if (itrDupCourseCheck == itrStudent->second.end())
			{
				//Add the course to the student's enrolled courses.
				m_date.SetCurTime();
				itrStudent->second[*itrCourse] = m_date;
				cout << "Student id: " << studentId 
					 << "\nStudent name: " << itrStudent->first.GetName()
					 << "\nEnrolled in " << *itrCourse << " at " << m_date
					 << endl << endl;
			}
			else
			{
				//Student is already enrolled in the course.
				cout << "Student id: " << studentId 
					 << "\nStudent name: " << itrStudent->first.GetName()
					 << "\nIs already enrolled in " << *itrCourse << endl
					 << "Can only enroll in a course once.\n\n";
			}
		}
	}

}