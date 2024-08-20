/*
 * Lista.h
 *
 *  Created on: 12 gen 2023
 *      Author: miche
 */

#ifndef LISTA_H_
#define LISTA_H_

// includo il file che contiene la classe virtuale principale
#include "lista_lineare.h"
#include <iostream>

using namespace std;

// definisco un valore con cui inizializzare gli elementi vuoti
#define VALORE_INIZIALIZZAZIONE 0

// forward declaration della classe lista_puntatori
template <class T>
class lista_collegata;

/*
 * Definisco la classe nodo
*/
template <class T>
class nodo_lista
{
    // definsco classe amica che può accedere a variabili e metodi privati della classe lista_nodo
    friend class lista_collegata<T>;

private:
    T valore_nodo;
    nodo_lista<T> *precedente;
    nodo_lista<T> *successivo;
};

/**
 * Definisco una classe "figlia" della classe lista_lineare
*/
template <class T>
class lista_collegata : public lista_lineare<T, nodo_lista<T> *>
{
public:
    typedef typename lista_lineare<T, nodo_lista<T> *>::tipoelem tipoelem;
    typedef typename lista_lineare<T, nodo_lista<T> *>::posizione posizione;

    // costruttore
    lista_collegata();
    lista_collegata(int dimensione_lista);

    // costruttore di copia
    lista_collegata(const lista_collegata<T> &lista_copiata);

    // distruttore
    ~lista_collegata();

    // operatori

    // metodo che controlla se la lista e' vuota
    bool lista_vuota() const;

    // metodo per leggere la lunghezza della lista
    int lunghezza_lista() const;

    // metodo per scrivere un elemento in una determinata lista_collegata::posizione
    void scrivi_elemento(const tipoelem &elemento_scritto, posizione posizione_elemento);

    // metodo per leggere un elemento in una determinata poszione della lista
    tipoelem leggi_elemento(posizione posizione_selezionata) const;

    // metodo per leggere la lista_collegata::posizione del primo elemento della lista
    posizione primo_lista() const;

    // metdo per leggere l'ultima posizione nella lista
    posizione ultimo_lista() const;

    // metodo per controllare se una determinata lista_collegata::posizione e' l'ultima della lista
    bool fine_lista(posizione posizione_selezionata) const;

    // metodo per leggere la lista_collegata::posizione precedente del nodo nella lista
    posizione precedente_lista(posizione posizione_attuale) const;

    // metodo per per leggere la poszione successiva nel nodo nella lista
    posizione successivo_lista(posizione posizione_attuale) const;

    // metodo per inserire un elemento nella lista
    void inserisci_elemento(const tipoelem &elemento_inserito, posizione posizione_selezionata);

    // metodo per cancellare dalla lista un elemento in una determinata poszione
    void rimuovi_elemento(posizione nodo_eliminato);

    // metodo per inserire un elemento in testa alla lista
    void inserisci_in_testa(const tipoelem &elemento_inserito);

    // metodo per stampare tutti i valori della lista
    void stampa_lista();

    // sovraccarico operatore di assegnamento
    lista_collegata &operator=(const lista_collegata &lista_assegnata);

    // sovraccarico l'operatore di uguaglianza
    bool operator==(const lista_collegata &lista_confrontata) const;

    // ordinamento per inserzione sulla lista
    void insertion_sort();

    // metodo per eliminare una lista
    void elimina_lista();

    // metodo per scambiare due elementi in una lista
    void scambia_elementi(posizione p1, posizione p2);

private:
    nodo_lista<T> *testa;
    int lunghezza;
};

#endif /* LISTA_H_ */
