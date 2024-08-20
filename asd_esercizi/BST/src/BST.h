/*
 * BST.h
 *
 *  Created on: 11 feb 2023
 *      Author: Silvano
 */

#ifndef BST_H_
#define BST_H_

#include "albero_binario_collegato.h"

class BST{
public:
	//stabilisce se l'albero binario rispetta i vincoli di un BST
	bool is_bst();

	//inserisce in modo ordinato nel BST il valore passato
	void insert(int v);

	//restituisce il valore minimo del BST
	int min();

	void stampa();

private:
	albero_binario_collegato<int> T;
	int min(nodo_albero<int> *n);
	bool is_bst(nodo_albero<int> *n);
};

bool BST::is_bst(){
	if(!T.vuoto()){
		return (is_bst(T.radice()));
	}
	return true;
}
bool BST::is_bst(nodo_albero<int> *n){
	/*if(n!= nullptr && T.nodo_sx(n)->leggi_nodo() < n->leggi_nodo() && n->leggi_nodo() < T.nodo_dx(n)->leggi_nodo()){

		return(true && is_bst(T.nodo_sx(n)) && is_bst(T.nodo_dx(n)));
	}*/
	if(n==nullptr)
		return true;

	if(T.nodo_sx(n)!= nullptr && T.nodo_sx(n)->leggi_nodo() > n->leggi_nodo()){
		return false;
	}

	if(T.nodo_dx(n)!= nullptr && T.nodo_dx(n)->leggi_nodo() < n->leggi_nodo()){
		return false;
	}

	if(!is_bst(T.nodo_sx(n)) || !is_bst(T.nodo_dx(n))){
		return false;
	}
	return true;
}

void BST::insert(int v){

	nodo_albero<int> *n;
	if(T.vuoto()){
		T.inserisci_radice(v);
	}
	else{
		n = T.radice();
		bool valido = true;
		while(valido){
			if(v < n->leggi_nodo() && T.nodo_sx(n)!=nullptr){
				n = T.nodo_sx(n);
			}
			else if(v > n->leggi_nodo() && T.nodo_dx(n)!=nullptr){
				n = T.nodo_dx(n);
			}
			else valido = false;
		}
		if(v < n->leggi_nodo())
			T.inserisci_sx(n,v);
		else
			T.inserisci_dx(n,v);
	}
}

int BST::min(){
	if(!T.vuoto())
		return min(T.radice());

	return 0;
}

int BST::min(nodo_albero<int> *n){

	if(T.nodo_sx(n)==nullptr)
		return n->leggi_nodo();

	return min(T.nodo_sx(n));

}
void BST::stampa(){
	T.stampa_albero(T.radice());
}
#endif /* BST_H_ */
