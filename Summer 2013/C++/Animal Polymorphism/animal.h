/*william Freeman
  CS201L
  7/16/2013
  Lab Assignment 9 - Animal Polymorphism
  Description: Create an Animal class along with classes: Human, Bird, and Dog.
  Each one inheriting from Animal using virtual functions and Polymorphism.*/
#ifndef _ANIMAL
#define _ANIMAL
#include <string>

using std::string;

class Animal
{
public:
	//Default constructor.
	//Initalizes default values.
	Animal();
	//Constructor.
	//Initalizes m_speciesName to the value passed in the parameter.
	Animal(string& speciesName);
	//Outputs an appropriate response based upon the class type.
	virtual void Action();
	//virtual void Action() = 0;
protected:
	string m_speciesName;
};
#endif