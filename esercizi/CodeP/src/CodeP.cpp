/*
 * CodeP.cpp
 *
 *  Created on: 17 gen 2023
 *      Author: miche
 */

#include "CodeP.h"

using namespace std;

template<class tipoelem>
CodeP<tipoelem>::CodeP(){
	testa = NULL;
	coda = NULL;
	lunghezza = 0;
}

template<class tipoelem>
CodeP<tipoelem>::~CodeP(){
	if(!empty()){
		delete testa;
	}
}

template<class tipoelem>
bool CodeP<tipoelem>::empty(){
	return (testa==NULL);
}

template<class tipoelem>
void CodeP<tipoelem>::Pop(){
	Nodo *temp = new Nodo;
	if(!empty()){
		temp = testa;
		testa = testa->next;
		delete temp;
		lunghezza--;
	} else {
		cout << "La coda e' vuota"<<endl;
	}
}

template<class tipoelem>
void CodeP<tipoelem>::Push(tipoelem e){
	Nodo *temp = new Nodo;
	if (!empty()){
		coda->next = temp;
		temp->next = NULL;
		temp->valore = e;
		coda = temp;
		lunghezza++;
	}else{
		temp->valore = e;
		testa = coda = temp;
		lunghezza++;
	}
}

template<class tipoelem>
void CodeP<tipoelem>::StampaCoda(){
	Nodo *temp = new Nodo;
	temp = testa;
	while(temp!=NULL){
		cout << temp->valore<< " ";
		temp = temp->next;
	}
	cout << endl;
}


