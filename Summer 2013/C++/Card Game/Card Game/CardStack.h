/*William Freeman
  CS201R
  7/23/2013
  Assignment 6 - Card Game
  Description: Create a card game using a Stack implemented with a Linked
  List. The players will pick from a stack of 100 cards and whoever has the
  highest score at the end of the game wins.
  ---CardStack.h is the header file for the CardStack & Node class.---*/
#ifndef _CARD_STACK
#define _CARD_STACK
  
class Node
{
private:
	int m_data;
	Node* m_ptrNext;
public:
	friend class CardStack;
}; //Node class

class CardStack
{
private:
	int m_size;
	Node* m_ptrTop;
	Node* m_ptrBottom;
public:
	//Default Constructor.
	//Initalizes m_ptrTop & m_ptrBottom to NULL.
	//Initalizes m_size to 0.
	CardStack();
	//Destructor.
	//Calls the Pop() function until m_ptrBottom != NULL.
	~CardStack();
	//Appends the parameter value passed to the stack.
	void Push(int value);
	//Removes the topmost card from the stack.
	void Pop();
	//Returns m_data being pointed to by m_ptrTop.
	//Throws an error if the stack is emtpy.
	int Top();
	//Returns the value of m_size.
	int GetSize();
}; //CardStack class

#endif //_CARD_STACK

