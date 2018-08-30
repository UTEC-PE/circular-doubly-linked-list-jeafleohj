#ifndef NODE_H
#define NODE_H

#include <iostream>


template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};
#endif
