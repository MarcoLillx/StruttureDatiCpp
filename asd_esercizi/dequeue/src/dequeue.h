/*
 * dequeue.h
 *
 *  Created on: 28 nov 2020
 *      Author: Marco
 */

#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#include <iostream>
using namespace std;

template <class T>
class dequeue{
public:
	struct node{
		T value;
		node* next;
		node* prev;
	};
	/*costruttore*/
	dequeue(){
		head = tail = nullptr;
	}
	/*inserimento in testa*/
	void push_front(T e){
		node *n = new node;
		n->value = e;
		n->next = head;
		n->prev = nullptr;
		head = n;
	}
	/*inserimento in coda*/
	void push_back(T e){
		node *n = new node;
		n-> value = e;
		n->next = nullptr;
		n->prev = tail;
		tail = n;
	}
	/*cancellazione in coda*/
	T pop_back(){
		T t = tail->value;	//valore di tipo T di cui fare il pop in coda
		node *n = tail;
		tail = tail->prev;
		tail->next = nullptr;
	}
private:
	node *head;
	node *tail;

};



#endif /* DEQUEUE_H_ */
