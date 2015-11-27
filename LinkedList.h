#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>

#include "Node.h"

using namespace std;

template<typename T>
class Node;

template<typename T>
class LinkedList {

    private:
        int size;
        Node<T> *sentinel;

    public:
        LinkedList<T>();
        ~LinkedList<T>();
        
        void addFront(const T data);
        void addBack(const T data);
        
        T popFront();
        T popBack();
        
        T get(int i) const;
        Node<T>* getFirst() const;
        Node<T>* getLast() const;
        
        int getSize() const;
        bool isEmpty() const;
};

template<typename T>
LinkedList<T>::LinkedList() {
    // Sentinel node
    size = 0;
    sentinel = new Node<T>();
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (!isEmpty()) {
        delete sentinel->getNext();
    }
    delete sentinel;
}

template<typename T>
void LinkedList<T>::addFront(const T data) {
    size++;
    sentinel->insertAfter(data);
}

template<typename T>
void LinkedList<T>::addBack(const T data) {
    size++;
    sentinel->insertBefore(data);
}

template<typename T>
T LinkedList<T>::popFront() {
//    if (isEmpty()) {
//        throw std::out_of_range("LinkedList is empty");
//    }
    if (!isEmpty()) {
        size--;
    }
    T data = sentinel->getNext()->getData();
    delete sentinel->getNext();
    return data;
}

template<typename T>
T LinkedList<T>::popBack() {
//    if (isEmpty()) {
//        throw std::out_of_range("LinkedList is empty");
//    }
    if (!isEmpty()) {
        size--;
    }
    T data = sentinel->getPrevious()->getData();
    delete sentinel->getPrevious();
    return data;
}

template<typename T>
T LinkedList<T>::get(int i) const {
    if (i < size / 2) {
        // Loop first to last
        Node<T>* node = sentinel->getNext();
        for (int j = 0; j < i; j++) {
            node = node->getNext();
        }
        return node->getData();
    } else {
        // Loop last to first
        Node<T>* node = sentinel->getPrevious();
        for (int j = i; j >= i; j--) {
            node = node->getPrevious();
        }
        return node->getData();
    }
}

template<typename T>
Node<T>* LinkedList<T>::getFirst() const {
    return sentinel->getNext();
}

template<typename T>
Node<T>* LinkedList<T>::getLast() const {
    return sentinel->getPrevious();
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    // If the sentinel nodde points to itself, it means that
    // the list is empty of nodes
    if (sentinel == sentinel->getNext()) {
        return true;
    }
    return false;
}

template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, LinkedList<T>& list) {
    std::string s;
    
    // Not empty
    if (!list.isEmpty()) {
        s += "[";
        Node<T>* node = list.getFirst();
        while (node != list.getLast()) {
            s += std::to_string(node->getData()) + ", ";
            node = node->getNext();
        }
        s += std::to_string(list.getLast()->getData()) + "]";
    } else {
        s = "[]";
    }
    
    return stream << s;
}

#endif