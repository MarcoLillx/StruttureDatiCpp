//============================================================================
// Name        : PariDispari_StringList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "eo_string.h"
using namespace std;

int main() {
	eo_strings Prova;
	Prova.inserisci_elemento("Marco");
	Prova.inserisci_elemento("mulo");
	Prova.inserisci_elemento("Cina");
	Prova.inserisci_elemento("Michele");
	Prova.inserisci_elemento("Mela");
	Prova.inserisci_elemento("Dio");
	Prova.inserisci_elemento("Porco");
	Prova.inserisci_elemento("Cane");
	Prova.inserisci_elemento("Ano");
	Prova.inserisci_elemento("Zorro");

	Prova.visualizza_pari();
	Prova.visualizza_dispari();

	Prova.rimuovi_elemento("Mela");

	Prova.rimuovi('m');

	Prova.visualizza_pari();


	system("pause");

	return 0;
}
