/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#include "bird.h"

//Default constructor.
//Initalizes 0 values.
Bird::Bird()
{
	Animal::Setup(0.0,0.0);
	m_name = "";
	m_canFly = false;
	m_foodHabit = "";
}

//Initalizes member variables to the variables passed as parameters.
void Bird::Setup(string name, bool canFly, const string& foodHabit, double weight, double length)
{
	Animal::Setup(weight, length);
	m_name = name;
	m_canFly = canFly;
	m_foodHabit = foodHabit;
}

//Returns the value of m_canFly for an instance of Bird.
bool Bird::getCanFly() const
{
	return m_canFly;
}

//Returns the value of m_foodHabit for an instance of Bird.
string Bird::getFoodHabit() const
{
	return m_foodHabit;
}


//Returns the value of m_name for an instance of Bird.
string Bird::getName() const
{
	return m_name;
}