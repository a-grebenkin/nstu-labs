#include "Node.h"
#include "Bag.h"
#include <iostream>

template <class T>

Node<T>::Node(T data){
    this->data = data;
}

template <class T>

Node<T>::Node(T data, Node *next, Node *last){
    this->data = data;
    this->next = next;
    this->last = last;
}
