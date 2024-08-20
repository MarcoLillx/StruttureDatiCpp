/*
 * Grid.h
 *
 *  Created on: 30 gen 2023
 *      Author: miche
 */

#ifndef GRID_H_
#define GRID_H_

#include "Lista_Collegata.h"
#include "Lista_Collegata.cpp"

class cell {
private:
	int x;
	int y;
	bool vivo;  			//false=morto, true=vivo

public:
	int leggix() {
		return x;
	}
	int leggiy() {
		return y;
	}
	bool leggi_vivo() {
		return vivo;
	}
	void scrivix(int x_nuovo) {
		x = x_nuovo;
	}
	void scriviy(int y_nuovo) {
		y = y_nuovo;
	}
	void scrivi_vivo(bool vivo_nuovo) {
		vivo = vivo_nuovo;
	}
};

class grid {
public:
	typedef typename lista_collegata<cell>::posizione posx;

	// inserisce una cella viva nella griglia
	void insert(cell&);
	// rimuove una cella nella griglia
	void remove(cell&);
	// sposta a sinistra di una posizione la cella viva presente in posizione (x,y)
	void moveLeft(int x, int y);
	// sposta a destra di una posizione la cella viva presente in posizione (x,y)
	void moveRight(int x, int y);
	// sposta in alto di una posizione la cella viva presente in posizione (x,y)
	void moveUpper(int x, int y);
	// sposta in basso di una posizione la cella viva presente in posizione (x,y)
	void moveDown(int x, int y);
	// stabilisce se la cella viva presente in posizione (x,y) `e circondata,
	// ovvero tutte le celle vicine alla cella data sono vive
	bool surrounded(int x, int y);
	// rimuove dalla griglia tutte le celle circondate
	void removeSurrounded();

private:
	lista_collegata<cell> cells;
	int n;
	int m;
};

void grid::insert(cell &c) {
	posx i = cells.primo_lista();
	bool inserito = false;

	if (c.leggi_vivo() == true) {
		if (!cells.lista_vuota()) {
			while (cells.fine_lista(i) == false && inserito == false) {
				if (c.leggix() == cells.leggi_elemento(i).leggix()
						&& c.leggiy() == cells.leggi_elemento(i).leggiy()) {
					cells.scrivi_elemento(c, i);
					inserito = true;
				} else {
					cells.inserisci_elemento(c, i);
					inserito = true;
				}
				i = cells.successivo_lista(i);
			}
		} else {
			cells.inserisci_in_testa(c);
		}
		cout << "La cella e' stata inserita." << endl;
	} else {
		cout << "La cella e' morta." << endl;
	}
}

void grid::remove(cell &c) {
	posx i = cells.primo_lista();
	while (cells.fine_lista(i) == false) {
		if (c.leggix() == cells.leggi_elemento(i).leggix()
				&& c.leggiy() == cells.leggi_elemento(i).leggiy()) {
			cells.rimuovi_elemento(i);
		}
		i = cells.successivo_lista(i);
		cout << "La cella e' stata rimossa." << endl;
	}
}

void grid::moveLeft(int x, int y) {
	posx i = cells.primo_lista();
	while (cells.fine_lista(i) == false) {
		if (x == cells.leggi_elemento(i).leggix()
				&& y == cells.leggi_elemento(i).leggiy()) {
			cells.leggi_elemento(i).scrivix(x - 1);
			cout << "La cella e' stata spostata a sinistra." << endl;
		}
		i = cells.successivo_lista(i);
	}
}

void grid::moveRight(int x, int y) {
	posx i = cells.primo_lista();
	while (cells.fine_lista(i) == false) {
		if (x == cells.leggi_elemento(i).leggix()
				&& y == cells.leggi_elemento(i).leggiy()) {
			cells.leggi_elemento(i).scrivix(x + 1);
			cout << "La cella e' stata spostata a destra." << endl;
		}
		i = cells.successivo_lista(i);
	}
}

void grid::moveUpper(int x, int y) {
	posx i = cells.primo_lista();
	while (cells.fine_lista(i) == false) {
		if (x == cells.leggi_elemento(i).leggix()
				&& y == cells.leggi_elemento(i).leggiy()) {
			cells.leggi_elemento(i).scriviy(y - 1);
			cout << "La cella e' stata spostata in alto." << endl;
		}
		i = cells.successivo_lista(i);
	}
}

void grid::moveDown(int x, int y) {
	posx i = cells.primo_lista();
	while (cells.fine_lista(i) == false) {
		if (x == cells.leggi_elemento(i).leggix()
				&& y == cells.leggi_elemento(i).leggiy()) {
			cells.leggi_elemento(i).scriviy(y + 1);
			cout << "La cella e' stata spostata in basso." << endl;
		}
		i = cells.successivo_lista(i);
	}
}

bool grid::surrounded(int x, int y) {
	posx i = cells.primo_lista();
	bool c_up, c_down, c_r, c_l = false;

	bool circondato = false;

	while (cells.fine_lista(i) == false && circondato == false) {
		if ((cells.leggi_elemento(i).leggix() == (x - 1)) && cells.leggi_elemento(i).leggiy() == y
				&& (cells.leggi_elemento(i).leggi_vivo() == true)) {
			c_l = true;
		}
		if ((cells.leggi_elemento(i).leggix() == (x + 1)) && cells.leggi_elemento(i).leggiy() == y
				&& (cells.leggi_elemento(i).leggi_vivo() == true)) {
			c_r = true;
		}
		if ((cells.leggi_elemento(i).leggiy() == (y - 1)) && cells.leggi_elemento(i).leggix() == x
				&& (cells.leggi_elemento(i).leggi_vivo() == true)) {
			c_up = true;
		}
		if ((cells.leggi_elemento(i).leggiy() == (y + 1)) && cells.leggi_elemento(i).leggix() == x
				&& (cells.leggi_elemento(i).leggi_vivo() == true)) {
			c_down = true;
		}

		if (c_l && c_r && c_up && c_down) {
			cout << "La cella e' circondata da celle vive." << endl;
			circondato = true;
		}

		i = cells.successivo_lista(i);
		cout << circondato << endl;
	}
	if (circondato == false){
		cout << "La cella non e' circondata da celle vive." << endl;
	}
	return circondato;
}



#endif /* GRID_H_ */
