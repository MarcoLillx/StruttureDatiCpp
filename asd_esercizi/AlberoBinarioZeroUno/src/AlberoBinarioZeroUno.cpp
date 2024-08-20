//============================================================================
// Name        : AlberoBinarioZeroUno.cpp
// Author      : Marco
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AlberoBinarioZeroUno.h"
#include "albero_binario_collegato.h"

using namespace std;

int main() {

	nodo_albero<int> *n1, *n2, *n3, *n4;

	albero_binario_collegato<int> a1;

	a1.inserisci_radice(0);

	n1 = a1.radice();
	a1.inserisci_sx(n1, 1);
	a1.inserisci_dx(n1, 1);

	n2 = a1.nodo_sx(n1);
	a1.inserisci_sx(n2, 0);
	a1.inserisci_dx(n2, 0);

	/* a1.stampa_albero(n1);

	 cout << a1.profondita(n1);*/

	cout << "\n\n";
	a1.stampa_albero(n1);

	zero_one_binary_tree<int> zot;

	int zeri;
	zeri = zot.zero_nodes(a1);

	cout << "Numero di zeri nell'albero: " << zeri << endl;

	cout << "E' un albero binario zero one?(0:no, 1:si) = " << zot.is_zero_one(a1)<<endl;

	system("pause");
	return 0;
}
