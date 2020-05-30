#pragma once
#include <iostream>

template <class T>
class Node
{
    //friend class List;
public:
    Node();
    Node(T data);
    Node(T data, Node *next, Node *last);
private:
    T data;
    Node *next;
    Node *last;
};
