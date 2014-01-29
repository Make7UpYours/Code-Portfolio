/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --employee.cpp is the implementation file for the Employee class--*/
#include <string>
#include <iostream>

#include "employee.h"

using std::string;
using std::cout;
using std::endl;

//Default constructor.
//Initalizes 0 values for an instance of Employee class.
Employee::Employee()
{
	m_firstName = "";
	m_lastName = "";
	m_payPerHour = 0.0;
	m_activeEmployee = true;
}

//Setup function.
//Initalizes parameters for an instance of Employee class.
void Employee::Setup(const string& first, const string& last, float pay)
{
	m_firstName = first;
	m_lastName = last;
	m_payPerHour = pay;
}

//Returns the concatenated full name of an instance of Employee class.
string Employee::GetName() const
{
	return m_lastName + ", " + m_firstName;
}

//Returns m_activeEmployee for an instance of Employee class.
bool Employee::GetIsActive() const
{
	return m_activeEmployee;
}

//Sets m_activeEmployee to false for an instance of Employee class.
void Employee::LayOff()
{
	m_activeEmployee = false;
}

//Outputs all information for an instance of Employee class.
void Employee::Output() const
{
	cout << "Employee: " << GetName()
		 << " | Pay: $" << m_payPerHour;
	if (m_activeEmployee)
	{
		cout << " | Status: Current\n";
	}
	else
	{
		cout << " | Status: Former\n";
	}
}

//Returns the value of m_payPerHour for an instance of Employee class.
float Employee::GetPay() const
{
	return m_payPerHour;
}