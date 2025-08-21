#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
template<typename T>
class Queue 
{
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
    Queue();

    void enqueue(T data);
    void ENQUEUE(T* data);
    T* dequeue();
    T DEQUEUE();

    bool isEmpty();

    int getCount();

    void print();

    bool peek(T& frntEntry);

    T PeekValue();
};

#endif