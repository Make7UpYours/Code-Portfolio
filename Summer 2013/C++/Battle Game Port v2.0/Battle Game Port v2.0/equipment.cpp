/*William Freeman
CS201R
6/24/13
Assignment 2 - Battle Game Port v2.0
Description: Port of a battle game within Python to C++, now including
equipment and uses classes.
---equipment.cpp is the implementation file for the Equipment class---*/
#include "equipment.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

//Default constructor - sets 0 values
Equipment::Equipment()
{
	Name = "";
	Atk = 0;
	Def = 0;
	Agi = 0;
}

//Initalizes all the values for an instance of Equipment
void Equipment::setup(string equipName, int atk, int def, int agi)
{
	Name = equipName;
	Atk = atk;
	Def = def;
	Agi = agi;
}

//Prints the info for the stats of an instance of Equipment
void Equipment::printInfo() const
{
	cout << Name << ":  ATK: " << Atk << "  DEF: " << Def << "  AGI: " << Agi
		<< endl;
}

//Returns the value of Name for an instance of Equipment
string Equipment::getName()
{
	return Name;
}

//Returns the value of Atk for an instance of Equipment
int Equipment::getAtk()
{
	return Atk;
}

//Returns the value of Def for an instance of Equipment
int Equipment::getDef()
{
	return Def;
}

//Returns the value of Agi for an instance of Equipment
int Equipment::getAgi()
{
	return Agi;
}