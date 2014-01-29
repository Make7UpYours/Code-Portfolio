/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#ifndef _BIRD
#define _BIRD
#include <string>

#include "animal.h"

using std::string;

class Bird:public Animal
{
public:
	//Default constructor.
    //Initalizes 0 values.
	Bird();
	//Initalizes member variables to the variables passed as parameters.
	void Setup(string name, bool canFly, const string& foodHabit, double weight, double length);
	//Returns the value of m_canFly for an instance of Bird.
	bool getCanFly() const;
	//Returns the value of m_foodHabit for an instance of Bird.
	string getFoodHabit() const;
	//Returns the value of m_name for an instance of Bird.
	string getName() const;
private:
	string m_name;
	bool m_canFly;
	string m_foodHabit;
};
#endif