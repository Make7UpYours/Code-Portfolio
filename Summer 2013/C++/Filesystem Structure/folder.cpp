/*William Freeman
  CS201L
  6/27/2013
  Lab 5-Filesystem Structure
  Description: Create a folder class which contains a pointer that is pointing
  to that folder's parent folder. The user picks a folder and that floder along
  with the folders's parents will be outputted.*/
#include <string>

#include "folder.h"

using std::string;

//Default constructor
Folder::Folder()
{
	m_name = "uninitalized";
	m_ptrParentFolder = NULL;
}

//Initalizes values for member variables
void Folder::Setup(const string& name, Folder* ptrParentFolder)
{
	m_name = name;
	m_ptrParentFolder = ptrParentFolder;
}

//Returns m_ptrParentFolder for an instance of Folder class
Folder* Folder::GetParentFolder()
{
	return m_ptrParentFolder;
}

//Returns m_name
string Folder::GetName()
{
	return m_name;
}