/*William Freeman
  CS201R
  7/23/2013
  Assignment 6 - Card Game
  Description: Create a card game using a Stack implemented with a Linked
  List. The players will pick from a stack of 100 cards and whoever has the
  highest score at the end of the game wins.*/
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "CardStack.h"

using std::cout;
using std::endl;
using std::ofstream;

const int NUM_PLAYERS = 5, NUM_CARDS = 100;

void InitalizeScores(int players[]);
//Initalizes the players' score to 0.
void BuildDeck(CardStack& cards);
//Builds a deck of 100 cards.
void Header(int players[], ofstream& outFile);
//Places a header in outFile.
void DealCards(CardStack& cards, int players[], ofstream& outFile);
//Deals cards to players and adds to their score.
void DetermineWinner(int players[], ofstream& outFile);
//Determines the winner of the game and outputs to outFile.

int main()
{
	srand(time(NULL));
	CardStack cards;
	int players[NUM_PLAYERS];
	ofstream outFile;
	outFile.open("Output.txt");

	InitalizeScores(players);
	BuildDeck(cards);
	Header(players, outFile);

	while (cards.GetSize() != 0)
	{
		DealCards(cards, players, outFile);
	}

	DetermineWinner(players, outFile);

	cout << "Results have been sent to \"Output.txt\"\n";

	outFile.close();

	return 0;
}

void InitalizeScores(int players[])
{
	for (int index = 0; index < NUM_PLAYERS; index++)
	{
		players[index] = 0;
	}
}

void BuildDeck(CardStack& cards)
{
	for (int index = 0; index < NUM_CARDS; index++)
	{
		//Num [2,14].
		cards.Push( rand() % 13 + 2);
	}
}

void Header(int players[], ofstream& outFile)
{
	outFile << "PLAYERS: ";
	for (int index = 0; index < NUM_PLAYERS; index++)
	{
		//Add 1 to player due to array indexing.
		outFile << "\t " << index + 1;
	}

	outFile << "\n-------- ";

	for (int index = 0; index < NUM_PLAYERS; index++)
	{
		outFile << "\t---";
	}
	outFile << endl;
}

void DealCards(CardStack& cards, int players[], ofstream& outFile)
{
	outFile << "  SCORE: ";
	for (int index = 0; index < NUM_PLAYERS; index++)
	{
		players[index] += cards.Top();
		cards.Pop();
		outFile << "\t" << players[index];
	}
	outFile << endl;
}

void DetermineWinner(int players[], ofstream& outFile)
{
	outFile << endl;
	outFile << "---------------------------\n";
	int winner, highScore = 0;
	//Iterate through the players and determine which player has the highest score.
	for (int index = 0; index < NUM_PLAYERS; index++)
	{
		if (players[index] > highScore)
		{
			winner = index;
			highScore = players[index];
		}
	}
	//Add 1 to winner due to array indexing.
	outFile << "The winner is player " << winner + 1 << " with a total of "
			<< players[winner] << " points\n"
			<< "Congrats player " << winner + 1 << "!\n";
}