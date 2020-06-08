#pragma once

template <class T>
class Node
{
    //friend class List;
public:
    Node();
    Node(T data);
    Node(T data, Node *next, Node *last);

    Node<T> *getNext() const;

    Node<T> *getPrevious() const;

    T *getData() const;

    void setNext(Node<T> node);

    void setPrevious(Node<T> node);
private:
    T data;
    Node *next;
    Node *last;
};
