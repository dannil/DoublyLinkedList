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
        
        int size() const;
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
        delete sentinel->next;
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
    T data = sentinel->next->data;
    delete sentinel->next;
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
    T data = sentinel->previous->data;
    delete sentinel->previous;
    return data;
}

template<typename T>
T LinkedList<T>::get(int i) const {
    if (i < size / 2) {
        // Loop first to last
        Node<T>* node = sentinel->next;
        for (int j = 0; j < i; j++) {
            node = node->next;
        }
        return node->data;
    } else {
        // Loop last to first
        Node<T>* node = sentinel->previous;
        for (int j = i; j >= i; j--) {
            node = node->previous;
        }
        return node->data;
    }
}

template<typename T>
Node<T>* LinkedList<T>::getFirst() const {
    return sentinel->next;
}

template<typename T>
Node<T>* LinkedList<T>::getLast() const {
    return sentinel->previous;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    // If the sentinel nodde points to itself, it means that
    // the list is empty of nodes
    if (sentinel == sentinel->next) {
        return true;
    }
    return false;
}

template<typename T>
int LinkedList<T>::size() const {
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