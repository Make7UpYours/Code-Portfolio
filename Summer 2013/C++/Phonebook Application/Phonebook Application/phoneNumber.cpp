/*William Freeman
  CS201R
  7/15/2013
  Assignment 4 - Phonebook Application
  Description: Crate a phonebook program that will load in a list of people
  (first name, last name, phone number, and country) from a file, and enter
  them into the system. The user will then be able to view all entries or
  filter by country or last name.
  ----phoneNumber.cpp is the implementation file for the class PhoneNumber----*/
#include "phoneNumber.h"

using std::endl;

//Default contstructor.
//Initalizes default values for member variables.
PhoneNumber::PhoneNumber()
{
	m_firstName = "First";
	m_lastName = "Last";
	m_phoneNumber = "Phone Number";
	m_country = "Country";
}

//Constructor.
//Calls the Setup function using the variables passed as parameters.
PhoneNumber::PhoneNumber(const string& first, const string& last,
						 const string& phone, const string& country)
{
	Setup(first, last, phone, country);
}

//Initalizes member variables to the parameter variables passed.
void PhoneNumber::Setup(const string& first, const string& last, 
						const string& phone, const string& country)
{
	m_firstName = first;
	m_lastName = last;
	m_phoneNumber = phone;
	m_country = country;
}

//Compares member variables for item1 and item2.
//Returns true if all member variables are the same, false otherwise.
bool operator==(const PhoneNumber& item1, const PhoneNumber& item2)
{
	if (item1.m_firstName == item2.m_firstName &&
		item1.m_country == item2.m_country &&
		item1.m_lastName == item2.m_lastName &&
		item1.m_phoneNumber == item2.m_phoneNumber)
	{
		return true;
	}
	return false;
}

//Overloads << operator.
//Outputs all member variables for an instance of PhoneNumber.
ostream& operator<<(ostream& out, PhoneNumber& item)
{
	out << item.m_lastName << endl;
    out << item.m_firstName << endl;
    out << item.m_country << endl;
    out << item.m_phoneNumber << endl;
    return out;
}