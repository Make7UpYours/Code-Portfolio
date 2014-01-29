/*William Freeman
  CS201L
  6/18/2013
  Random Num Game: Create a guessing game using random numbers.
  If the user guesses the number then let them know if not tell them
  the random number.*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void guessGame(int randNum);
//Takes a random number and allows the user to guess the number.
//If the number is correct then lets the user know they are correct
//if not then tells them they are not and gives them the number.

int main()
{
	srand(time(NULL));
	int randomNum = rand() % 20 + 1;
	guessGame(randomNum);
	system("PAUSE");
	return 0;
}

void guessGame(int randNum)
{
	int userGuess;
	do
	{
		cout << "What is your guess(1-20):  ";
		cin >> userGuess;
		if (userGuess > 20 || userGuess < 1)
		{
			cout << "Not a valid guess try again!\n";
		}
	} while (userGuess > 20 || userGuess < 1);
	if (userGuess == randNum)
		cout << "Congrats you guessed the number!\n";
	else
		cout << "Incorrect! The number was: " << randNum << endl;
}
