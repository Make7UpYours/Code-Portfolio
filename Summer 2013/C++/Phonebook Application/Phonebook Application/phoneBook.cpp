/*William Freeman
  CS201R
  7/15/2013
  Assignment 4 - Phonebook Application
  Description: Crate a phonebook program that will load in a list of people
  (first name, last name, phone number, and country) from a file, and enter
  them into the system. The user will then be able to view all entries or
  filter by country or last name.
  ----phoneBook.cpp is the implementation file for the class PhoneBook----*/
#include <fstream>

#include "phoneBook.h"

using std::ifstream;

//Reads through filename and assigns appropriate values for variables
//for m_listPhoneNumbers and m_listCountries.
void PhoneBook::ReadFile(const string& filename)
{
	ifstream inFile;
	inFile.open(filename);
	string first, last, phone, country;
	while (inFile >> first >> last >> phone >> country)
	{
		PhoneNumber tempPhone(first, last, phone, country);
		m_listPhoneNumbers.AddItem(tempPhone);
		m_listCountries.AddItem(country);
	}
	inFile.close();
}

//Outputs all values contained within m_listCountries.
void PhoneBook::OutputAllCountries()
{
	m_listCountries.OutputAll();
}

//Outputs all values contained within m_listPhoneNumbers.
void PhoneBook::OutputAllPhonenumbers()
{
	m_listPhoneNumbers.OutputAll();
}

//Iterates through m_listPhoneNumbers.
//Checks if country parameter passed is equal to any PhoneNumber's country.
//Output the PhoneNumber if equal.
void PhoneBook::OutputPhonenumbersFilter(const string& country)
{
	int size = m_listPhoneNumbers.GetSize();
	for (int index = 0; index < size; index++)
	{
		PhoneNumber item = m_listPhoneNumbers.GetItem(index);
		if (item.m_country == country)
		{
			cout << item << endl;
		}
	}
}

//Iterates through m_listPhoneNumbers.
//Checks if the letter passed as a parameter is equal to the first letter
//contained within the last name of the person stored in a PhoneNumber.
//Outputs the PhoneNumber if equal.
void PhoneBook::OutputPhonenumbersFilter(char letter)
{
	int size = m_listPhoneNumbers.GetSize();
	for (int index = 0; index < size; index++)
	{
		PhoneNumber item = m_listPhoneNumbers.GetItem(index);
		if (item.m_lastName[0] == letter)
		{
			cout << item << endl;
		}
	}
}