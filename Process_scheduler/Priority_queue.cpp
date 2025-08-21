#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP
#include <iostream>
#include "Priority_queue.h"
using namespace std;



template<typename T>
Priority_queue<T>::Priority_queue()
{
	this->Head = nullptr;
	this->Tail = nullptr;
	this->Count = 0;

}

template <typename T>
Priority_queue <T>::~Priority_queue() 
{
	Node<T>* temp_node = this->Head;
	while (this->Head) 
	{
		temp_node = this->Head->getNext();
		delete this->Head;
		this->Head = temp_node;
	}
	this->Count = 0;
}

//template <typename T> 
//void Priority_queue<T>::enqueue(T data)
//{
//	Node<T>* new_node = new Node<T>(data);
//	
//};

template <typename T>
void Priority_queue<T>::Enqueue(T* data, double Priority) // priority is ordered descendimg
{

	Node<T>* new_node = new Node<T>(*data);
	new_node->setPriority(Priority);

	if (IsEmpty()) // the priority queue is empty 
	{
		this->Tail = new_node;
		this->Head = new_node;
		this->Count += 1;
		return;
	}
	else if (this->Tail->getPriority() < Priority) // if priority of last item is less 
	{
		this->Tail->setNext(new_node);
		this->Tail = new_node;
		this->Count += 1;
		return;
	}
	else
	{
		Node<T>* tNode = Head;
		if (this->Head->getPriority() > Priority)
		{
			new_node->setNext(this->Head);
			this->Head = new_node;
			this->Count += 1;
			return;
		}

		else // head priority > Priority
		{
			while (tNode->getPriority() <= Priority)
			{
				tNode = tNode->getNext();
			}
			if (tNode->getNext() == nullptr)
			{
				tNode->setNext(new_node);
				Tail = new_node;
			}
			else // next of tNode is not null
			{
				tNode->setNext(new_node);
			}
			this->Count += 1;
		}
	}


}


template <typename T>
void Priority_queue <T> ::Remove(Node<T>* node)
{
	Node <T>* temp = Head;
	Node<T>* N_temp = Head->getNext();
	while (N_temp)
	{
		if (N_temp == node)
		{
			temp->setNext(N_temp->getNext());
			delete N_temp;
		}

	}

}




template <typename T>
Node<T>* Priority_queue<T>::getHead()
{
	return this->Head;
}

template <typename T>
Node<T>* Priority_queue<T>::getTail() // least priority
{
	return this->Tail;
}

template <typename T >
bool Priority_queue<T>::IsEmpty()
{
	return (Head == nullptr && Tail == nullptr);
}

template <typename T>
std::pair<T*, double>* Priority_queue<T>::Dequeue()
{
	if (IsEmpty())
	{
		cout << "The priority queue is empty";
		//return make_pair(nullptr,0.0);
		return nullptr;
	}
	else if (Head == Tail)
	{
		//Node <T>* node_dec = Head;
		T* value_dec = Head->getItemPointer();
		double prio = Head->getPriority();
		delete Head;
		Head = Tail = nullptr;
		this->Count -= 1;
		//return value_dec;
		return new std::pair<T*, double>(value_dec, prio);
	}
	else // if there is more than one node
	{
		Node <T>* LNode = Head;
		T* value_dec = Head->getItemPointer();
		double prio = Head->getPriority();
		Head = Head->getNext();
		this->Count -= 1;
		delete LNode;
		return new std::pair<T*, double>(value_dec, prio);
	}
}

//template <typename T>
//std::pair<Process*, double >* Priority_queue<T>::DEQUEUE()
//{
//	if (IsEmpty())
//	{
//		cout << "The priority queue is empty";
//		//return make_pair(nullptr,0.0);
//		return nullptr;
//	}
//	else if (Head == Tail)
//	{
//		//Node <T>* node_dec = Head;
//		T* value_dec = Head->getItem();
//		double prio = Head->getPriority();
//		delete Head;
//		Head = Tail = nullptr;
//		this->Count -= 1;
//		//return value_dec;
//		return new std::pair<T*, double>(value_dec, prio);
//	}
//	else // if there is more than one node
//	{
//		Node <T>* LNode = Head;
//		T* value_dec = Head->getItem();
//		double prio = Head->getPriority();
//		Head = Head->getNext();
//		this->Count -= 1;
//		delete LNode;
//		return new std::pair<T*, double>(value_dec, prio);
//	}
//}
//



//template <typename T>
//void Priority_queue<T> :: Remove()
//{
//	T value_dec = Dequeue();
//	delete value_dec;
//
//
//}


template<typename T>
void Priority_queue<T>::print()
{
	if (Head == nullptr) {
		return;
	}
	Node<T>* current = Head;
	while (current != nullptr) {
		cout << current->setItem() << " ";
		current = current->getNext();
	}
	cout << endl;
}
template<typename T>
int Priority_queue<T> ::getCount()
{
	return this->Count;
}

template <typename T>
T Priority_queue <T> ::get_at_node(int n)
{
	Node<T>* node = Head;
	for (int i = 0; i < n; i++) {
		node = node->getNext();
	}
	return node->getItemPointer();
}



#endif // !PRIORITY_QUEUE_CPP