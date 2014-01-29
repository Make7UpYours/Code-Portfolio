/*william Freeman
  CS201L
  7/16/2013
  Lab Assignment 9 - Animal Polymorphism
  Description: Create an Animal class along with classes: Human, Bird, and Dog.
  Each one inheriting from Animal using virtual functions and Polymorphism.*/
#include <string>

#include "animal.h"
#include "bird.h"
#include "dog.h"
#include "human.h"

using std::string;

int main()
{
	//Exercise 1
	Animal* ptrAnimal;
	string species = "Human";
	Human human(species);
	ptrAnimal = &human;
	ptrAnimal->Action();
	
	species = "Dog";
	Dog dog(species);
	ptrAnimal = &dog;
	ptrAnimal->Action();

	species = "Bird";
	Bird bird(species);
	ptrAnimal = &bird;
	ptrAnimal->Action();
	/*The function call outputs a different result each time because of inheritance
	and polymorphism. An Dog, Human, and Bird are all Animals. Therefore according
	to the rules of both inheritance and polymorphism, an Animal pointer can point
	to any of its children and access their member functions.*/
	
	//Exercise 2
	/*Animal animal;
	Making Action a pure virtual functions within the class Animal, makes
	Animal an abstracct class. You cannot use an abstract class for anything
	except for inheritance from child classes for functions and variables.
	When you attempt to create an abstract class the compiler generates
	and error.*/

	//Exercise 3
	species = "Animal";
	Animal animal(species);
	ptrAnimal = &animal;
	Human* ptrHuman = &human;
	Dog* ptrDog = &dog;

	ptrAnimal = dynamic_cast<Human*>(ptrHuman);
	ptrAnimal->Action();

	/*ptrHuman = dynamic_cast<Animal*>(ptrAnimal);
	ptrHuman->Action();
	This portion will cause an error, because you cannot use dynamic casting
	to go from the derived class to the base class. But you can use dynamic
	casting to go from the base class to the derived class. This is a similar
	process that was used to point to children class in Exercise 1.*/

	ptrAnimal = &animal;

	ptrAnimal = static_cast<Human*>(ptrHuman);
	ptrAnimal->Action();

	/*ptrHuman = static_cast<Animal*>(ptrAnimal);
	ptrHuman->Action();
	Static casting also will not allow a derived class to be converted to its
	base class.*/

	ptrAnimal = &animal;

	ptrAnimal = reinterpret_cast<Human*>(ptrHuman);
	ptrAnimal->Action();

	/*ptrHuman = reinterpret_cast<Animal*>(ptrAnimal);
	ptrHuman->Action();

	ptrHuman = reinterpret_cast<Dog*>(ptrDog);
	ptrHuman->Action();
	Neither of these sections of code will work with the compiler. You cannot
	use casting to go from a derived class to a base class at all. Also 
	attempting to go from one child class to another sibling class is not 
	allowed either.
	According to slides this should work, But VS2012 is throwing a compiler
	error when using reinterpret_cast and going from Human* to Dog*.*/

	//Warm Up
	/*Animal animal;
	Bird bird;
	Human human;
	Dog dog;

	animal.Action();
	human.Action();
	dog.Action();
	bird.Action();*/

	return 0;
}