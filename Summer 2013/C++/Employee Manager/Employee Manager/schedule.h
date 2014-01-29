/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --schedule.h is the header file for the Schedule class--*/
#ifndef _SCHEDULE
#define _SCHEDULE
#include <string>

#include "employee.h"

using std::string;

class Schedule
{
public:
	//Initalizes values for private members for an instance of Schedule class.
	void Setup(int hour);
	//Sets m_ptrEmployee to the passed parameter.
	void AssignEmployee(Employee* employee);
	//Checks to see if m_ptrEmployee is set.
	//If it is then returns the name of the employee, 
	//if not then returns "UNALLOCATED".
	string GetEmployeeName() const;
	//Outputs m_beginHour and calls GetEmployeeName().
	void Output() const;
	//Resets m_ptrEmployee to a NULL value for an instance of Schedule class.
	void Reset();
	//Checks to see if an employee has been assigned to m_ptrEmployee.
	//Returns true if m_ptrEmployee is not NULL.
	bool GetIsSet() const;
private:
	Employee* m_ptrEmployee;
	int m_beginHour;
};
#endif