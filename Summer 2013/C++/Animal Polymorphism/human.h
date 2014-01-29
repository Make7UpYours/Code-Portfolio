/*william Freeman
  CS201L
  7/16/2013
  Lab Assignment 9 - Animal Polymorphism
  Description: Create an Animal class along with classes: Human, Bird, and Dog.
  Each one inheriting from Animal using virtual functions and Polymorphism.*/
#ifndef _HUMAN
#define _HUMAN
#include "animal.h"

class Human: public Animal
{
public:
	//Constructor.
	//Initalizes m_speciesName to the value passed in the parameter.
	Human(string& speciesName);
	//Outputs an appropriate response based upon the class type.
	virtual void Action();
};
#endif