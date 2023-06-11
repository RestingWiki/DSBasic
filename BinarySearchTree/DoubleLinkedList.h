#ifndef  DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include<iostream>
using namespace std;
template <typename T>
struct Node
{
	T data;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
};




// DoublelyLinkedList
template <typename T>
class DoubleLinkedList{
private:
	Node<T>* head;
	int count;
	Node<T>* makeNode(const T& value);
public:
	DoubleLinkedList();			// Constructor
	~DoubleLinkedList();		// Destructor
	void insert(int pos, const T& value);
	void erase(int pos);
	T& get(int pos) const;
	void print() const;
	int size()   const;


};


#endif // ! DOUBLELINKEDLIST_H

