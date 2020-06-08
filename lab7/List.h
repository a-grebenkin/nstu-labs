#pragma once

#include "Node.h"
#include <functional>

using namespace std;

template <class T>
class List
{
public:
    List();

    void pop_front();
    
    void pop_back();

    void pop(int index) const;
    
    void push_front(T data);
    
    void push_back(T data);
    
    size_t size() const;

    size_t count_if(const function<bool(T)> &query) const;

    bool empty() const;

    T& operator[](int index) const;
    
private:
    Node<T> *head; //голова списка

    Node<T> *temp; //последний узел
};
