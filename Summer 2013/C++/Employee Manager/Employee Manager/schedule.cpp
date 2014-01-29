/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --schedule.cpp is the implementation file for the Schedule class--*/
#include <iostream>

#include "schedule.h"

using std::cout;
using std::endl;

//Initalizes values for private members for an instance of Schedule class.
void Schedule::Setup(int hour)
{
	m_ptrEmployee = NULL;
	m_beginHour = hour;
}

//Sets m_ptrEmployee to the passed parameter.
void Schedule::AssignEmployee(Employee* employee)
{
	m_ptrEmployee = employee;
}

//Checks to see if m_ptrEmployee is set.
//If it is then returns the name of the employee, 
//if not then returns "UNALLOCATED".
string Schedule::GetEmployeeName() const
{
	Employee employee;
	if (GetIsSet())
	{
		employee = *m_ptrEmployee;
		return employee.GetName();
	}
	else
	{
		return "UNALLOCATED";
	}
}

//Outputs m_beginHour and calls GetEmployeeName().
void Schedule::Output() const
{
	cout << m_beginHour << ":00\t----\t" << GetEmployeeName() << endl;
}

//Resets m_ptrEmployee to a NULL value for an instance of Schedule class.
void Schedule::Reset()
{
	m_ptrEmployee = NULL;
}

//Checks to see if an employee has been assigned to m_ptrEmployee.
//Returns true if m_ptrEmployee is not NULL.
bool Schedule::GetIsSet() const
{
	if (m_ptrEmployee == NULL)
	{
		return false;
	}
	else //employee is set.
	{
		return true;
	}
}