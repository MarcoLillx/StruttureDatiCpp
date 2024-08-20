/*
 * PilaP.h
 *
 *  Created on: 17 gen 2023
 *      Author: miche
 */

#ifndef PILAP_H_
#define PILAP_H_

#include <stdio.h>
#include <iostream>

template<class tipoelem>
class PilaP{
private:
	struct Nodo{
		tipoelem valore;
		Nodo *next;
	};
	Nodo *testa;
public:
	PilaP();
	~PilaP();
	bool empty();
	void Pop();
	void Push(tipoelem);
	tipoelem GetValore();
	void StampaPila();
};



#endif /* PILAP_H_ */
