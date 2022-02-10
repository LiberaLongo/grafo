//Libera Longo
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <string>
using namespace std;

#include "./Nodo.hpp"
#include "./Arco.hpp"
#include "./includeTemplate.hpp"

template class Lista<Nodo>;
template class Lista<Arco>;

class Grafo {
private:
	Lista<Nodo> nodi;
	Lista<Arco> archi;
public:
	//costruttori
	Grafo();
	Grafo(Lista<Nodo> nodi, Lista<Arco> archi);
	//distruttori
	virtual ~Grafo() {};
	//inserimento
	void insertNodo(Nodo nodo);
	void insertArco(Arco arco);
	//inserimento di un arco se idFrom e idTO vengono trovati entrambi come id di Nodi già presenti nel grafo.
	void insertArco(int idFrom, int idTO);
	//rimuove un nodo dalla lista dei nodi e lo restituisce, NULL altrimenti
	Nodo* removeNodo(Nodo nodo);
	//rimuove un arco dalla lista degli archi e lo restituisce, NULL altrimenti
	Arco* removeArco(Arco arco);
	//controlla se ha cliccato un nodo, ritorna 0 altrimenti
	int haCliccato(Punto p);
	//stampa
	string toString();
	void print();
	void draw(sf::RenderWindow &window, const sf::Font font);
	
};

#endif
