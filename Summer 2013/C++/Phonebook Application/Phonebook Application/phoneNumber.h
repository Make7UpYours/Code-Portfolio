/*William Freeman
  CS201R
  7/15/2013
  Assignment 4 - Phonebook Application
  Description: Crate a phonebook program that will load in a list of people
  (first name, last name, phone number, and country) from a file, and enter
  them into the system. The user will then be able to view all entries or
  filter by country or last name.
  ----phoneNumber.h is the header file for the class PhoneNumber----*/
#ifndef _PHONE_NUMBER
#define _PHONE_NUMBER
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class PhoneNumber
{
public:
	friend class PhoneBook;

	//Default contstructor.
	//Initalizes default values for member variables.
	PhoneNumber();
	//Constructor.
	//Calls the Setup function using the variables passed as parameters.
	PhoneNumber(const string& first, const string& last, const string& phone,
				const string& country);
	//Initalizes member variables to the parameter variables passed.
	void Setup(const string& first, const string& last, const string& phone,
				const string& country);
	//Compares member variables for item1 and item2.
    //Returns true if all member variables are the same, false otherwise.
	friend bool operator==(const PhoneNumber& item1, const PhoneNumber& item2);
	//Overloads << operator.
	//Outputs all member variables for an instance of PhoneNumber.
	friend ostream& operator<<(ostream& out, PhoneNumber& item);
private:
	string m_firstName;
	string m_lastName;
	string m_phoneNumber;
	string m_country;
};
#endif