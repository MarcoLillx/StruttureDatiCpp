//============================================================================
// Name        : CodeP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>

#include "CodeP.cpp"

using namespace std;

int main() {
	CodeP<int> Prova;
	Prova.Push(14);
	Prova.StampaCoda();
	Prova.Pop();
	Prova.Push(22);
	Prova.Push(89);
	Prova.Push(76);
	Prova.StampaCoda();
	Prova.Pop();
	Prova.StampaCoda();

	system("pause");
	return 0;
}
