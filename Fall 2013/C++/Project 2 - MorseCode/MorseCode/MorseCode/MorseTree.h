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
  ---MorseTree.h is the header file for the class MorseTree---
  MorseTree will store the letters of the alphabet in accordance to Fig. 8.38
  on pg. 510 in the textbook.
  Will also decode and encode messages to morse code.
 */
#ifndef _MORSE_TREE_H_
#define _MORSE_TREE_H_
#include <string>
#include <queue>
#include <fstream>
#include <map>
#include "Binary_Tree.h"

using std::string;
using std::priority_queue;
using std::ostream;
using std::map;

//struct to store the data pertaining to a letter and its code.
struct MorseData
{
	char m_letter;
	string m_code;

	//Operator overloads
	friend ostream& operator<<(ostream& out, const MorseData& node)
	{
		return out << node.m_letter << ": " << node.m_code;
	}
	
	//Overload < operator for sorting purposes.
	friend bool operator<(const MorseData& d1, const MorseData& d2)
	{
		if (d1.m_code.size() == d2.m_code.size()) //Code is same length.
		{
			return d1.m_code < d2.m_code;
		}
		else
		{
			//d1 is larger than d2 but is considered less than d2 for proper
			//sorting within a priority_queue.
			return d2.m_code.size() < d1.m_code.size();
		}
	}
}; //end MorseData

class MorseTree : public Binary_Tree<char>
{
private:
	//Private member variables
	const char DELIMITER; //Delimiter to seperate coded letters.

	//Private member functions
	/** Stores MorseData in a priority_queue & builds the tree from Fig. 8.38 on 
		pg. 510.
		Iterates through dataTable and for each letter, appends it to MorseTree.
	*/
	void BuildTree();
	/** Inserts characters into the MorseTree in their correct locations.
		Iterates through MorseData.m_code to determine the placement for each
		character.
		Returns true if the character is placed in the tree correctly, false
		otherwise.
	*/
	bool Insert(BTNode<char>*& localRoot, MorseData data, int& index);
	/** Reads in data supplied by a text file that contains the alphabet paired
		with each letter's corresponding morse code.
		@param codeDataTable - The priority_queue that will store MorseData and
		sort items based upon their depth to be held within the MorseTree.
	*/
	void ReadInCode(priority_queue<MorseData>& codeDataTable);
	/** Decodes an encoded Morse code message.
		@param tree - The tree to begin searching for the specific character.
		@param codedMessage - A Morse code message that is to be decoded.
		@param decodedMessage - A message that has been decoded.
		@param n - the current index position whithin codedMessage.
	*/
	void Decode(Binary_Tree<char>& tree, string& codedMessage,
				  string& decodedMessage, int n);
	/** Traverses the MorseTree and determine the correct code for letter.
		@param tree - The tree to be traversed.
		@param letter - The letter being searched for.
		@param found - Determines when letter is found. (Should be passed as false
		initially)
	*/
	string EncodeChar(Binary_Tree<char>& tree, char letter, bool& found);

public:
	//Constructors
	MorseTree()
		: DELIMITER('+'), Binary_Tree<char>()
	{
		//Create a root for the tree with no letter.
		this->root = new BTNode<char>(' ');
		BuildTree();
	}
	
	//Public member functions
	/** Wrapper function for Decode(BTNode<char>* node, string& codedMessage,
		string& decodedMessage, int n).
		Limits user error by passing appropriate values for the required parameters.
		@param codedMessage - A Morse code message that is to be decoded.
	*/
	string Decode(string& codedMessage);
	/** Takes a message and encodes that message into Morse code.
		Iterates through each character contained within message and finds their
		corresponding Morse code by calling EncodeChar().
		Returns a Morse code message with DELIMITER seperating each word.
	*/
	string Encode(string& message);
	/** Returns the DELIMITER used to seperate coded letters.*/
	char GetDelimiter() const
	{
		return DELIMITER;
	}

}; //end MorseTree

#endif //_MORSE_TREE_H_