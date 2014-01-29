/*William Freeman
  CS201R
  7/15/2013
  Assignment 4 - Phonebook Application
  Description: Crate a phonebook program that will load in a list of people
  (first name, last name, phone number, and country) from a file, and enter
  them into the system. The user will then be able to view all entries or
  filter by country or last name.*/
#include <iostream>
#include <string>

#include "list.h"
#include "phoneNumber.h"
#include "phoneBook.h"

using std::cout;
using std::string;
using std::cin;

enum MenuOptions{QUIT, VIEW_ALL_ENTRIES, FILTER_BY_COUNTRY, FILTER_BY_LETTER};

int menu();
//Outputs a menu with options that the user will choose from.
//Returns the menu selection made by the user.

void menuSelection(int choice, PhoneBook& phoneBook);
//Calls the correct function for the menu selection made by the user.

int main()
{
	PhoneBook phoneBook;
	phoneBook.ReadFile("numbers.txt");
	int menuChoice;
	do
	{
		menuChoice = menu();
		menuSelection(menuChoice, phoneBook);
	} while (menuChoice != QUIT);
	return 0;
}

int menu()
{
	int choice;
	cout << VIEW_ALL_ENTRIES << ". View all entries\n"
		 << FILTER_BY_COUNTRY << ". Filter by Country\n"
		 << FILTER_BY_LETTER << ". Filter by letter\n"
		 << QUIT << ". Quit\n"
		 << "Enter menu selection: ";
	cin >> choice;
	return choice;
}

void menuSelection(int choice, PhoneBook& phoneBook)
{
	switch(choice)
	{
	case VIEW_ALL_ENTRIES:
		{
			cout << endl << "------------\n"
				 << "ALL ENTRIES:\n"
				 << "------------\n\n";
			phoneBook.OutputAllPhonenumbers();
			break;
		}
	case FILTER_BY_COUNTRY:
		{
			string country;
			cout << endl << "------------------\n"
				 << "FILTER BY COUNTRY:\n"
				 << "------------------\n\n";
			phoneBook.OutputAllCountries();
			//Prompt for a country name to filter by.
			cout << "\nEnter a country name (case-sensitive): ";
			cin >> country;
			cout << "\nResidents of the country: " << country << endl << endl;
			phoneBook.OutputPhonenumbersFilter(country);
			break;
		}
	case FILTER_BY_LETTER:
		{
			char letter;
			cout << endl << "-----------------\n"
				 << "FILTER BY LETTER:\n"
				 << "-----------------\n\n"
				 << "Enter a letter (capital) to filter by: ";
			cin >> letter;
			cout << "\nPeople whose last name starts with " << letter << endl << endl;
			phoneBook.OutputPhonenumbersFilter(letter);
			break;
		}
	case QUIT:
		{
			cout << endl << "Thanks for using the Phonebook Application!\n";
			break;
		}
	default:
		{
			cout << endl << "Invalid menu selection try again\n\n";
		}
	}
}