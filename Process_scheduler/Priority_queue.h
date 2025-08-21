#pragma once
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Node.h"
#include <string>
#include <iostream>
#include "Process.h"

using namespace std;
//#include "Priority_queue.cpp"

template <typename T>
class Priority_queue
{
private :
	Node<T>* Head;
	Node<T>* Tail;

	int Count;
public:
	Priority_queue();
	~Priority_queue();
	//void enqueue(T data);
	void Enqueue(T* data, double Priority);
	//void Enqueue_tr(Node<T>* n);
	Node<T>* getHead(); // returns the highest priority item
	Node<T>* getTail(); // returns the least priority item
	void Remove(Node<T>* node);
	bool IsEmpty();
	std::pair<T*, double>* Dequeue();
	//std::pair<Process*, double >* DEQUEUE();
	int getCount();
	void print();
	T get_at_node(int n);
	//void Remove(); // This function returns the highest priority item and 
};

#endif 