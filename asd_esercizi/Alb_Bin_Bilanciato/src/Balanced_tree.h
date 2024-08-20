/*
 * Balanced_tree.h
 *
 *  Created on: 30 gen 2023
 *      Author: miche
 */

#ifndef BALANCED_TREE_H_
#define BALANCED_TREE_H_

#include "albero_binario_collegato.h"

template<class tipoelem>
class balanced_tree {
public:
	/* Stabilisce se l’albero `e bilanciato in altezza.
	 * Un albero binario `e bilanciato in altezza se a) `e vuoto, o b) se per ogni nodo
	 * le altezze dei suoi due sottoalberi differiscono al pi`u di uno e i due sottoalberi
	 * sono bilanciati in altezza.
	 */
	bool is_height_balanced(const albero_binario_collegato<tipoelem> &B);
	/* Stabilisce se tutti i nodi non foglia dell’albero hanno esattamente due figli */
	bool complete_nodes(const albero_binario_collegato<tipoelem> &B);

    bool complete_nodes(nodo_albero<tipoelem> n);

};

template<class tipoelem>
bool balanced_tree<tipoelem>::is_height_balanced(
		const albero_binario_collegato<tipoelem> &B) {
	// Check for emptiness
	int lh = 0, rh = 0;

	// If tree is empty then return true
	if (B.foglia(B.radice())) {
		cout << "L'albero ha solo la radice." << endl;
		return 1;
	}

	// Get the height of left and right sub trees
	lh = B.profondita(B.nodo_sx(B.radice()));
	rh = B.profondita(B.nodo_dx(B.radice()));

	if (abs(lh - rh) <= 1) {
		cout << "L'albero e' bilanciato." << endl;
		return 1;
	}
	// If we reach here then tree is not height-balanced
	cout << "L'albero non e' bilanciato." << endl;
	return 0;
}

template<class tipoelem>
bool balanced_tree<tipoelem>::complete_nodes(
		const albero_binario_collegato<tipoelem> &B) {

	if (!B.foglia(B.radice())) {
		return true;
	}

	else if (B.nodo_sx(B.radice()) != nullptr
			&& B.nodo_dx(B.radice()) != nullptr) {
		return (true && complete_nodes(B.nodo_sx(B.radice())) && complete_nodes(B.nodo_dx(B.radice())));
	}

	return false;
}

template<class tipoelem>
bool balanced_tree<tipoelem>::complete_nodes(nodo_albero<tipoelem> nodo) {
	if (!foglia(nodo)) {
		return true;
	}

	else if (nodo_sx(nodo) != nullptr
			&& nodo_dx(nodo) != nullptr) {
		return (true && complete_nodes(nodo_sx(nodo))
				&& complete_nodes(nodo_dx(nodo)));
	}

	return false;
}

#endif /* BALANCED_TREE_H_ */
