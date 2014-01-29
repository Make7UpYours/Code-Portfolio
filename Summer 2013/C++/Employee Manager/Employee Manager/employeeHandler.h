/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --employeeHandler.h is the header file for the EmployeeHandler class--*/
#ifndef _EMPLOYEE_HANDLER
#define _EMPLOYEE_HANDLER
#include "employee.h"

class EmployeeHandler
{
public:
	//Default constructor.
	//Initalizes m_employeeCount to 0 for an instance of EmployeeHandler class.
	EmployeeHandler();
	//Destructor.
	//Frees memory by deleting m_lstEmployees.
	~EmployeeHandler();
	//Prompt user for all the information for an employee and call setup function
	//for the current employee.
	//Increment m_employeeCount by 1.
	void AddEmployee();
	//Displays a list of all employees.
	//Allows the user to choose one and edit the employee's information.
	void EditEmployee();
	//Displays a list of all employees.
	//User chooses which employee to layoff.
	void LayoffEmployee();
	//Outputs all employees from 0 to the value of m_employeeCount.
	void DisplayEmployeeList() const;
	//Output a list of all employees and asks the user to enter the index of
	//an employee they wish to modify.
	int EmployeeSelection() const;
	//Returns a reference to an Employee at index.
	Employee& GetEmployee(int index);
	//Returns m_employeeCount for an instance of EmployeeHandler.
	int GetEmployeeCount() const;
	//Exports the list of employees as an HTML file.
	void ExportEmployeeHTML() const;
	//Exports the list of employees as a .csv file.
	void ExportEmployeeCSV() const;
private:
	//Creates a temp array which copies m_lstEmployees and increases
	//m_lstSize by 5.
	//Returns the newly sized temp array.
	Employee* ResizeEmployeeLst();
	//Unstable version of ResizeEmployeeLst().
	//void ResizeEmployeeLst();

	Employee* m_lstEmployees;
	int m_employeeCount;
	int m_lstSize;
};
#endif