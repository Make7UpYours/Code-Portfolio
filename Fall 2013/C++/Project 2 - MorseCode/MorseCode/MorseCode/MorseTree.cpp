/*William Freeman, Andrew Schneider, Kingsley Kakie
  CS303
  11/5/2013
  Project 2 (Programming 7 pg. 509) - Morse Code Project
  Description: Store each letter of the alphabet in a node of a binary tree of
  depth 4. The root node is at depth 0 and stores no letter. The left node at
  depth 1 stores the letter e and the right node stores the letter t. See fig.
  8.38 on pg. 510 for the remaining nodes.
  To build the tree, read a file in which each line consists of a letter
  followed by its code. The letters should be ordered by tree depth. To find
  the position for a letter in the tree, scan the code and branch left for a
  dot and branch right for a dash. Encode a message by replacing each letter by
  its code symbol. Then decode the message using the Morse code tree. Make sure
  you use a delimiter symbol between coded letters.
  ---MorseTree.cpp is the implementation file for the class MorseTree---
  MorseTree will store the letters of the alphabet in accordance to Fig. 8.38
  on pg. 510 in the textbook.
  Will also decode and encode messages to morse code.
 */
#include <queue>
#include <fstream>
#include <iostream>
#include "MorseTree.h"

using std::priority_queue;
using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;

/** Stores MorseData in a priority_queue & builds the tree from Fig. 8.38 on 
	pg. 510.
	Iterates through dataTable and for each letter, appends it to MorseTree.
*/
void MorseTree::BuildTree()
{
	priority_queue<MorseData> dataTable;
	ReadInCode(dataTable);
	int tableSize = dataTable.size();
	for(int index = 0; index < tableSize; index++)
	{
		//Iterate through dataTable and build the tree.
		MorseData data = dataTable.top();
		dataTable.pop();
		int start = 0; //Begin at the first charcter in a string.
		if (!Insert(this->root, data, start))
		{
			cerr << "ERROR: Bad character found for: " << data << endl
				 << "Unable to build MorseTree.\n";
		}
	}
}

/** Inserts characters into the MorseTree in their correct locations.
	Iterates through MorseData.m_code to determine the placement for each
	character.
	Returns true if the character is placed in the tree correctly, false
	otherwise.
*/
bool MorseTree::Insert(BTNode<char>*& localRoot, MorseData data, int& index)
{
	if (localRoot == NULL)
	{
		//Insert letter into tree.
		localRoot = new BTNode<char>(data.m_letter);
		return true;
	}
	if (data.m_code[index] == '.')
	{
		//Begin insertion starting at the left child of the root.
		index++;
		Insert(localRoot->left, data, index);
	}
	else if (data.m_code[index] == '_')
	{
		//Begin insertion starting at the right child of the root.
		index++;
		Insert(localRoot->right, data, index);
	}
	else
	{
		//Bad character contained in m_code.
		return false;
	}
}

/** Reads in data supplied by a text file that contains the alphabet paired
	with each letter's corresponding morse code.
	@param codeDataTable - The priority_queue that will store MorseData and
	sort items based upon their depth to be held within the MorseTree.
*/
void MorseTree::ReadInCode(priority_queue<MorseData>& codeDataTable)
{
	ifstream inFile("MorseCode.txt");
	char let;
	string code;
	MorseData codeData;
	while (inFile >> let >> code)
	{
		codeData.m_letter = let;
		codeData.m_code = code;
		codeDataTable.push(codeData);
	}
	inFile.close();
}

