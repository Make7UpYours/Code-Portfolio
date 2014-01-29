/*William Freeman
  CS201R
  7/21/2013
  Assignment 5 - Recipe Program
  Description: Create a program using STL vector class. The program will contain
  a recipe menu which the user will be able to add recipes and export recipes.*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::getline;
using std::ofstream;

enum MenuOptions{ADD_RECIPE = 1, EXPORT_RECIPE, QUIT};

int DisplayMenu();
//Displays the main menu, giving choices that the user may select from.
//Returns the user's menu choice.
void AddRecipe(map<string, vector<string> >& recipes);
//Prompts the user to enter the name of the recipe, followed by the ingredients.
//Stores the name of hte recipe as the key, and the ingredients as the values
//for the map recipes.
void ExportRecipes(map<string, vector<string> >& recipes);

int main () 
{
	map<string, vector<string> > recipes;
	int menuChoice;
	
	do
	{
		menuChoice = DisplayMenu();

		switch (menuChoice)
		{
		case ADD_RECIPE:
			{
				AddRecipe(recipes);
				break;
			}
		case EXPORT_RECIPE:
			{
				ExportRecipes(recipes);
				break;
			}
		case QUIT:
			{
				cout << "\nEnjoy your recipes!\n";
			}
		}
	} while(menuChoice != QUIT);
    
	return 0;
}

int DisplayMenu()
{
	int choice;
	do
	{
		cout << "---------\n"
			 << "MAIN MENU\n"
			 << "---------\n\n"
			 << ADD_RECIPE << ". Add new recipe\n\n"
			 << EXPORT_RECIPE << ". Export recipes\n\n"
			 << QUIT << ". Quit\n\n"
			 << "Selection: ";
		cin >> choice;
		if (choice < ADD_RECIPE || choice > QUIT)
		{
			cout << "\nInvalid menu selection. Try again.\n\n";
		}
		//Prevent the user from making improper menu selection.
	} while (choice < ADD_RECIPE || choice > QUIT);
	return choice;
}

void AddRecipe(map<string, vector<string> >& recipes)
{
	string name, ingredient, garbage;

	//Clear cin.
	//Fixes a bug where getline was assiging empty strings with no user input
	//to name & ingredient.
	getline(cin, garbage, '\n'); 

	cout << "\n----------\n"
		 << "ADD RECIPE\n"
		 << "----------\n\n"
		 << "Enter the name for the recipe: ";
	getline(cin, name, '\n');
	cout << endl;

	do
	{
		cout << "Enter ingredient and amount, E.G. \"1 cup flour\"\n"
			 << "or type \"done\" when done.\n";
		getline(cin, ingredient, '\n');
		if (ingredient != "done")
		{
			//Add to the map.
			recipes[name].push_back(ingredient);
			cout << "\nAdded \"" << ingredient << "\".\n\n";
		}
	} while (ingredient != "done");

	cout << endl;
}

void ExportRecipes(map<string, vector<string> >& recipes)
{
	//Force user to add recipes before being able to export an empty recipe list.
	if (recipes.empty())
	{
		cout << "\nThere are no recipes to export currently.\n"
			 << "Add some recipes in order to export.\n\n";
		return;
	}

	ofstream outFile;
	outFile.open("Recipes.txt");
	//Iterate through the map.
	for (map<string, vector<string> >::iterator recipe = recipes.begin();
		recipe != recipes.end(); recipe++)
	{
		outFile << recipe->first << endl;
		//Iterate through the vector contained within the map.
		for (vector<string>::iterator ingredient = recipe->second.begin();
			ingredient != recipe->second.end(); ingredient++)
		{
			outFile << "\t+ " << *ingredient << endl;
		}
		outFile << endl << endl;
	}
	cout << "\nExported recipes to \"Recipes.txt\".\n\n";
	outFile.close();
}