#include <iostream>

#ifndef DOUBLELINKEDLIST_CPP
#define DOUBLELINKEDLIST_CPP
#include "DoubleLinkedList.h"

// Constructor
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() :count(0), head(0) {

}

// Destructor
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	Node<T>* del = head;
	while (del != nullptr)
	{
		head = head->next;
		delete del;
		del = head;
	}
}

// Make node member fuction
template<typename T>
Node<T>* DoubleLinkedList<T>::makeNode(const T& value) {
	Node<T>* tempNode = new Node<T>;
	tempNode->data = value;
	tempNode->next = nullptr;
	tempNode->prev = nullptr;

	return tempNode;
}


// Insert member function
template<typename T>
void DoubleLinkedList<T>::insert(int pos, const T& value){
	if (pos < 0 || pos > count)
	{
		cout << "Invalid position!" << endl;
		return;

	}
	Node<T>* newNode = makeNode(value);		// Create a new node for the new value
	if (pos == 0)
	{
		if (head != nullptr)
		{
			newNode->next = head;
			head->prev = newNode;
		}
		head = newNode;
	}
	else if (pos < count)
	{
		Node<T>* curNode = head;
		for (int i = 1; i < pos ; i++)
		{
			curNode = curNode->next;
		}

		newNode->next = curNode->next;
		newNode->prev = curNode;
		curNode->next->prev = newNode;
		curNode->next = newNode;
	}
	else if (pos == count)
	{
		Node<T>* curNode = head;
		while (curNode->next != nullptr)
		{
			curNode == curNode->next;
		}

		newNode->prev = curNode;
		curNode->next = newNode;
	}

	count++;
}


#endif // 
