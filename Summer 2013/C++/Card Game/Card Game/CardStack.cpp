/*William Freeman
  CS201R
  7/23/2013
  Assignment 6 - Card Game
  Description: Create a card game using a Stack implemented with a Linked
  List. The players will pick from a stack of 100 cards and whoever has the
  highest score at the end of the game wins.
  ---CardStack.cpp is the implementation file for the CardStack class.---*/
#include <iostream>
#include <cassert>

#include "CardStack.h"

//Default Constructor.
//Initalizes m_ptrTop & m_ptrBottom to NULL.
//Initalizes m_size to 0.
CardStack::CardStack()
	: m_size(0), m_ptrTop(NULL), m_ptrBottom(NULL)
{}

//Destructor.
//Calls the Pop() function until m_ptrBottom != NULL.
CardStack::~CardStack()
{
	while (m_ptrBottom != NULL)
	{
		Pop();
	}
}

//Appends the parameter value passed to the stack.
void CardStack::Push(int value)
{
	//Dynamically create a new Node & set variables.
	Node* newNode = new Node;
	newNode->m_data = value;
	newNode->m_ptrNext = NULL;
	
	//Stack is empty.
	if (m_ptrBottom == NULL)
	{
		m_ptrTop = newNode;
		m_ptrBottom = newNode;
	}
	else //Stack is not empty.
	{
		m_ptrTop->m_ptrNext = newNode;
		m_ptrTop = newNode;
	}
	
	m_size++;
}

//Removes the topmost card from the stack.
void CardStack::Pop()
{
	//Throw an erorr if user attempts to Pop() an empty stack.
	assert(m_ptrBottom != NULL);

	//Only one item in stack.
	if (m_ptrBottom->m_ptrNext == NULL)
	{
		delete m_ptrBottom;
		m_ptrBottom = NULL;
	}
	else
	{
		Node* currentNode = m_ptrBottom;
		while (currentNode->m_ptrNext != m_ptrTop)
		{
			currentNode = currentNode->m_ptrNext;
		}

		currentNode->m_ptrNext = NULL;
		delete m_ptrTop;
		m_ptrTop = currentNode;
	}
	
	m_size--;
}

//Returns m_data being pointed to by m_ptrTop.
//Throws an error if the stack is emtpy.
int CardStack::Top()
{
	//Ensure that stack is not empty.
	assert(m_ptrBottom != NULL);
	
	return m_ptrTop->m_data;
}

//Returns the value of m_size.
int CardStack::GetSize()
{
	return m_size;
}
