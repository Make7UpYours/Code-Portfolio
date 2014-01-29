/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#include "animal.h"

//Default constructor.
//Initalizes 0 values.
Animal::Animal()
{
	m_weight = 0.0;
	m_length = 0.0;
}

//Initalizes the member variables to the parameter values passed through func.
void Animal::Setup(double weight, double length)
{
	m_weight = weight;
	m_length = length;
}

//Returns m_weight for an instance of Animal
double Animal::getWeight() const
{
	return m_weight;
}

//Returns m_length for an instance of Animal
double Animal::getLength() const
{
	return m_length;
}