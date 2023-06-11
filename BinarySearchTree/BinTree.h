#ifndef  BINTREE_H
#define BINTREE_H
#include <iostream>
using namespace std;

// NODE
template<class T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
};


// TREE
template<class T>
class BinTree {
private:
	Node<T>* root;
	int count;
	Node<T>* makeNode(const T& value);	// Create a new Node
	void destroy(Node<T>* ptr);			// Destroy a node
	void insert(const T& value, Node<T>*& ptr);
	void inOrder(Node<T>* ptr)	const;
	void preOrder(Node<T>* ptr) const;
	void postOrder(Node<T>* ptr) const;
	bool search(const T& value, Node<T>* ptr) const;
public:
	// Constructor
	BinTree();
	// Destructor
	~BinTree();
	void insert(const T& value);
	void erase(const T& value);
	bool search(const T& value) const;
	void inOrder() const;
	void preOrder() const;
	void postOrder() const;
	int size()	const;
	bool empty() const;

};
#endif // ! BINTREE_H
