/*William Freeman
  CS201L
  6/27/2013
  Lab 5-Filesystem Structure
  Description: Create a folder class which contains a pointer that is pointing
  to that folder's parent folder. The user picks a folder and that floder along
  with the folders's parents will be outputted.*/
#include <iostream>
#include <string>

#include "folder.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int NUM_FOLDERS = 7;

int main()
{
	Folder folders[NUM_FOLDERS];
	//Initalize folders
	folders[0].Setup("root", NULL);
	folders[1].Setup("FolderA", &folders[0]);
	folders[2].Setup("FolderB", &folders[0]);
	folders[3].Setup("FolderA-A", &folders[1]);
	folders[4].Setup("FolderB-A", &folders[2]);
	folders[5].Setup("FolderB-B", &folders[2]);
	folders[6].Setup("Folder A-A-A", &folders[3]);

	//Output all folders
	for (int index = 0; index < NUM_FOLDERS; index++)
	{
		cout << index << " folder: " << folders[index].GetName() << endl;
	}

	//User decides what folder to view the path of
	int userChoice;
	do
	{
		cout << "Which folder would you like to view the path of: ";
		cin >> userChoice;
		if (userChoice < 0 || userChoice > 6)
		{
			cout << "Invalid folder selection try again!\n";
		}
	} while (userChoice < 0 || userChoice > 6);

	cout << folders[userChoice].GetName() << endl;

	Folder* currentFolder;
	currentFolder = &folders[userChoice];

	//Step through folder path
	while (currentFolder != NULL)
	{
		cout << currentFolder->GetName() << " < ";
		currentFolder = currentFolder->GetParentFolder();
	}

	cout << endl;
	system("PAUSE");
	return 0;
}