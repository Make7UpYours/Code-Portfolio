/*william Freeman
  CS201L
  7/16/2013
  Lab Assignment 9 - Animal Polymorphism
  Description: Create an Animal class along with classes: Human, Bird, and Dog.
  Each one inheriting from Animal using virtual functions and Polymorphism.*/
#include <iostream>

#include "human.h"

using std::cout;

//Constructor.
//Initalizes m_speciesName to the value passed in the parameter.
Human::Human(string& speciesName)
{
	m_speciesName = speciesName;
}

//Outputs an appropriate response based upon the class type.
void Human::Action()
{
	cout << "I can walk, run and tame other animals.\n";
}