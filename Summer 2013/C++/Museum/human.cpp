/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#include "human.h"

//Default constructor.
//Initalizes 0 values.
Human::Human()
{
	Animal::Setup(0.0,0.0);
	m_ethnic = "";
	m_language = "";
}

//Initalizes member variables to the variables passed as parameters.
void Human::Setup(const string& ethnic, const string& language, double weight, double length)
{
	Animal::Setup(weight, length);
	m_ethnic = ethnic;
	m_language = language;
}

//Returns the value of m_ethnic for an instnace of Human.
string Human::getEthnic() const
{
	return m_ethnic;
}

//Returns the value of m_language for an instance of Human.
string Human::getLanguage() const
{
	return m_language;
}