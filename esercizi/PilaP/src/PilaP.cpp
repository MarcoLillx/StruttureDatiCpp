//============================================================================
// Name        : PilaP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "PilaP.h"

using namespace std;

template<class tipoelem>
PilaP<tipoelem>::PilaP() {
	testa = nullptr;
}

template<class tipoelem>
PilaP<tipoelem>::~PilaP() {
	while (!empty()) {
		Pop();
	}
}

template<class tipoelem>
bool PilaP<tipoelem>::empty() {
	return (testa == nullptr);
}

template<class tipoelem>
void PilaP<tipoelem>::Pop() {
	if (!empty()) {
		struct Nodo *temp = new Nodo;
		temp = testa;
		testa = temp->next;
		delete temp;
	} else {
		cout << "La pila e' vuota" << endl;
	}
}

template<class tipoelem>
void PilaP<tipoelem>::Push(tipoelem e) {
	struct Nodo *temp = new Nodo;
	temp->valore = e;
	temp->next = testa;
	testa = temp;
}

template<class tipoelem>
tipoelem PilaP<tipoelem>::GetValore() {
	if (!empty()) {
		return testa->valore;
	} else {
		cout << "La pila e' vuota" << endl;
		return 0;
	}
}

template<class tipoelem>
void PilaP<tipoelem>::StampaPila(){
	struct Nodo *temp = new Nodo;
	temp = testa;
	while(temp!=nullptr){
		cout<< temp->valore << " ";
		temp = temp->next;
	}
}

