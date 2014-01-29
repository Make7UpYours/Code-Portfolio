/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --employee.h is the header file for the Employee class--*/
#ifndef _EMPLOYEE
#define _EMPLOYEE
#include <string>

using std::string;

class Employee
{
public:
	//Default constructor.
	//Initalizes 0 values.
	Employee();
	//Setup function.
	//Initalizes parameters for an instance of Employee class.
	void Setup(const string& first, const string& last, float pay);
	//Returns the concatenated full name of an instance of Employee class.
	string GetName() const;
	//Returns m_activeEmployee for an instance of Employee class.
	bool GetIsActive() const;
	//Sets m_activeEmployee to false for an instance of Employee class.
	void LayOff();
	//Outputs all information for an instance of Employee class.
	void Output() const;
	//Returns the value of m_payPerHour for an instance of Employee class.
	float GetPay() const;
private:
	string m_firstName;
	string m_lastName;
	float m_payPerHour;
	bool m_activeEmployee;
};
#endif