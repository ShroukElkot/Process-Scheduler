#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include"Node.h"
#include<iostream>
#include "Node.cpp"
using namespace std;
template <typename T>
class LinkedList {
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}
	//LinkedList(LinkedList <T> lnew) //copy constructor
	//{
	//	Head = lnew.Head;
	//}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}

	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	T* getfirst() { // a function made to get the first item so that we can use linked list as FIFO
		Node<T>* p = Head;
		//Node<Process>* p = Head;
		Head = Head->getNext();
		return p->getItemPointer();
	}

	T getatindex(int n) {  //
		Node<T>* p = Head;
		for (int i = 0; i < n; i++) {
			p = p->getNext();
		}
		return p->getItemPointer();
		//return *(p->getItemPointer());
	}

	T getatindex1(int n) {  //
		Node<T>* p = Head;
		for (int i = 0; i < n; i++) {
			p = p->getNext();
		}
		return p->getItem();
		//return *(p->getItemPointer());
	}


	T* getatindex2(int n) {  //
		Node<T>* p = Head;
		for (int i = 0; i < n; i++) {
			p = p->getNext();
		}
		return p->getItemPointer();
	}
	void PrintList(LinkedList<T>& list) const
	{
		cout << list;
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();

		}
		cout << "*\n";
	}

	//friend ostream& operator<<(ostream& os, const LinkedList<T>& list) {
	//	Node<T>* p = list.Head;
	//	os << "\nprinting list contents:\n\n";
	//	while (p) {
	//		os << "[ " << p->getItem() << " ]";
	//		os << "--->";
	//		p = p->getNext();
	//	}

	//	os << "*\n";

	//	return os;
	//}


	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}

	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void insertend(const T& newlist) {
		Node<T>* p = Head;
		Node<T>* R = new Node<T>(newlist);
		while (p->getNext() != nullptr) {
			p = p->getNext();
		}
		p->setNext(R);
		R->setItem(newlist);
		R->setNext(NULL);
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool find(T value) {
		bool first = false;
		Node<T>* Temp = Head;
		while (Temp) {
			if (Temp->getItem() == value) {
				first = true;
			}
			Temp = Temp->getNext();

		}
		return first;
	}


	Node <T>* findat(T value) {
		bool first = false;
		Node<T>* Temp = Head;
		while (Temp) {
			if (Temp->getItem() == value) {
				first = true;
			}
			Temp = Temp->getNext();

		}
		return Temp;
	}

	Node <T>* FINDAT(int value) {
		bool first = false;
		Node<T>* Temp = Head;
		while (Temp) {
			if (Temp->getItem() == value) {
				first = true;
			}
			Temp = Temp->getNext();

		}
		return Temp;
	}
	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int count(T value) {
		int count = 0;
		Node<T>* Temp = Head;
		while (Temp != NULL) {
			if (Temp->getItem() == value) {
				count++;
			}
			Temp = Temp->getNext();
		}
		return count;
	}
	int countall() {
		int count = 0;
		Node<T>* Temp = Head;
		while (Temp != NULL) {
			count++;
			Temp = Temp->getNext();
		}
		return count;
	}
	//[4] DeleteFirst
	//Deletes the first node in the list
	void deletefirst() {
		Node<T>* Temp = Head;
		Temp = Head->getNext();
		delete Head;
		Head = Temp;
	}

	//[5] DeleteLast
	//Deletes the last node in the list
	void deletelast() {
		int count = 0;
		Node<T>* Temp = Head;
		while (Temp->getNext() != NULL) {
			Temp = Temp->getNext();
			count++;
		}
		delete Temp;
		Node<T>* Temp2 = Head;
		for (int i = 0; i < count - 1; i++)
		{
			Temp2 = Temp2->getNext();
		}
		Temp2->setNext(NULL);

	}
	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool deletenode(T value) {
		Node<T>* Temp = Head;
		Node<T>* Temp2 = Head;
		bool first = false;
		if (Temp->getItem() == value) {
			deletefirst();
		}
		else
		{

			int count = 0;

			while (Head) {
				count++;
				if (Temp->getItem() == value) {
					for (int i = 0; i < count - 2; i++)
					{
						Temp2 = Temp2->getNext();
					}
					Temp2->setNext(Temp->getNext());
					delete Temp;
					first = true;
					return first;
				}
				Temp = Temp->getNext();

			}
			return first;

		}

	}
	/*void delete_node(int val) {
		if (Head == NULL) {
			return;
		}
		if (Head->data == val) {
			Node<T>* temp = Head;
			Head = Head->getNext();
			delete temp;
			return;
		}
		Node<T>* curr_node = Head;
		while (curr_node->getNext != NULL) {
			if (curr_node->getNext()->getItem() == val) {
				Node* temp = curr_node->getNext();
				curr_node->getNext() = curr_node->getNext()->getNext();
				delete temp;
				return;
			}
			curr_node = curr_node->next;
		}
	}
	*/

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	void deletenodes(T value) {
		int noofvals = count(value);
		for (int i = 0; i < noofvals; i++)
		{
			deletenode(value);
		}
		/*bool first = false;
		Node<T>* Temp = Head;
		Node<T>* Temp2 = Head;
		while (Temp->getNext() != NULL) {
			if (Temp->getItem() == value) {
				for (int i = 0; i < count - 2; i++)
				{
					Temp2 = Temp2->getNext();
				}
				Temp2->setNext(Temp->getNext());
				delete Temp;
				first = true;
			}
			Temp = Temp->getNext();

		}
		return first;*/
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void join(LinkedList<T>& L) {

		Node<T>* Temp = Head;

		while (Temp->getNext() != NULL) {
			Temp = Temp->getNext();
		}
		Temp->setNext(L.Head);
		L.Head = NULL;
	}
	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void reverse()
	{
		// Initialize current, previous and next pointers
		Node<T>* current = Head;
		Node<T>* prev = NULL; Node<T>* next = NULL;

		while (current != NULL) {
			// Store next
			next = current->getNext();
			// Reverse current node's pointer
			current->setNext(prev);
			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		Head = prev;
	}
	T* getfirst_index(int P) {
		Node<T>* p = Head;
		for (int i = 0; i < P; i++) {
			p = p->getNext();
		}
		return p->getItemPointer();
	}

	/*	T find_node(int val) {
			Node* curr_node = head;
			while (curr_node != NULL) {
				if (curr_node->data == val) {
					return curr_node;
				}
				curr_node = curr_node->next;
			}
			return NULL;
		}
		*/
	void printkth(int k) {
		int count = 1;
		Node<T>* Temp = Head;
		while (Temp->getNext() != NULL) {
			count++;
			Temp = Temp->getNext();

		}
		if (k<1 || k > count) {
			cout << " beyond list length " << endl;
		}
		else
		{
			Node<T>* neededdata = Head;
			for (int i = 1; i < k; i++) {
				neededdata = neededdata->getNext();
			}
			cout << neededdata->getItem() << " this is your data";

		}
	}

	void INSERT(T* data)
	{
		Node<T>* newNode = new Node<T>(*data);
		if (Head == nullptr) {
			Head = newNode;
			return;
		}
		Node<T>* current = Head;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(newNode);
	}
};
#endif

