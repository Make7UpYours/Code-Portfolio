/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS 303
  11/27/2013
  Project 3 - Student Enrollment
  Description: Implement a system that allows students to enroll in courses. A
  student can enroll in multiple courses. A course can have multiple enrolled
  students. Each student has a title and a unique id as well. Upon enrollment,
  a record should be kept of the date and time when a student enrolls in a
  course.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include "Enrollment.h"
#include "Student.h"
#include "Course.h"

using namespace std;

enum MAIN_MENU_CHOICES {QUIT, STUDENT, COURSE}; //MainMenu() selection.
//StudentMenu() selection.
enum STUDENT_CHOICES {STU_RET, STU_ADD, STU_EDIT, STU_DELETE, STU_VIEW_COURSES,
					  STU_ENROLL, STU_DROP}; 
//CourseMenu() selection.
enum COURSE_CHOICES {COUR_RET,COUR_ADD, COUR_EDIT, COUR_DELETE};

int MainMenu();
/*Displays the menu options for the user.
  Asks them to enter their menu option choice and returns their selection.*/
int StudentMenu();
/*Displays the menu options for student operations.
  Asks the user to enter a menu option and returns their selection.*/
int CourseMenu();
/*Displays the menu options for course operations.
  Asks the user to enter a menu option and returns their selection.*/
void ProcessStuFunc(int& choice, Enrollment& classEnrollment);
/*Processes the menu choice made by the user for student operations and calls
  the correct functions for the Enrollment class instance.*/
void ProcessCourFunc(int& choice, Enrollment& classEnrollment);
/*Processes the menu choice made by the user for course operations and calls
  the correct functions for the Enrollment class instance.*/
set<Course> PreLoadCourses();
/*Reads through Courses.txt, making a set of each Course type. 
  Returns the set of Courses.*/
set<Student> PreLoadStudents();
/*Reads through Students.txt making a set of each Student type.
  Returns the set of Students.*/

int main()
{
	set<Course> preLoadedCourses = PreLoadCourses();
	set<Student> preLoadedStudents = PreLoadStudents();
	Enrollment classEnrollment(preLoadedCourses, preLoadedStudents);
	int choice;
	do
	{
		choice = MainMenu();
		switch(choice)
		{
		case STUDENT:
			{
				//Student operations menu.
				choice = StudentMenu();
				ProcessStuFunc(choice, classEnrollment);
				break;
			}
		case COURSE:
			{
				//Course operations menu.
				choice = CourseMenu();
				ProcessCourFunc(choice, classEnrollment);
				break;
			}
		case QUIT:
			{
				cout << "Goodbye!\n\n";
				break;
			}
		default:
			{
				cout << "Invalid menu operation.\n\n";
			}
		}
			
			
	} while(choice != QUIT);

	system("Pause");
	return 0;
}

int MainMenu()
{
	int choice;
	cout << "****** STUDENT COURSE ENROLLMENT SYSTEM ******\n"
		 << STUDENT << ". Student Operations\n"
		 << COURSE << ". Course Operations\n"
		 << QUIT << ". Quit program\n"
		 << "Enter a menu option: ";
	cin >> choice;
	cout << endl;
	return choice;
}

int StudentMenu()
{
	int choice;
	do
	{
		cout << "****** STUDENT OPERATIONS MENU ******\n"
			 << STU_ADD << ". Add a student\n"
			 << STU_EDIT << ". Edit a student's name\n"
			 << STU_DELETE << ". Delete a student\n"
			 << STU_VIEW_COURSES << ". View enrolled courses\n"
			 << STU_ENROLL << ". Enroll a student in a course\n"
			 << STU_DROP << ". Drop a student from a course\n"
			 << STU_RET << ". Return to Main Menu\n"
			 << "Enter a menu option: ";
		cin >> choice;
		cout << endl;
		if (choice < STU_RET || choice > STU_DROP)
		{
			cout << "Invalid menu operation.\n\n";
		}
	} while(choice < STU_RET || choice > STU_DROP);
	return choice;
}

int CourseMenu()
{
	int choice;
	do
	{
		cout << "****** COURSE OPERATIONS MENU ******\n"
			 << COUR_ADD << ". Add a course\n"
			 << COUR_EDIT << ". Edit a course's title\n"
			 << COUR_DELETE << ". Delete a course\n"
			 << COUR_RET << ". Return to Main Menu\n"
			 << "Enter a menu option: ";
		cin >> choice;
		cout << endl;
		if (choice < COUR_RET || choice > COUR_DELETE)
		{
			cout << "Invalid menu operation.\n\n";
		}
	} while(choice < COUR_RET || choice > COUR_DELETE);
	return choice;
}

