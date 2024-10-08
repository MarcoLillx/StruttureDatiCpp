/*
 * Lista.cpp
 *
 *  Created on: 16 gen 2023
 *      Author: miche
 */

#include "Lista_Collegata.h"

using namespace std;

template <class T>
lista_collegata<T>::lista_collegata()
{
    // creo il nodo sentinella e assegno il valore alla testa della lista
    testa = new nodo_lista<T>;

    // poiche' la lista è vuota, il nodo precedente e il nodo successivo del nodo testa  punteranno al nodo stesso
    testa->precedente = testa;
    testa->successivo = testa;

    // assegno il valore della lunghezza
    lunghezza = 0;
}

template <class T>
lista_collegata<T>::lista_collegata(int dimensione_lista)
{
    if (dimensione_lista > 0)
    {
        // assegno il valore della lunghezza
        lunghezza = dimensione_lista;

        // creo la lista con valori di defualt
        for (int i = 0; i < lunghezza; i++)
        {
            inserisci_in_testa(VALORE_INIZIALIZZAZIONE);
        }
    }
}

template <class T>
lista_collegata<T>::lista_collegata(const lista_collegata<T> &lista_copiata)
{
    lunghezza = lista_copiata.lunghezza_lista();

    // inizializzo la nuova lista
    testa = new nodo_lista<T>;
    testa->precedente = testa;
    testa->successivo = testa;

    // verifico che la lista che sto copiando nono e' vuota
    if (lista_copiata.lista_vuota() == false)
    {
        // seleziono la prima posizione della lista copiata
        posizione nodo_copiato = lista_copiata.primo_lista();

        while (lista_copiata.fine_lista(nodo_copiato) == false)
        {
            inserisci_in_testa(nodo_copiato->valore_nodo);
            nodo_copiato = lista_copiata.successivo_lista(nodo_copiato);
        }
    }
}

template <class T>
lista_collegata<T>::~lista_collegata()
{
    // finche la lista non e' vuota elimino i nodi
    while (!lista_vuota())
    {
        rimuovi_elemento(primo_lista());
    }
    // elimino il nodo di testa
    delete testa;
}

template <class T>
bool lista_collegata<T>::lista_vuota() const
{
    bool esito;
    esito = false;

    if (testa->precedente == testa && testa->successivo == testa)
    {
        esito = true;
    }
    return esito;
}

template <class T>
int lista_collegata<T>::lunghezza_lista() const
{
    return lunghezza;
}

template <class T>
void lista_collegata<T>::scrivi_elemento(const tipoelem &elemento_scritto, posizione posizione_elemento)
{
    // verifico che la posizione non sia quella del nodo sentinella e che la lista non sia vuota
    if (!fine_lista(posizione_elemento) && !lista_vuota())
    {
        posizione_elemento->valore_nodo = elemento_scritto;
    }
}

template <class T>
typename lista_collegata<T>::tipoelem lista_collegata<T>::leggi_elemento(posizione posizione_selezionata) const
{
    tipoelem elemento_letto;

    // verifico che la posizione non sia quella del nodo sentinella e che la lista non sia vuota
    if (fine_lista(posizione_selezionata) == false && !lista_vuota())
    {
        elemento_letto = posizione_selezionata->valore_nodo;
    }
    return elemento_letto;
}

template <class T>
typename lista_collegata<T>::posizione lista_collegata<T>::primo_lista() const
{
    posizione prima_posizione;

    // verifico che la lista non sia vuota
    if (!lista_vuota())
    {
        prima_posizione = testa->successivo;
    }
    return prima_posizione;
}

template <class T>
typename lista_collegata<T>::posizione lista_collegata<T>::ultimo_lista() const
{
    posizione ultima_posizione;

    // verifico che la lista non sia vuota
    if (!lista_vuota())
    {
        ultima_posizione = testa->precedente;
    }
    return ultima_posizione;
}

template <class T>
bool lista_collegata<T>::fine_lista(posizione posizione_selezionata) const
{
    bool fine;
    fine = false;

    // la condizione di fine_lista e' vera quando mi trovo sul "nodo sentinella"
    if (posizione_selezionata == testa)
    {
        fine = true;
    }
    return fine;
}

template <class T>
typename lista_collegata<T>::posizione lista_collegata<T>::precedente_lista(posizione posizione_attuale) const
{
    return posizione_attuale->precedente;
}

template <class T>
typename lista_collegata<T>::posizione lista_collegata<T>::successivo_lista(posizione posizione_attuale) const
{
    return posizione_attuale->successivo;
}

template <class T>
void lista_collegata<T>::inserisci_elemento(const tipoelem &elemento_inserito, posizione posizione_selezionata)
{
    // creo il nuovo nodo e assegno il valore
    posizione nodo_creato = new nodo_lista<T>;
    nodo_creato->valore_nodo = elemento_inserito;

    if (lista_vuota() == true)
    {
        inserisci_in_testa(elemento_inserito);
    }
    else
    {
        // assegno i valori dei puntatori del nodo creato
        nodo_creato->successivo = posizione_selezionata;
        nodo_creato->precedente = posizione_selezionata->precedente;

        // assegno i valori dei puntatori dei nodi adiacenti
        posizione_selezionata->precedente->successivo = nodo_creato;
        posizione_selezionata->precedente = nodo_creato;
    }
    // incremento la lunghezza
    lunghezza++;
}

