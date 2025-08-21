#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
#include <iostream>
using namespace std;
template<typename T>
Queue<T>:: Queue() 
{
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
}

template<typename T>
void Queue<T>::enqueue(T data) 
{
        Node<T>* new_node = new Node<T>(data);
        if (head == nullptr) {
           this-> head = new_node;
            this-> tail = new_node;
            this->count += 1;
            return;
        }
        tail->setNext( new_node);
        tail = new_node;
        this->count += 1;
}

template<typename T>
void Queue<T>::ENQUEUE(T* data)
{
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
        this->head = new_node;
        this->tail = new_node;
        this->count += 1;
        return;
    }
    tail->setNext(new_node);
    tail = new_node;
    this->count += 1;
}
template<typename T>
T* Queue<T>:: dequeue() 
{
        if (isEmpty()) // the queue does not contain elements
        {
            cout<< "Queue is empty";
        }
        else if (head == tail) // the queue contains one item
        {
            T* value_dec = head->getItemPointer();
            delete head;
            head = tail = nullptr;
            this -> count -= 1;
        
            return value_dec;

        }
        else 
        {
            Node<T>* new_node = head;
            T* value_dec = head->getItemPointer();
            new_node = head->getNext();
            delete head;
            head = new_node;
            this->count -= 1;
            return value_dec;

        }
}

template <typename T>
T Queue <T> ::DEQUEUE()
{
    if (isEmpty()) // the queue does not contain elements
    {
        cout << "Queue is empty";
    }
    else if (head == tail) // the queue contains one item
    {
        T value_dec = head->getItem();
        delete head;
        head = tail = nullptr;
        this->count -= 1;

        return value_dec;

    }
    else
    {
        Node<T>* new_node = head;
        T value_dec = head->getItem();
        new_node = head->getNext();
        delete head;
        head = new_node;
        this->count -= 1;
        return value_dec;

    }
}

template<typename T>
bool Queue<T>::isEmpty() 
{
        return (head == nullptr&& tail==nullptr);
}

template <typename T>
int Queue<T>::getCount() 
{
    return this->count;
}

template<typename T>
 void Queue<T>:: print() 
 {
        if (head == nullptr) {
            return;
        }
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
}

 template <typename T>

 bool  Queue<T>::peek(T& frntEntry)
 {
     if (isEmpty())
         return false;

     frntEntry = head->getItem();
     return true;

 }

 template <typename T>

 T  Queue<T>::PeekValue()
 {
     if (isEmpty()){}
     else {
         T frntEntry = head->getItem();
         return frntEntry;
     }
 }
#endif