#ifndef BINTREE_CPP
#define BINTREE_CPP
#include "BinTree.h"

template<class T>
BinTree<T>::BinTree():root(nullptr),count(0)
{
}

// Destructor
template<class T>
BinTree<T>::~BinTree() {
	destroy(root);
}

// Insert
template<class T>
void BinTree<T>::insert(const T& value) {
	insert(value, root);
	count++;
}

// Search
template<class T>
bool BinTree<T>::search(const T& value) const {
	return search(value, root);
}


// Preorder
template<class T>
void BinTree<T>::preOrder() const {
	preOrder(root);
}

// In order
template<class T>
void BinTree<T>::inOrder() const {
	inOrder(root);
}

// Post order
template<class T>
void BinTree<T>::postOrder() const {
	postOrder(root);
}

// Size
template<class T>
int BinTree<T>::size() const {
	return count;
}

// Empty member function
template <class T>
bool BinTree <T> ::empty() const
{
	return (count == 0);
}

/*
  ____                          _                _   _      _
 |  _ \ ___  ___ _   _ _ __ ___(_)_   _____     | | | | ___| |_ __   ___ _ __
 | |_) / _ \/ __| | | | '__/ __| \ \ / / _ \    | |_| |/ _ \ | '_ \ / _ \ '__|
 |  _ <  __/ (__| |_| | |  \__ \ |\ V /  __/    |  _  |  __/ | |_) |  __/ |
 |_| \_\___|\___|\__,_|_|  |___/_| \_/ \___|    |_| |_|\___|_| .__/ \___|_|
															 |_|
																				*/
template<class T>
void BinTree<T>::destroy(Node<T>* node) {
	if (node == nullptr)
		return;
	else
	{
		destroy(node->left);
		destroy(node->right);	
		delete node;
	}
}

template<class T>
void BinTree<T>::insert(const T& value, Node<T>*& node) {
	if (node == nullptr) {
		node = makeNode(value);
		return;
	}
	else if (value < node->data) {
		insert(value, node->left);
	}
	else
	{
		insert(value, node->right);
	}
}


template<typename T>
void BinTree<T>::preOrder(Node<T>* node) const{
	if (node == nullptr)
		return;

	cout << node->data << endl;
	preOrder(node->left);
	preOrder(node->right);
}

template <class T>
void BinTree<T>::inOrder(Node<T>* node) const {
	if (node == nullptr)
		return;

	inOrder(node->left);
	cout << node->data << endl;
	inOrder(node->right);

}

template <class T>
void BinTree<T>::postOrder(Node<T>* node) const {
	if (node == nullptr)
		return;

	postOrder(node->left);
	postOrder(node->right);
	cout << node->data;
}


template <typename T>
bool BinTree <T> ::search(const T& value, Node <T>* node) const
{
	if (node == nullptr)
	{
		return false;
	}
	else if (value < node->data)
	{
		search(value, node->left);
	}
	else if (value > node->data)
	{
		search(value, node->right);
	}
	else
		return true;
}

template <typename T>
Node <T>* BinTree <T> ::makeNode(const T& value) {
	Node<T>*  tempNode = new Node<T>;
	tempNode->data = value;
	tempNode->left = nullptr;
	tempNode->right = nullptr;

}
#endif // !BINTREE_CPP
