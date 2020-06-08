#include "Node.h"

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

template<class T>
Node<T> *Node<T>::getNext() const {
    return next;
}

template<class T>
Node<T> *Node<T>::getPrevious() const {
    return last;
}

template<class T>
T *Node<T>::getData() const {
    return *data;
}

template<class T>
void Node<T>::setNext(Node<T> node) {
    next = node;
}

template<class T>
void Node<T>::setPrevious(Node<T> node) {
    last = node;
}
