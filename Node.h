#ifndef NODE_H
#define NODE_H

#include "LinkedList.h"

template<typename T>
class Node {

    private:
        T data;
        Node<T> *previous, *next;

    public:
        Node<T>() : previous(this), next(this) { } // Sentinel node
        Node<T>(T data, Node<T>* previous, Node<T>* next) : data(data), previous(previous), next(next) {
            this->previous->next = this;
            this->next->previous = this;
        }
        ~Node<T>() {
            // Delete links to the object by assigning
            // previous and next new links
            this->previous->next = next;
            this->next->previous = previous;
        }
        T getData();
        Node<T>* getPrevious() const;
        Node<T>* getNext() const;
        Node<T>* insertBefore(const T& data);
        Node<T>* insertAfter(const T& data);
};

template<typename T>
T Node<T>::getData() {
    return this->data;
}

template<typename T>
Node<T>* Node<T>::getPrevious() const {
    return this->previous;
}

template<typename T>
Node<T>* Node<T>::getNext() const {
    return this->next;
}

template<typename T>
Node<T>* Node<T>::insertBefore(const T& data) {
    new Node<T>(data, this->previous, this);
}

template<typename T>
Node<T>* Node<T>::insertAfter(const T& data) {
    new Node<T>(data, this, this->next);
}

#endif
