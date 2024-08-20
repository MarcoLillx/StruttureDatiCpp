/*
 * PileP.h
 *
 *  Created on: 17 gen 2023
 *      Author: miche
 */

#ifndef CODEP_H_
#define CODEP_H_

#include <iostream>
#include <stdio.h>

using namespace std;

template<class tipoelem>
class CodeP{
private:
	struct Nodo{
		tipoelem valore;
		Nodo *next;
	};
	Nodo *testa;
	Nodo *coda;
	int lunghezza;
public:
	CodeP();
	~CodeP();
	bool empty();
	void Pop();
	void Push(tipoelem);
	tipoelem GetValore();
	void StampaCoda();
};



#endif /* CODEP_H_ */
