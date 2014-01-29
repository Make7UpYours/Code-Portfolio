/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#ifndef _ANIMAL
#define _ANIMAL

class Animal
{
public:
	//Default constructor.
	//Initalizes 0 values.
	Animal();
	//Initalizes the member variables to the parameter values passed through func.
	void Setup(double weight, double length);
	//Returns m_weight for an instance of Animal
	double getWeight() const;
	//Returns m_length for an instance of Animal
	double getLength() const;
private:
	double m_weight;
	double m_length;
};
#endif