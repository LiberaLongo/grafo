//Libera Longo
#ifndef ARCO_HPP
#define ARCO_HPP

#include <iostream>
#include <string>
using namespace std;

#include "./Nodo.hpp"

class Arco {
private:
	int superiorCapacity = 0;
	int flusso = 0;
	Nodo fromA;	//puntatore al nodo di partenza
	Nodo toB;		//puntatore al nodo di arrivo
public:
	//costruttori
	Arco(); //serve per lista!
	Arco(Nodo A, Nodo B);
	Arco(Nodo A, Nodo B, int superiorCapacity);
	//distruttore
	virtual ~Arco() {};
	//getter fasullo (solo per fare searchID nella lista dei nodi del grafo) restituisce sempre -1
	int getID();
	//setters e getters
	void setCapacity(int capacity);
	int getCapacity(void);
	void setFlusso(int flusso);
	int getFlusso(void);
	Nodo getNodoFrom(void);
	Nodo getNodoTO(void);
	//stampa
	string toString(void);
	void print(void);
	//per trovarlo in una lista
	bool confronto(Arco arco);
	//disegna
	void draw(sf::RenderWindow &window, const sf::Font font );
};

void inputArco(string vettore[], int &idFrom, int &idTO);

#endif //ARCO_HPP
