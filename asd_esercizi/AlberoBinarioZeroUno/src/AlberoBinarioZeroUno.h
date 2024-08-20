/*
 * AlberoBinarioZeroUno.h
 *
 *  Created on: 10 feb 2023
 *      Author: Silvano
 */

#ifndef ALBEROBINARIOZEROUNO_H_
#define ALBEROBINARIOZEROUNO_H_

#include <iostream>
#include "albero_binario_collegato.h"

using namespace std;

template<class T>
class zero_one_binary_tree {
public:
	/* Stabilisce se l’albero rispetta le propiet`a di un albero zero-one, ovvero:
	 * 1) la radice ha valore 0;
	 * 2) ogni nodo 0, ha come figli due nodi 1;
	 * 3) ogni nodo 1, ha come figli due nodi 0.
	 */
	bool is_zero_one(const albero_binario_collegato<T> &B);
	bool is_zero_one(const albero_binario_collegato<T> &B, nodo_albero<T> *n);

	/* Restituisce il numero di nodi 0 dell’abero */
	int zero_nodes(const albero_binario_collegato<T> &B);
	int zero_nodes(const albero_binario_collegato<T> &B, nodo_albero<T> *n);
};

template<class T>
bool zero_one_binary_tree<T>::is_zero_one(
		const albero_binario_collegato<T> &B) {

	if (!B.vuoto() && B.radice()->leggi_nodo() == 0) {
		return (true and is_zero_one(B,B.radice()) && is_zero_one(B,B.radice()));
	}

	return false;
}
template<class T>
bool zero_one_binary_tree<T>::is_zero_one(const albero_binario_collegato<T> &B,
		nodo_albero<T> *n) {

	if (n != nullptr) {
		if (n->leggi_nodo() == 0 && B.nodo_sx(n)->leggi_nodo() == 1
				&& B.nodo_dx(n)->leggi_nodo() == 1)
			return (true && is_zero_one(B, B.nodo_sx(n))
					&& is_zero_one(B, B.nodo_dx(n)));
		else if (n->leggi_nodo() == 1 && B.nodo_sx(n)->leggi_nodo() == 0
				&& B.nodo_dx(n)->leggi_nodo() == 0)
			return (true && is_zero_one(B, B.nodo_sx(n))
					&& is_zero_one(B, B.nodo_dx(n)));
		else if(B.foglia(n))
			return true;
	}

	return false;
}
template<class T>
int zero_one_binary_tree<T>::zero_nodes(const albero_binario_collegato<T> &B) {

	if (!B.vuoto() && B.radice()->leggi_nodo() == 0) {
		return (zero_nodes(B, B.radice()));
	}
	return 0;
}
template<class T>
int zero_one_binary_tree<T>::zero_nodes(const albero_binario_collegato<T> &B, nodo_albero<T> *n) {

	if (n != nullptr && n->leggi_nodo() == 0) {
		return (1 + zero_nodes(B, B.nodo_sx(n)) + zero_nodes(B, B.nodo_dx(n)));
	}
	if(n != nullptr && n->leggi_nodo()==1){
		return (zero_nodes(B, B.nodo_sx(n)) + zero_nodes(B, B.nodo_dx(n)));
	}
	return 0;
}
#endif /* ALBEROBINARIOZEROUNO_H_ */
