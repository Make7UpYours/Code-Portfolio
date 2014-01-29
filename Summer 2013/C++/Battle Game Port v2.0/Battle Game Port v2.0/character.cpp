/*William Freeman
  CS201R
  6/24/13
  Assignment 2 - Battle Game Port v2.0
  Description: Port of a battle game within Python to C++, now including
  equipment and uses classes.
  ---character.cpp is the implementation file for the Character class---*/
#include "characcter.h"

#include <string>



using std::string;

//default constructor
Character::Character()
{
	Name = "";
	HP = 999999999;
	Atk = 0;
	Def = 0;
	Agi = 0;
	adjustedAgi = 0;
	adjustedAtk = 0;
}

//Allows user to set Character HP
void Character::setHP(int hp)
{
	HP = hp;
}

//Allows user to set Character Name
void Character::setName(string name)
{
	Name = name;
}

//Allows user to set Characcter Atk
void Character::setAtk(int atk)
{
	Atk = atk;
}

//Allows user to set Character Def
void Character::setDef(int def)
{
	Def = def;
}

//Allows user to set Characer Agi
void Character::setAgi(int agi)
{
	Agi = agi;
}

//Allows user to set Character adjustedAgi
void Character::setAdjustedAgi(int adjAgi)
{
	adjustedAgi = adjAgi;
}

//Allows user to set Character adjustedAtk;
void Character::setAdjustedAtk(int adjAtk)
{
	adjustedAtk = adjAtk;
}

//Returns the Character's name
string Character::getName() const
{
	return Name;
}

//Returns the Character's HP
int Character::getHP() const
{
	return HP;
}

//Returns the Character's Atk
int Character::getAtk() const
{
	return Atk;
}

//Retruns the Character's Def
int Character::getDef() const
{
	return Def;
}

//Returns the Character's Agi
int Character::getAgi() const
{
	return Agi;
}

//Returns the Character's adjustedAgi
int Character::getAdjustedAgi() const
{
	return adjustedAgi;
}

//Returns the Character's adjustedAtk
int Character::getAdjustedAtk() const
{
	return adjustedAtk;
}