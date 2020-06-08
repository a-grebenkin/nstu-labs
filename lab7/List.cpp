#include "List.h"
#include <stdexcept>

template <class T>
void List<T>::pop_front(){
    if (head)
    {
        Node<T> *tmp = head;
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
}

template <class T>
void List<T>::pop_back(){
    if (temp) {
        Node<T> *current = temp;
        current=current->last;
        delete current->next;
        current->next = nullptr;
    }
};

template <class T>
void List<T>::push_front(T data){
    auto *nd = new Node<T>(data);
    temp = nd;

    if (head)
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
void List<T>::push_back(T data){
    auto *nd = new Node<T>(data, nullptr, temp);
    temp = nd;

    if (head)
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
size_t List<T>::size() const{
    size_t counter = 0;

    Node<T> *node = this->head;

    while (node != nullptr)
    {
        counter++;
        node = node->getNext();
    }

    return counter;
}

template<class T>
bool List<T>::empty() const {
    return head == nullptr;
}

template<class T>
size_t List<T>::count_if(const function<bool(T)> &query) const {
    size_t counter = 0;

    Node<T> *node = this->head;

    while (node != nullptr)
    {
        if (query(node->getData()))
            counter++;

        node = node->getNext();
    }

    return counter;
}

template<class T>
void List<T>::pop(int index) const {
    size_t i = 0;

    Node<T> *node = head;

    while (node != nullptr && i != index)
    {
        i++;
        node = node->getNext();
    }

    if (i != index)
        return;

    Node<T> *previous = node->getPrevious(), next = node->getNext();

    if (!next == nullptr)
        next.setPrevious(previous);

    previous->setNext(next);

    delete node;
}

template<class T>
T& List<T>::operator[](int index) const {
    size_t i = 0;

    Node<T> *node = head;

    while (node != nullptr && i != index)
    {
        i++;
        node = node->getNext();
    }

    if (i != index)
        throw invalid_argument("index is out of range");

    return *node->getData();
}

template<class T>
List<T>::List()  {
    this->head = nullptr;
}
