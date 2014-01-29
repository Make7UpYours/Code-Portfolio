/*William Freeman
  CS201R
  6/13/13
  Assignment 1 - Battle Game Port
  Description: Port of a battle game within Python to C++*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

//DELAYLENGTH in miliseconds == 0.5 seconds
const int DELAYLENGTH = 500;

int main()
{
	//Seed the random number generator
	srand(time(NULL));
	cout << "BATTLE GAME!\n";

	bool done = false;
	int combatRound = 0;

	//Player attributes
	int playerHP = 20;
	int playerAtk = rand() % 3 + 5;
	int playerDef = rand() % 3 + 5;
	int playerAgi = rand() % 3 + 5;

	//Enemy attributes
	int enemyHP = 20;
	int enemyAtk = rand() % 2 + 5;
	int enemyDef = rand() % 2 + 5;
	int enemyAgi = rand() % 2 + 5;

	cout << "\n-------------\n"
		 << "FIGHTER STATS\n"
		 << "-------------\n";

	cout << "\nPLAYER STATS:\n"
		 << "HP " << playerHP << endl
		 << "ATK " << playerAtk << endl
		 << "DEF " << playerDef << endl
		 << "AGI " << playerAgi << endl;

	cout << "\nENEMY STATS:\n"
		 << "HP " << enemyHP << endl
		 << "ATK " << enemyAtk << endl
		 << "DEF " << enemyDef << endl
		 << "AGI " << enemyAgi << endl;

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
		cout << "\n###########################################\n"
			 << "-------------------------------------------\n"
			 << "ROUND " << combatRound << endl
			 << "PLAYER:\t HP " << playerHP << " ATK " << playerAtk
			 << " DEF " << playerDef << " AGI " << playerAgi << endl
             << "ENEMY:\t HP " << enemyHP << " ATK " << enemyAtk
			 << " DEF " << enemyDef << " AGI " << enemyAgi << endl
			 << "-------------------------------------------\n"
			 << "1. Quick Attack\n"
			 << "2. Standard Attack\n"
			 << "3. Heavy Attack\n"
			 << "What will you do? ";
		int playerChoice;
		cin >> playerChoice;

		//Ensure the player enters a proper selection
		while(playerChoice < 1 || playerChoice > 3)
		{
			cout << "Invalid choice, choose between 1 and 3: ";
			cin >> playerChoice;
		}
		
		int enemyChoice = rand() % 3 + 1;
		cout << "Enemy chooses option " << enemyChoice << endl
		     << "-------------------------------------------\n";

		//Adjust player and enemy stats based upon the type of attack they have chosen
		int adjustedPlayerAtk = playerAtk;
		int adjustedPlayerAgi = playerAgi;

		int adjustedEnemyAtk = enemyAtk;
		int adjustedEnemyAgi = enemyAgi;

		switch(playerChoice)
		{
		case 1:
			{
				adjustedPlayerAgi += 2;
				adjustedPlayerAtk -= 1;
				break;
			}
		case 2:
			//Do nothing
			break;
		case 3:
			{
				adjustedPlayerAgi -= 1;
				adjustedPlayerAtk += 2;
				break;
			}
		}

		switch(enemyChoice)
		{
		case 1:
			{
				adjustedEnemyAgi += 2;
				adjustedEnemyAtk -= 1;
				break;
			}
		case 2:
			//Do nothing
			break;
		case 3:
			{
				adjustedEnemyAgi -= 1;
				adjustedEnemyAtk += 2;
				break;
			}
		}
		
		//Begin battle
		cout << "PLAYER attacks ENEMY!\n";
		Sleep(DELAYLENGTH);
		
		int randDiff = rand() % adjustedPlayerAgi;
		Sleep(DELAYLENGTH);

		if (randDiff >= 1)
		{
			//Calculate damage
			int damage = (adjustedPlayerAtk - enemyDef / 2);
			cout << "PLAYER hits ENEMY for " << damage << " damage!\n";
			enemyHP -= damage;
		}
		else
			cout << "PLAYER misses!\n";

		Sleep(DELAYLENGTH);

		cout << "ENEMY attacks PLAYER!\n";
		Sleep(DELAYLENGTH);

		randDiff = rand() % adjustedEnemyAgi;
		Sleep(DELAYLENGTH);

		if (randDiff >=1)
		{
			//Caculate damage
			int damage = (adjustedEnemyAtk - playerDef / 2);
			cout << "ENEMY hits PLAYER for " << damage << " damage!\n";
			playerHP -= damage;
		}
		else
			cout << "ENEMEY misses!\n";
		
		Sleep(DELAYLENGTH);

		//Check to see if either player is knocked out
		if (playerHP <= 0)
		{
			cout << "PLAYER has fallen!\n";
			done = true;
		}
		else if (enemyHP <= 0)
		{
			cout << "ENEMY has fallen!\n";
			done = true;
		}
	}

	//At this point either player or enemy has fallen.
	cout << "\n    #####################################   \n"
	     << " ####                                   ####\n"
	     << "#           G A M E     O V E R             #\n"
		 << "# ######################################### #\n"
		 << "##                                         ##\n";

	if (playerHP <= 0)
		cout << "Too bad, you lose!\n";
	else
		cout << "Congratulations, you won!\n";
	
	return 0;
}