void ProcessStuFunc(int& choice, Enrollment& classEnrollment)
{
	switch(choice)
	{
	case STU_ADD:
		{
			classEnrollment.ViewActiveStudents();
			string studentId, studentName, junk;
			cout << "Enter student's ID number (CANNOT BE CHANGED): ";
			cin >> studentId;
			getline(cin, junk); //Clear the junk from cin.
			cout << "Enter the student's name: ";
			getline(cin, studentName);
			cout << endl;
			classEnrollment.AddStudent(studentName, studentId);
			break;
		}
	case STU_EDIT:
		{
			classEnrollment.ViewActiveStudents();
			string studentId, newName, junk;
			cout << "Enter the ID number of the student to edit: ";
			cin >> studentId;
			getline(cin, junk); //Clear the junk from cin.
			cout << "Enter the new name of the student: ";
			getline(cin, newName);
			cout << endl;
			classEnrollment.EditStudent(studentId, newName);
			break;
		}
	case STU_DELETE:
		{
			classEnrollment.ViewActiveStudents();
			string studentId;
			cout << "Enter the ID number of the student to delete: ";
			cin >> studentId;
			cout << endl;
			classEnrollment.DeleteStudent(studentId);
			break;
		}
	case STU_VIEW_COURSES:
		{
			classEnrollment.ViewActiveStudents();
			string studentId;
			cout << "Enter the ID number of the student to view enrolled "
				 << "courses: ";
			cin >> studentId;
			cout << endl;
			classEnrollment.ViewEnrolledCourses(studentId);
			break;
		}
	case STU_ENROLL:
		{
			string studentId, courseId;
			//Select student.
			classEnrollment.ViewActiveStudents();
			cout << "Enter ID number of student: ";
			cin >> studentId;
			cout << endl;
			//Select course.
			classEnrollment.OutputCourseList();
			cout << "Select a course to enroll by entering the course ID: ";
			cin >> courseId;
			cout << endl;
			classEnrollment.EnrollCourse(studentId, courseId);
			break;
		}
	case STU_DROP:
		{
			string studentId, courseId;
			//Select student.
			classEnrollment.ViewActiveStudents();
			cout << "Enter ID number of student: ";
			cin >> studentId;
			cout << endl;
			//Select course to drop.
			classEnrollment.ViewEnrolledCourses(studentId);
			cout << "Select a course to drop by entering the course ID: ";
			cin >> courseId;
			cout << endl;
			classEnrollment.DropCourse(studentId, courseId);
			break;
		}
	case STU_RET:
		{
			//Increment choice so program doesn't end.
			choice++;
			break;
		}
	}
}

void ProcessCourFunc(int& choice, Enrollment& classEnrollment)
{
	switch(choice)
	{
	case COUR_ADD:
		{
			classEnrollment.OutputCourseList();
			string courseId, courseTitle, junk;
			cout << "Enter the course ID (CANNOT BE CHANGED): ";
			cin >> courseId;
			getline(cin, junk); //Clear junk from cin.
			cout << "Enter the title of the course: ";
			getline(cin, courseTitle);
			cout << endl;
			classEnrollment.AddCourse(courseTitle, courseId);
			break;
		}
	case COUR_EDIT:
		{
			classEnrollment.OutputCourseList();
			string courseId, newCourseTitle, junk;
			cout << "Enter the ID of the course to change the name of: ";
			cin >> courseId;
			getline(cin, junk); //Clear junk from cin.
			cout << "Enter the new title of the course: ";
			getline(cin, newCourseTitle);
			cout << endl;
			classEnrollment.EditCourse(courseId, newCourseTitle);
			break;
		}
	case COUR_DELETE:
		{
			classEnrollment.OutputCourseList();
			string courseId;
			cout << "Enter the ID of the course to delete: ";
			cin >> courseId;
			cout << endl;
			classEnrollment.DeleteCourse(courseId);
			break;
		}
	case COUR_RET:
		{
			//Increment choice so program doesn't end.
			choice++;
			break;
		}
	}
}

set<Course> PreLoadCourses()
{
	set<Course> courses;
	ifstream inFile("Courses.txt");
	string id, title;
	while (!inFile.eof())
	{
		//Obtain title and id & insert course to courses.
		getline(inFile, id);
		getline(inFile, title);
		Course course(title, id);
		courses.insert(course);
	}
	inFile.close();
	return courses;
}

set<Student> PreLoadStudents()
{
	set<Student> students;
	ifstream inFile("Students.txt");
	string id, name;
	while (!inFile.eof())
	{
		//Obtain name and id, insert student to students.
		getline(inFile, id);
		getline(inFile, name);
		Student student(id, name);
		students.insert(student);
	}
	inFile.close();
	return students;
}
