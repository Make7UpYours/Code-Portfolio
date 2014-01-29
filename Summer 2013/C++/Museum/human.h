/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#ifndef _HUMAN
#define _HUMAN
#include<string>

#include "animal.h"

using std::string;

class Human: public Animal
{
public:
	//Default constructor.
	//Initalizes 0 values.
	Human();
	//Initalizes member variables to the variables passed as parameters.
	void Setup(const string& ethnic, const string& language, double weight, double length);
	//Returns the value of m_ethnic for an instnace of Human.
	string getEthnic() const;
	//Returns the value of m_language for an instance of Human.
	string getLanguage() const;
private:
	string m_ethnic;
	string m_language;
};
#endif