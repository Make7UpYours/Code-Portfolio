/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#ifndef _DOG
#define _DOG
#include <string>

#include "animal.h"

using std::string;

class Dog:public Animal
{
public:
	//Default constructor.
	//Initalizes 0 values.
	Dog();
	//Initalizes member variables to variables passed as parameters.
	void Setup(const string& breed, double lifeSpan, double weight, double length);
	//Retuns the value of m_breed.
	string getBreed() const;
	//Returns the value of m_lifeSpan.
	double getLifeSpan() const;
private:
	string m_breed;
	double m_lifeSpan;
};
#endif