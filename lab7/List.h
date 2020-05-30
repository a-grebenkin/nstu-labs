#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class List
{
public:
    List();
    void pop_front();
    
    void pop_back();
    
    void push_front(T data);
    
    void push_back(T data);
    
    int size();
    
private:

    Node<T> *head; //голова списка

    Node<T> *temp; //последний узел
    
    int n;
};
