//============================================================================
// Name        : Alb_Bin_Bilanciato.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "albero_binario_collegato.h"
#include "Balanced_tree.h"

int main() {
	balanced_tree<int> Tree;
	nodo_albero<int> *n1, *n2, *n3, *n4;

	albero_binario_collegato<int> a1;

	a1.inserisci_radice(1);

	n1 = a1.radice();
	a1.inserisci_sx(n1, 3);
	a1.inserisci_dx(n1, 2);

	n2 = a1.nodo_sx(n1);
	a1.inserisci_sx(n2, 9);
	a1.inserisci_dx(n2, 19);
	/* a1.stampa_albero(n1);

	 cout << a1.profondita(n1);*/
	n3 = a1.nodo_sx(n2);
	a1.inserisci_sx(n3, 5);

	n4 = a1.nodo_dx(n1);
	a1.inserisci_sx(n4, 7);

	cout << "\n\n";
	a1.stampa_albero(n1);

	bool bilanciato = Tree.is_height_balanced(a1);

	bool completo = Tree.complete_nodes(a1);
	if (completo == true){
		cout << "Tutti i nodi non foglia hanno due figli." << endl;
	} else {
		cout << "Non tutti i nodi non foglia hanno due figli." << endl;
	}

	system("pause");

	return 0;
}
