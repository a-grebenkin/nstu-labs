#include "List.h"
#include <iostream>

template <class T>
List<T>::List():n(0){
    
};

template <class T>
void List<T>:: pop_front(){
    n--;
    if(head)
    {
        Node<T> *tmp = head;
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
}

template <class T>
void List<T>:: pop_back(){
    n--;
    if(temp){
        Node<T> *current = temp;
        current=current->last;
        delete current->next;
        current->next = nullptr;
    }
};

template <class T>
void List<T>:: push_front(T data){
    n++;
    Node<T> *nd = new Node<T>(data);
    temp = nd;
    if(head)
    {
        Node<T> *tmp = head;
        head = nd;
        nd->next = tmp;
    }
    else
    {
        head = nd;
        nd->next = NULL;
    }
}

template <class T>
void List<T>:: push_back(T data){
    Node<T> *nd = new Node<T>(data, NULL, temp);
    temp = nd;
    if(head)
    {
        Node<T> *current = head;
        while(current->next){
            current = current->next;
            current->next = nd;
        }
    }
    else
        head = nd;
}

template <class T>
int List<T>:: size(){
    return n;
}
