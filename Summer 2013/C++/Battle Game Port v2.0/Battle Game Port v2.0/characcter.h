/*William Freeman
  CS201R
  6/24/13
  Assignment 2 - Battle Game Port v2.0
  Description: Port of a battle game within Python to C++, now including
  equipment and uses classes.
  ---character.h is the header file for the Character class---*/
#ifndef _CHARACTER
#define _CHARACTER
#include <string>

using std::string;

class Character
{
public:
	//default constructor
	Character();
	//Allows user to set Character HP
	void setHP(int hp);
	//Allows user to set Character Name
	void setName(string name);
	//Allows user to set Characcter Atk
	void setAtk(int atk);
	//Allows user to set Character Def
	void setDef(int def);
	//Allows user to set Characer Agi
	void setAgi(int agi);
	//Allows user to set Character adjustedAgi
	void setAdjustedAgi(int adjAgi);
	//Allows user to set Character adjustedAtk;
	void setAdjustedAtk(int adjAtk);
	//Returns the Character's name
	string getName() const;
	//Returns the Character's HP
	int getHP() const;
	//Returns the Character's Atk
	int getAtk() const;
	//Retruns the Character's Def
	int getDef() const;
	//Returns the Character's Agi
	int getAgi() const;
	//Returns the Character's adjustedAgi
	int getAdjustedAgi() const;
	//Returns the Character's adjustedAtk
	int getAdjustedAtk() const;
private:
	string Name;
	int HP;
	int Atk;
	int Def;
	int Agi;
	int adjustedAgi;
	int adjustedAtk;
};
#endif