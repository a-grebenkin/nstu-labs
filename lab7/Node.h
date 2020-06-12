#pragma once

template <class T>
class Node
{
    //friend class List;
public:
    Node(T &data, Node *next, Node *last) {
        this->data = data;
        this->next = next;
        this->last = last;
    };

    Node<T> *getNext() const {
        return next;
    };

    Node<T> *getPrevious() const {
        return last;
    };

    T &getData() {
        return data;
    };

    void setNext(Node<T> *node) {
        next = node;
    };

    void setPrevious(Node<T> *node) {
        last = node;
    };
private:
    T data;
    Node *next;
    Node *last;
};
