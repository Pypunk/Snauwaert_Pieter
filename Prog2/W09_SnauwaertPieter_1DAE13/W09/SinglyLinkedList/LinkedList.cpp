#include "pch.h"
#include "LinkedList.h"

Node::Node(int value, Node *pNext)
	:value{ value }
	, pNext{ pNext }
{
}

LinkedList::LinkedList()
	:m_Size{}
	,m_pFirstNode{ nullptr }
{
}

LinkedList::~LinkedList()
{
}

// Wrap the value in a new Node object and add it as first Node of the list
void LinkedList::PushFront( int  value )
{
	Node* oldNode{ m_pFirstNode };
	m_pFirstNode = new Node{ value };
	m_pFirstNode->pNext = oldNode;
	m_Size++;
}

// Remove and delete first Node
void LinkedList::PopFront()
{
	if (m_pFirstNode)
	{
		Node* nextNode{ m_pFirstNode->pNext };
		m_pFirstNode = nextNode;
	}
	m_Size--;
}

// Remove all Nodes having this value
void LinkedList::Remove( int value )
{
	if (m_pFirstNode->value == value)
	{
		if (m_pFirstNode->pNext)
		{
			m_pFirstNode = m_pFirstNode->pNext;
		}
		m_Size--;
	}
}

// Wrap the value in a new Node object and insert it after the specified Node 
void LinkedList::InsertAfter(Node* pBefore, int value)
{
	Node* previousNode{ pBefore->pNext };
	pBefore->pNext = new Node{ value };
	pBefore->pNext->pNext = previousNode;
	m_Size++;
}

// Return pointer to first Node
Node* LinkedList::Begin( ) const
{
	return m_pFirstNode;
}

// Return number of Node objects in the list
size_t LinkedList::Size( ) const
{
	return m_Size;
}

// Send the values of the list to the out object, use a space as element separator
std::ostream& operator<<( std::ostream& out, const LinkedList& list )
{
	Node* printNode{ list.Begin() };
	while (printNode)
	{
		out << printNode->value << " ";
		printNode = printNode->pNext;
	}
	return out;
}
