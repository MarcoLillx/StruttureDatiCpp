//============================================================================
// Name        : BST.cpp
// Author      : Marco
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "BST.h"

int main() {

	BST albero_ricerca;

	albero_ricerca.insert(10);
	albero_ricerca.insert(7);
	albero_ricerca.insert(5);
	albero_ricerca.insert(12);
	albero_ricerca.insert(8);
	albero_ricerca.insert(2);
	albero_ricerca.insert(9);
	albero_ricerca.insert(6);
	cout << "\n\n";
	albero_ricerca.stampa();

	cout << "Il minimo e': " << albero_ricerca.min() << endl;
	cout << "BST: " << albero_ricerca.is_bst() << endl;
	system("pause");
	return 0;
}
