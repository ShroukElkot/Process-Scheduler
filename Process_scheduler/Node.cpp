#include "Node.h"
#pragma once

template<typename T> //default constructor
Node<T>::Node()
{
	next = nullptr;
}

template<typename T>
Node<T>::Node(T newItem) //non-default constructor
{
	item = newItem;
	next = nullptr;
}

template<typename T>
Node<T>::Node(T* newItem) //non-default constructor
{
	item = * newItem;
	next = nullptr;
}

template<typename T>
void Node<T>::setItem(T newItem)
{
	item = newItem;
}

template<typename T>
void Node<T> ::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template<typename T>
T Node<T> ::getItem() const
{
	return item;
}

template<typename T>
int Node<T> ::GETITEM() const
{
	return item;
}

template<typename T>
Node<T>* Node<T> ::getNext() const
{
	return next;
}
template<typename T>
void Node<T>::setPriority(double Priority)
{
	this->priority = Priority;
}
template<typename T>
double Node<T> ::getPriority()
{
	return this->priority;
}
template<typename T>
T* Node<T> ::getItemPointer()
{

	T* n = &item;
	return n;


}
