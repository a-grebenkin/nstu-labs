#pragma once

#include "Node.h"
#include <functional>

using namespace std;

template <class T>
class List
{
public:
    List() {
        this->head = nullptr;
        this->temp = nullptr;
    };

    void pop_front() {
        if (head)
        {
            Node<T> *tmp = head;
            tmp = tmp->getNext();
            delete head;
            head = tmp;
        }
    };
    
    void pop_back() {
        if (temp) {
            Node<T> *current = temp;
            current = current->getPrevious();
            delete current->getNext();
        }
    };;

    void pop(int index) const {
        size_t i = 0;

        Node<T> *node = head;

        while (node != nullptr && i != index)
        {
            i++;
            node = node->getNext();
        }

        if (i != index)
            return;

        Node<T> *previous = node->getPrevious(), *next = node->getNext();

        if (next == nullptr)
            next->setPrevious(previous);

        previous->setNext(next);

        delete node;
    };
    
    void push_front(T data) {
        Node<T> *nd = new Node<T>(data);
        temp = nd;

        if (head)
        {
            Node<T> *tmp = head;
            head = nd;
            nd->setNext(tmp);
        }
        else
        {
            head = nd;
            nd->setNext(nullptr);
        }
    };
    
    void push_back(T &data) {
        auto *nd = new Node<T>(data, nullptr, temp);
        temp = nd;

        if (head)
        {
            Node<T> *current = head;
            while(current->getNext())
                current = current->getNext();

            current->setNext(nd);
        }
        else
            head = nd;
    };
    
    size_t size() const {
        size_t counter = 0;

        Node<T> *node = this->head;

        while (node != nullptr)
        {
            counter++;
            node = node->getNext();
        }

        return counter;
    };

    size_t count_if(const function<bool(T)> &query) const {
        size_t counter = 0;

        Node<T> *node = this->head;

        while (node != nullptr)
        {
            if (query(node->getData()))
                counter++;

            node = node->getNext();
        }

        return counter;
    };

    bool empty() const {
        return head == nullptr;
    };

    T &operator[](int index) const {
        size_t i = 0;

        Node<T> *node = head;

        while (node != nullptr && i != index)
        {
            i++;
            node = node->getNext();
        }

        if (i != index)
            throw invalid_argument("index is out of range");

        return node->getData();
    };
    
private:
    Node<T> *head; //голова списка

    Node<T> *temp; //последний узел
};
