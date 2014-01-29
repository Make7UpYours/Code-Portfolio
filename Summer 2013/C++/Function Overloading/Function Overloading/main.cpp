/*William Freeman
  CS201L
  6/18/2013
  Function Overloading: Create a function that will take a person's name in
  segments and outputs the full name.*/
#include <iostream>
#include <string>
using namespace std;

string concatenateName(string first, string last);
//Takes first and last name of individual and returns the full name of 
//that individual.

string concatenateName(string first, string middle, string last);
//Takes the first, middle, and last name of an individual and returns the full
//name of that individual.

string concatenateName(string preHyph, string postHyph, string middle, string last);
//If a person has a hyphenated name this function will take the hyphenated name in parts
//along with the middle and last name and return the full name of the individual

void concatenateName(const int numNames);
//Function takes the number of names that a user has and

int main()
{
	string first = "Josh", last = "Berbin",
			middle = "Franks", postHyph = "Perkins";
	string fullName;
	int num;

	fullName = concatenateName(first, last);
	cout << fullName << endl;
	fullName = concatenateName(first, middle, last);
	cout << fullName << endl;
	fullName = concatenateName(first, postHyph, middle, last);
	cout << fullName << endl;

	cout << "How many names do you have? ";
	cin >> num;
	concatenateName(num);
	system("PAUSE");
	return 0;
}

string concatenateName(string first, string last)
{
	return first + " " + last;
}

string concatenateName(string first, string middle, string last)
{
	return first + " " + middle + " " + last;
}

string concatenateName(string preHyph, string postHyph, string middle, string last)
{
	return preHyph + "-" + postHyph + " " + middle + " " + last;
}

void concatenateName(const int numNames)
{
	string name[15];
	cout << "Enter your names in order:\n";
	for (int index = 0; index < numNames; index++)
	{
		cin >> name[index];
	}
	cout << endl;
	for (int index = 0; index < numNames; index++)
	{
		cout << name[index] << " ";
	}
	cout << endl;
}