template <class T>
void lista_collegata<T>::rimuovi_elemento(posizione nodo_eliminato)
{
    // verifico che la lista non sia vuota e il nodo selezionato non sia il "nodo sentinella"
    if (!lista_vuota() && fine_lista(nodo_eliminato) == false)
    {
        // assegno i valori ai puntatori dei nodi adiacenti
        nodo_eliminato->precedente->successivo = nodo_eliminato->successivo;
        nodo_eliminato->successivo->precedente = nodo_eliminato->precedente;

        // elimino il nodo
        delete nodo_eliminato;
    }
}

template <class T>
void lista_collegata<T>::inserisci_in_testa(const tipoelem &elemento_inserito)
{
    // creo il nuovo nodo e lo alloco in memoria
    nodo_lista<T> *nodo_inserito;
    nodo_inserito = new nodo_lista<T>;

    // scrivo il valore nel nodo
    nodo_inserito->valore_nodo = elemento_inserito;

    // verifico che la lista sia vuota
    if (lista_vuota())
    {
        testa->successivo = nodo_inserito;
        nodo_inserito->precedente = testa;
    }
    else
    {
        testa->precedente->successivo = nodo_inserito;
        nodo_inserito->precedente = testa->precedente;
    }
    nodo_inserito->successivo = testa;
    testa->precedente = nodo_inserito;

    // incremento la lunghezza
    lunghezza++;
}

template <class T>
void lista_collegata<T>::stampa_lista()
{
    // verifico che la lista non e' vuota
    if (!lista_vuota())
    {
        posizione posizione_attuale;
        posizione_attuale = primo_lista();

        while (fine_lista(posizione_attuale) == false)
        {
            tipoelem elemento_letto;
            elemento_letto = leggi_elemento(posizione_attuale);
            cout << elemento_letto << "\n"
                 << endl;

            posizione_attuale = successivo_lista(posizione_attuale);
        }
    }
    else
    {
        cout << "La lista da stampare e' vuota!\n" << endl;
    }
}

template <class T>
lista_collegata<T> &lista_collegata<T>::operator=(const lista_collegata<T> &lista_assegnata)
{
    // assegno il valore della lunghezza
    lunghezza = lista_assegnata.lunghezza_lista();

    // cancello il vecchio stato della lista
    this->~lista_collegata();

    // inizializzo il "nodo sentinella" della lista
    testa = new nodo_lista<T>;
    testa->precedente = testa;
    testa->successivo = testa;

    // copio i valori dalla lista se la lista da assegnare non e' vuota
    if (lista_assegnata.lista_vuota() == false)
    {
        // seleziono la prima posizione della lista copiata
        posizione nodo_assegnato = lista_assegnata.primo_lista();

        while (lista_assegnata.fine_lista(nodo_assegnato) == false)
        {
            inserisci_in_testa(nodo_assegnato->valore_nodo);
            nodo_assegnato = lista_assegnata.successivo_lista(nodo_assegnato);
        }
    }
    return *this;
}

template <class T>
bool lista_collegata<T>::operator==(const lista_collegata<T> &lista_confrontata) const
{
    bool confronto;
    confronto = true;

    if (lunghezza != lista_confrontata.lunghezza_lista())
    {
        confronto = false;
    }
    else
    {
        // confronto uno ad uno gli elementi delle due liste
        posizione nodo_1 = primo_lista();
        posizione nodo_2 = lista_confrontata.primo_lista();

        while ((fine_lista(nodo_1) == false && lista_confrontata.fine_lista(nodo_2) == false) && confronto == true)
        {
            if (nodo_1->valore_nodo != nodo_2->valore_nodo)
            {
                confronto = false;
            }
            nodo_1 = successivo_lista(nodo_1);
            nodo_2 = lista_confrontata.successivo_lista(nodo_2);
        }
    }
    return confronto;
}

template <class T>
void lista_collegata<T>::insertion_sort()
{
    posizione i;
    i = successivo_lista(primo_lista());

    while (fine_lista(i) == false)
    {
        posizione j;
        tipoelem chiave;

        chiave = leggi_elemento(i);
        j = precedente_lista(i);

        while (fine_lista(j) == false && chiave < leggi_elemento(j))
        {
            tipoelem elem_j;
            elem_j = leggi_elemento(j);

            scrivi_elemento(elem_j, successivo_lista(j));

            j = precedente_lista(j);
        }

        scrivi_elemento(chiave, successivo_lista(j));
        i = successivo_lista(i);
    }
}

template <class T>
void lista_collegata<T>::elimina_lista()
{
    if( lista_vuota() == false)
    {
        posizione posizione_eliminata;
        posizione_eliminata = primo_lista();

        while(!lista_vuota())
        {
            rimuovi_elemento(posizione_eliminata);
            posizione_eliminata = successivo_lista(posizione_eliminata);
        }
    }
}

template <class T>
void lista_collegata<T>::scambia_elementi(posizione p1, posizione p2)
{
    if( p1 != p2 && (p1 != nullptr && p2 != nullptr))
    {
        tipoelem temp;
        temp = leggi_elemento(p1);
        scrivi_elemento(leggi_elemento(p2),p1);
        scrivi_elemento(temp, p2);
    }
}

