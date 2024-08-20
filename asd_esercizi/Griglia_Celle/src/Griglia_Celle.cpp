//============================================================================
// Name        : Griglia_Celle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Grid.h"
using namespace std;

int main() {
	grid Prova;
	cell c1, c2, c3, c4, c5;
	c1.scrivix(2);
	c1.scriviy(2);
	c1.scrivi_vivo(true);
	c2.scrivix(1);
	c2.scriviy(2);
	c2.scrivi_vivo(true);
	c3.scrivix(2);
	c3.scriviy(1);
	c3.scrivi_vivo(true);
	c4.scrivix(3);
	c4.scriviy(2);
	c4.scrivi_vivo(true);
	c5.scrivix(2);
	c5.scriviy(3);
	c5.scrivi_vivo(true);

	Prova.insert(c1);
	Prova.insert(c2);
	Prova.insert(c2);
	Prova.insert(c4);
	Prova.insert(c5);

//	Prova.moveRight(1, 1);
//	Prova.moveLeft(3, 1);

	Prova.surrounded(2, 2);





	system("pause");

	return 0;
}