/** Decodes an encoded Morse code message.
	@param tree - The tree to begin searching for the specific character.
	@param codedMessage - A Morse code message that is to be decoded.
	@param decodedMessage - A message that has been decoded.
	@param n - the current index position whithin codedMessage.
*/
void MorseTree::Decode(Binary_Tree<char>& tree, string& codedMessage,
						 string& decodedMessage, int n)
{
	if(codedMessage.substr(n,1) == "." && n <= codedMessage.length())
    {   
		if(tree.is_leaf())
		{
			//Prevent from accessing NULL nodes.
			cerr << "Invalid Morse code used in MorseTree::Decode(BTNode<char*& node"
				 << ", string& codedMessage, string& decodedMessage, int n)\n";
			return;
		}
		//Traverse down the left subtree.
		Decode(tree.get_left_subtree(), codedMessage.substr(n), 
			   decodedMessage, n++);
    }
	else if(codedMessage.substr(n,1) == "_" && n <= codedMessage.length())
    {   
		if(tree.is_leaf())
		{
			//Prevent from accessing NULL nodes.
			cerr << "Invalid Morse code used in MorseTree::Decode(BTNode<char*& node"
				<< ", string& codedMessage, string& decodedMessage, int n)\n";
			return;
		}
		//Traverse down the right subtree.
		Decode(tree.get_right_subtree(), codedMessage.substr(n),
			   decodedMessage, n++);
    }
	else
	{
		decodedMessage += tree.get_data();
		return;
    }     
}


/** Wrapper function for Decode(BTNode<char>* node, string& codedMessage,
	string& decodedMessage, int n).
	Limits user error by passing appropriate values for the required parameters.
	@param codedMessage - A Morse code message that is to be decoded.
*/
string MorseTree::Decode(string& codedMessage)
{
	string result = "", codedLetter = "";
	size_t startLetter = 0;
	if (codedMessage[codedMessage.size() - 1] != DELIMITER)
	{
		//codedMessage did not end with DELIMITER.
		codedMessage += DELIMITER;
	}

	for (size_t index = 0; index < codedMessage.size(); index++)
	{
		if (codedMessage[index] == DELIMITER && index > startLetter)
		{
			//End of a coded letter.
			startLetter = index;
			Decode(*this, codedLetter, result, 0);
			codedLetter = "";
		}
		else if (codedMessage[index] == ' ')
		{
			//Append space to result
			result += " ";
		}
		else
		{
			//Append code to codedLetter.
			codedLetter += codedMessage[index];
		}
	}
	return result;
}

/** Traverses the MorseTree and determine the correct code for letter.
	@param tree - The tree to be traversed.
	@param letter - The letter being searched for.
	@param found - Determines when letter is found. (Should be passed as false
	initially)
*/
string MorseTree::EncodeChar(Binary_Tree<char>& tree, char letter, bool& found)
{
	if (tree.is_null())
	{
		return "";
	}
	if (tree.get_data() == letter)
	{
		//Character is found.
		found = true;
		return "";
	}
	else
	{
		//Traverse left subtree.
		string message = "." + EncodeChar(tree.get_left_subtree(), letter, found);
		if (!found) //No need to traverse right subtree if letter is found.
		{
			//Traverse right subtree.
			message = "_" + EncodeChar(tree.get_right_subtree(), letter,
											found);
		}
		return message;
	}
}

/** Takes a message and encodes that message into Morse code.
	Iterates through each character contained within message and finds their
	corresponding Morse code by calling EncodeChar().
	Returns a Morse code message with DELIMITER seperating each word.
*/
string MorseTree::Encode(string& message)
{
	string codedMessage = "";
	for (int index = 0; index < message.size(); index++)
	{
		char letter = tolower(message[index]); //Grab each character in message.
		if (letter == ' ')
		{
			//Keeps spaces in tact.
			codedMessage += " ";
			codedMessage += DELIMITER;
		}
		else if (letter >= 'a' && letter <= 'z')
		{
			//Determines when the letter is found in MorseTree
			bool foundLetter = false;
			codedMessage += EncodeChar(*this, letter, foundLetter);
			codedMessage += DELIMITER;
		}
		else
		{
			//Invalid character.
			codedMessage = "ERROR! Invalid character found in message: ";
			codedMessage += letter;
			return codedMessage;
		}
	}
	return codedMessage;
}