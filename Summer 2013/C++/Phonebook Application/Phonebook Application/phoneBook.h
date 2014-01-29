/*William Freeman
  CS201R
  7/15/2013
  Assignment 4 - Phonebook Application
  Description: Crate a phonebook program that will load in a list of people
  (first name, last name, phone number, and country) from a file, and enter
  them into the system. The user will then be able to view all entries or
  filter by country or last name.
  ----phoneBook.h is the header file for the class PhoneBook----*/
#ifndef _PHONE_BOOK
#define _PHONE_BOOK
#include <string>

#include "list.h"
#include "phoneNumber.h"

using std::string;

class PhoneBook
{
public:
	//Reads through filename and assigns appropriate values for variables
	//for m_listPhoneNumbers and m_listCountries.
	void ReadFile(const string& filename);
	//Outputs all values contained within m_listCountries.
	void OutputAllCountries();
	//Outputs all values contained within m_listPhoneNumbers.
	void OutputAllPhonenumbers();
	//Iterates through m_listPhoneNumbers.
	//Checks if country parameter passed is equal to any PhoneNumber's country.
	//Output the PhoneNumber if equal.
	void OutputPhonenumbersFilter(const string& country);
	//Iterates through m_listPhoneNumbers.
	//Checks if the letter passed as a parameter is equal to the first letter
	//contained within the last name of the person stored in a PhoneNumber.
	//Outputs the PhoneNumber if equal.
	void OutputPhonenumbersFilter(char letter);
private:
	List<PhoneNumber> m_listPhoneNumbers;
	List<string> m_listCountries;
};
#endif