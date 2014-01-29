/*william Freeman
  CS201L
  7/16/2013
  Lab Assignment 9 - Animal Polymorphism
  Description: Create an Animal class along with classes: Human, Bird, and Dog.
  Each one inheriting from Animal using virtual functions and Polymorphism.*/
#include <iostream>

#include "animal.h"

using std::cout;

//Default constructor.
//Initalizes default values.
Animal::Animal()
{
	m_speciesName = "Animal";
}

//Constructor.
//Initalizes m_speciesName to the value passed in the parameter.
Animal::Animal(string& speciesName)
{
	m_speciesName = speciesName;
}

//Outputs an appropriate response based upon the class type.
void Animal::Action()
{
	cout << "I am a living thing.\n";
}