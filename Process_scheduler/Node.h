#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;
template<typename T>
class Node
{
private:
	T item;	// A data item (can be any complex sturcture)
	Node<T>* next;	// Pointer to next node
	double priority;
public:

	Node(); //default constructor

	Node(T newItem); //non-default constructor
	Node(T* newItem);

	void setItem(T newItem); // end setItem

	void setNext(Node<T>* nextNodePtr); // end setNext

	void setPriority(double Priority);
	double getPriority();

	T getItem() const; // end getItem
	int GETITEM() const;
	T* getItemPointer();


	Node<T>* getNext() const;
	//T* operator=(const T* newItem);

}; // end Node


//template <typename T>
//ostream& operator<<(ostream& os, const Node<T>& node) {
//	os << node.getItem();
//	return os;
//}
//#include "Node.cpp"


#endif

