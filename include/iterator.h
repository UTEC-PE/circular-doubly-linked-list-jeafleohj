#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
private:
	Node<T>* current;
    
public:
	Iterator();
	Iterator(Node<T>* node);
	Iterator<T> operator=(Iterator<T> node);
	bool operator!=(Iterator<T> cmp);
	Iterator<T> operator++();
	Iterator<T> operator++(int);	
	Iterator<T> operator--();
	T operator*();
};

template <typename T>
Iterator<T>::Iterator(){
	current = nullptr;
}

template <typename T>
Iterator<T>::Iterator(Node<T>* node)
	: current(node)
{}

template <typename T>
Iterator<T> Iterator<T>::operator=(Iterator<T> node){
	current = node.current;
	return *this;
}

template <typename T>
bool Iterator<T>::operator!=(Iterator<T> cmp){
	return (current != cmp.current);
}

template <typename T>
Iterator<T> Iterator<T>::operator++(){
	current = current -> next;
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int){
	current = current -> next;
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(){
	current = current -> prev;
	return *this;	
}

template <typename T>
T Iterator<T>::operator*(){
	return current->data;
}
#endif
