#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
	Node<T>* start;
	int nodes;
	
public:
	List();
	T front();
	T back();
	void push_front(T value);
	void push_back(T value);
	void pop_front();
	void pop_back();
	T get(int position);
	void concat(List<T> &other);
	bool empty();
	int size();
	void clear();
	Iterator<T> begin();
	Iterator<T> end();
	void print(){
		Node<T>* it = start;
		for(int i = 0; i<nodes; ++i) {
			cout << it->data << " \n"[i==nodes-1];
			it = it->next;
		}
	}
	~List();
};

template <typename T>
List<T>::List(){
	start = nullptr;
	nodes = 0;
}

template <typename T>
T List<T>::front(){
	return start->data; // Falta validar si la lista está vacía
}
template <typename T>
T List<T>::back(){
	return start->prev->data; // Falta validar si la lista está vacía
}
template <typename T>
void List<T>::push_front(T value){
	Node<T>* node = new Node<T>;
	node->data = value;
	nodes++;
	if( start == nullptr ){
		node->next = node;
		node->prev = node;
	}else{
		node->next = start;
		node->prev = start->prev;
		start->prev->next = node;
		start->prev = node;
	}
	start = node;
}
template <typename T>
void List<T>::push_back(T value){
	nodes++;
	Node<T>* node = new Node<T>;
	node->data = value;
	if( start == nullptr ){
		node->next = node;
		node->prev = node;
		start = node;
	}else{
		node->next = start;
		node->prev = start->prev;
		start->prev->next = node;
		start->prev = node;
	}
	start = node;	
}
template <typename T>
void List<T>::pop_front(){
	if( nodes ){
		nodes--;
		if(nodes == 0){
			delete start;
			start = nullptr;
			return;
		}
		Node<T>* tmpnode = start;
		start->prev->next = start->next;
		start->next->prev = start->prev;
		start = start->next;
		delete tmpnode;
	}
}
template <typename T>
void List<T>::pop_back(){
	if( nodes ){
		nodes--;
		if(nodes == 0){
			delete start;
			start = nullptr;
			return;
		}
		Node<T>* tmpnode = start->prev;
		start->prev->prev->next = start;
		start->prev = start->prev->prev;

		delete tmpnode;
	}
}
template <typename T>
T List<T>::get(int position){
	Iterator<T> it = begin();
	for(int i=0; i<position; ++i){
		++it;
	}
	return *it;
}
template <typename T>
void List<T>::concat(List<T> &other){
	for(Iterator<T> it = begin(); it != end() ; ++it){
		push_back(*it);
	}
	nodes += other.size();
}
template <typename T>
bool List<T>::empty(){
	return start == nullptr;
}
template <typename T>
int List<T>::size(){
	return nodes;
}
template <typename T>
void List<T>::clear(){
	while(size()){
		pop_front();
	}
}
template <typename T>
Iterator<T> List<T>::begin(){
	Iterator<T> s(start);
	return s;
}
template <typename T>
Iterator<T> List<T>::end(){
	Iterator<T> e(start->prev);
	return e;	
}
template <typename T>
List<T>::~List(){
	clear();
}
#endif
