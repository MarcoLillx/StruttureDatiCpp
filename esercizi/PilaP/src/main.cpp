/*
 * main.cpp
 *
 *  Created on: 17 gen 2023
 *      Author: miche
 */

#include <iostream>
#include <stdio.h>

#include "PilaP.cpp"

using namespace std;

int main() {
	PilaP<int> Prova;
	Prova.StampaPila();
	Prova.Push(4);
	Prova.Push(52);
	Prova.StampaPila();
	Prova.Pop();
	Prova.StampaPila();

	system("pause");

	return 0;
}



