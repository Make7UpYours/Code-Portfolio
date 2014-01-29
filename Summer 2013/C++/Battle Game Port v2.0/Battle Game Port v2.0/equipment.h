/*William Freeman
  CS201R
  6/24/13
  Assignment 2 - Battle Game Port v2.0
  Description: Port of a battle game within Python to C++, now including
  equipment and uses classes.
  ---equipment.h is the header file for the Equipment class---*/
#ifndef _EQUIPMENT
#define _EQUIPMENT
#include <string>

using std::string;

class Equipment
{
public:
	//Default constructor - sets 0 values
	Equipment();
	//Initalizes all the values for an instance of Equipment
	void setup(string equipName, int atk, int def, int agi);
	//Prints the info for the stats of an instance of Equipment
	void printInfo() const;
	//Returns the value of Name for an instance of Equipment
	string getName();
	//Returns the value of Atk for an instance of Equipment
	int getAtk();
	//Returns the value of Def for an instance of Equipment
	int getDef();
	//Returns the value of Agi for an instance of Equipment
	int getAgi();

private:
	string Name;
	int Atk;
	int Def;
	int Agi;
};
#endif