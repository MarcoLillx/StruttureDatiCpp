/*
 * eo_string.h
 *
 *  Created on: 29 gen 2023
 *      Author: miche
 */

#ifndef EO_STRING_H_
#define EO_STRING_H_

#include <iostream>
#include <string>
#include <cctype>
#include "Lista_Collegata.cpp"

using namespace std;

class eo_strings {
public:
	typedef typename lista_collegata<string>::posizione posx;

	eo_strings();
	~eo_strings();
	int conta_caratteri(string s);
	void inserisci_elemento(string s);
	void rimuovi_elemento(string s);
	void rimuovi(char c);
	int freq_pari();
	void visualizza_dispari();
	void visualizza_pari();
	void insertion_sort();
private:
	lista_collegata<string> pari;
	lista_collegata<string> dispari;
};

eo_strings::eo_strings() {
}

eo_strings::~eo_strings() {
}

int eo_strings::conta_caratteri(string s) {
	return (s.size());
}

void eo_strings::inserisci_elemento(string s) {
	if (s.size() % 2 == 0) {
		pari.inserisci_in_testa(s);
	} else {
		dispari.inserisci_in_testa(s);
	}
}

void eo_strings::rimuovi_elemento(string s) {
	posx pos;
	bool trovato = false;
	if (s.size() % 2 == 0) {
		pos = pari.primo_lista();
		while (pos != pari.ultimo_lista() && !trovato) {
			if (s == pari.leggi_elemento(pos)) {
				trovato = true;
				pari.rimuovi_elemento(pos);
			}
			pos = pari.successivo_lista(pos);
		}
	} else {
		pos = dispari.primo_lista();
		while (pos != dispari.ultimo_lista() && !trovato) {
			if (s == dispari.leggi_elemento(pos)) {
				trovato = true;
				dispari.rimuovi_elemento(pos);
			}
			pos = dispari.successivo_lista(pos);
		}

	}
}

void eo_strings::rimuovi(char c) {
	posx pos;
	pos = pari.primo_lista();
	while (pari.fine_lista(pos) == false) {
		if (toupper(c) == toupper(pari.leggi_elemento(pos)[0])) {
			pari.rimuovi_elemento(pos);
		}
		pos = pari.successivo_lista(pos);
	}
}

int eo_strings::freq_pari() {
	return (pari.lunghezza_lista());
}

void eo_strings::visualizza_dispari() {
	insertion_sort();
	dispari.stampa_lista();
	cout << "----------------" << endl;
}
void eo_strings::insertion_sort()
{
    posx i;
    i = dispari.successivo_lista(dispari.primo_lista());

    while (dispari.fine_lista(i) == false)
    {
        posx j;
        string chiave;

        chiave = dispari.leggi_elemento(i);
        j = dispari.precedente_lista(i);

        while (dispari.fine_lista(j) == false && chiave.size() < dispari.leggi_elemento(j).size())
        {
            string elem_j;
            elem_j = dispari.leggi_elemento(j);

            dispari.scrivi_elemento(elem_j, dispari.successivo_lista(j));

            j = dispari.precedente_lista(j);
        }

        dispari.scrivi_elemento(chiave, dispari.successivo_lista(j));
        i = dispari.successivo_lista(i);
    }
}
void eo_strings::visualizza_pari() {
	pari.stampa_lista();
	cout << "----------------" << endl;
}

#endif /* EO_STRING_H_ */
