/*William Freeman
  CS201L
  7/18/2013
  Lab Assignment 10 - MyList Template
  Description: Create your own list template with functionality and test within
  the main function.*/
#include <iostream>
#include <string>

#include "myList.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	//Exercise 2
	MyList<string> names(2);
	names.add("Jack");
	names.add("Mary");
	names.add("John");
	names.add("Robert");
	names.add("Catherine");
	string name;
	name = names.get(4);
	cout << name << endl;
	names.remove(2);
	name = names.get(2);
	cout << name << endl;
	return 0;
}