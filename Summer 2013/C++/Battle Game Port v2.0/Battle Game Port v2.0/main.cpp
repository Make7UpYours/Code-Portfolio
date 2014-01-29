/*William Freeman
CS201R
6/24/13
Assignment 2 - Battle Game Port v2.0
Description: Port of a battle game within Python to C++, now including
equipment and uses classes.*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //used for Windows
//#include <unistd.h> //used for linux & mac

#include "characcter.h"
#include "equipment.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int setPlayerAttributes(Character& player, Equipment equipment[]);
//Sets the player's attributes for the game. Asks user for their name, which
//will be used for their player name.
//Returns the index for the player equipment array.

int setEnemyAttributes(Character& enemy, Equipment equipment[]);
//Sets the enemy's attributes for the game based upon the equipment the 
//enemy selects.
//User picks from a list of enemy names to battle with.
//Returns the index for the enemy equipment array.

void initialStatsDisplay(Character& character);
//Displays all the stats for character for the start of the game.

void attack(Character& attacker, Character& defender);
//Calculates the damage that an attacker will do upon the defender, ouputs to
//the screen and adjusts the HP of the defender.
//Unless attacker misses based upon their adjusted stats.

void displayEquipment(Equipment equipment[]);
//Displays the user's choice's for equipment.

void statsAndAtkOutput(int combatRound, Character& player, Character& enemy,
					   Equipment equipment[], int playerEquipIdx,
					   int enemyEquipIdx);
//Displays the current combat round and the stats of both the player and enemy.
//Outputs the user's choices for attacks.

void adjustStats(Character& character, int atkChoice);
//Adjusts the character's stats based upon their atkChoice.

//DELAYLENGTH in miliseconds == 0.5 seconds
const int DELAYLENGTH = 500;
const int STARTING_HP = 20;
const int NUM_EQUIPMENT = 3;

int main()
{
	//Seed the random number generator
	srand(time(NULL));
	cout << "BATTLE GAME!\n";

	bool done = false;
	int combatRound = 0;
	//Initalize equipment
	Equipment equipment[NUM_EQUIPMENT];
	equipment[0].setup("Knight's Pack", 8, 4, 3);
	equipment[1].setup("Tank's Pack", 4, 8, 3);
	equipment[2].setup("Rogue's Pack", 4, 3, 8);

	Character player, enemy;
	int playerEquipIndex, enemyEquipIndex;
	//Player attributes
	playerEquipIndex = setPlayerAttributes(player, equipment);
	//Enemy attributes
	enemyEquipIndex = setEnemyAttributes(enemy, equipment);

	//Display starting stats
	cout << "\n-------------\n"
		<< "FIGHTER STATS\n"
		<< "-------------\n";
	initialStatsDisplay(player);
	initialStatsDisplay(enemy);

	//Ask user if they would like to start the game
	string choice = "no";
	cout << "Ready to begin? (yes/no) ";
	cin >> choice;
	while(choice != "yes")
	{
		cout << "Well, what are you waiting for?\n";
		cout << "Ready to begin? (yes/no) ";
		cin >> choice;
	}

	//main game loop
	while(done == false)
	{
		combatRound ++;
		//Start Atack
		statsAndAtkOutput(combatRound, player, enemy, equipment, playerEquipIndex,
			enemyEquipIndex);
		int playerChoice;
		cin >> playerChoice;
	//Ensure the player enters a proper selection
		while(playerChoice < 1 || playerChoice > 3)
		{
			cout << "Invalid choice, choose between 1 and 3: ";
			cin >> playerChoice;
		}
		int enemyChoice = rand() % 3 + 1;
		cout << enemy.getName() <<" chooses option " << enemyChoice << endl
			 << "-------------------------------------------\n";
		Sleep(DELAYLENGTH); //Windows
		//usleep(DELAYLENGTH); //Linux & mac

		//Adjust player and enemy stats based upon the type of attack they have chosen
		player.setAdjustedAtk(player.getAtk());
		player.setAdjustedAgi(player.getAgi());
		enemy.setAdjustedAtk(enemy.getAtk());
		enemy.setAdjustedAgi(enemy.getAgi());
		adjustStats(player, playerChoice);
		adjustStats(enemy, enemyChoice);

		//Begin battle
		//Player attacks first
		attack(player, enemy);

		Sleep(DELAYLENGTH); //Windows
		//usleep(DELAYLENGTH); //Linux & mac

		//Enemy attacksS
		attack(enemy, player);

		Sleep(DELAYLENGTH); //Windows
		//usleep(DELAYLENGTH); //Linux & mac

		//Check to see if either player is knocked out
		if (player.getHP() <= 0)
		{
			cout << player.getName() << " has fallen!\n";
			done = true;
		}
		else if (enemy.getHP() <= 0)
		{
			cout << enemy.getName() << " has fallen!\n";
			done = true;
		}
	}

	//At this point either player or enemy has fallen.
	cout << "\n    #####################################   \n"
		<< " ####                                   ####\n"
		<< "#           G A M E     O V E R             #\n"
		<< "# ######################################### #\n"
		<< "##                                         ##\n";

	if (player.getHP() <= 0)
		cout << "Too bad, you lose!\n";
	else
		cout << "Congratulations, you won!\n";

	return 0;
}

int setPlayerAttributes(Character& player, Equipment equipment[])
{
	string name;
	cout << "Type your character's name: ";
	cin >> name;

	//User picks their equipment
	int equipChoice;
	displayEquipment(equipment);
	cin >> equipChoice;
	//subtract 1, due to array indexing
	equipChoice--;

	player.setName(name);
	player.setHP(STARTING_HP);
	player.setAtk(equipment[equipChoice].getAtk());
	player.setDef(equipment[equipChoice].getDef());
	player.setAgi(equipment[equipChoice].getAgi());
	return equipChoice;
}

int setEnemyAttributes(Character& enemy, Equipment equipment[])
{
	string name;
	int choice;
	cout << "Choose your opponent:\n"
		<< "1. Vickerson\n"
		<< "2. Oppi\n"
		<< "3. Valkyrie\n"
		<< "4. Garrosh\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		{
			enemy.setName("Vickerson");
			break;
		}
	case 2:
		{
			enemy.setName("Oppi");
			break;
		}
	case 3:
		{
			enemy.setName("Valkrie");
			break;
		}
	case 4:
		{
			enemy.setName("Garrosh");
			break;
		}
	default:
		{
			cout << "Well it appears you cannot follow a simple task of "
				<< "choosing a number!\n"
				<< "Therefore you get to fight \"Ducky\"!\n";
			enemy.setName("Ducky");
		}
	}

	cout << enemy.getName() << " is selecting their equipment...\n";
	Sleep(DELAYLENGTH); //Windows
	//usleep(DELAYLENGTH); //Linux & mac

	int equipChoice;
	equipChoice = rand() % 3;
	cout << enemy.getName() << " selects " << equipment[equipChoice].getName()
		<< " as their equipment.\n";
	Sleep(DELAYLENGTH); //Windows
	//usleep(DELAYLENGTH); //Linux & mac

	enemy.setHP(STARTING_HP);
	enemy.setAtk(equipment[equipChoice].getAtk());
	enemy.setDef(equipment[equipChoice].getDef());
	enemy.setAgi(equipment[equipChoice].getAgi());
	return equipChoice;
}

void initialStatsDisplay(Character& character)
{
	cout << endl
		<< character.getName() << "'s stats:\n"
		<< "HP " << character.getHP() << endl
		<< "ATK " << character.getAtk() << endl
		<< "DEF " << character.getDef() << endl
		<< "AGI " << character.getAgi() << endl;
}

void attack(Character& attacker, Character& defender)
{
	cout << attacker.getName() << " attacks " << defender.getName() << endl;
	Sleep(DELAYLENGTH); //Windows
	//usleep(DELAYLENGTH); //Linux & mac

	int randDiff = rand() % attacker.getAdjustedAgi();
	Sleep(DELAYLENGTH); //Windows
	//usleep(DELAYLENGTH); //Linux & mac

	if (randDiff >= 1)
	{
		//Calculate damage for the attacker
		int damage;
		damage = (attacker.getAdjustedAtk() - defender.getDef() / 2);
		cout << attacker.getName() << " hits " << defender.getName() 
			<< " for " << damage << " damage!\n";
		defender.setHP(defender.getHP() - damage);
	}
	else
		cout << attacker.getName() << " misses!\n";
}

void displayEquipment(Equipment equipment[])
{
	cout << "Select your equipment:\n";
	for (int index = 0; index < NUM_EQUIPMENT; index++)
	{
		cout << index + 1 << ". ";
		equipment[index].printInfo();

	}
}

void statsAndAtkOutput(int combatRound, Character& player, Character& enemy,
					   Equipment equipment[], int playerEquipIdx,
					   int enemyEquipIdx)
{
	cout << "\n###########################################\n"
		<< "-------------------------------------------\n"
		<< "ROUND " << combatRound << endl
		<< player.getName() << "(" << equipment[playerEquipIdx].getName() 
		<< "):  HP " << player.getHP() 
		<< " ATK " << player.getAtk() << " DEF " << player.getDef() 
		<< " AGI " << player.getAgi() << endl
		<< enemy.getName() << "(" << equipment[enemyEquipIdx].getName()
		<< "):  HP " << enemy.getHP() << " ATK " 
		<< enemy.getAtk() << " DEF " << enemy.getDef() << " AGI " 
		<< enemy.getAgi() << endl
		<< "-------------------------------------------\n"
		<< "1. Quick Attack\n"
		<< "2. Standard Attack\n"
		<< "3. Heavy Attack\n"
		<< "What will you do? ";
}

void adjustStats(Character& character, int atkChoice)
{
	switch(atkChoice)
	{
	case 1:
		{
			character.setAdjustedAgi(character.getAdjustedAgi() + 2);
			character.setAdjustedAtk(character.getAdjustedAtk() - 1);
			break;
		}
	case 2:
		//Do nothing
		break;
	case 3:
		{
			character.setAdjustedAgi(character.getAdjustedAgi() - 1);
			character.setAdjustedAtk(character.getAdjustedAtk() + 2);
			break;
		}
	}
}