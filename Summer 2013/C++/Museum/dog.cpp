/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#include "dog.h"

//Default constructor.
//Initalizes 0 values.
Dog::Dog()
{
	Animal::Setup(0.0,0.0);
	m_breed = "";
	m_lifeSpan = 0.0;
}

//Initalizes member variables to variables passed as parameters.
void Dog::Setup(const string& breed, double lifeSpan, double weight, double length)
{
	Animal::Setup(weight, length);
	m_breed = breed;
	m_lifeSpan = lifeSpan;
}
//Retuns the value of m_breed.
string Dog::getBreed() const
{
	return m_breed;
}

//Returns the value of m_lifeSpan.
double Dog::getLifeSpan() const
{
	return m_lifeSpan;
}