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
	Nodo *fromA;	//puntatore al nodo di partenza
	Nodo *toB;		//puntatore al nodo di arrivo
public:
	//costruttori
	Arco(); //serve per lista!
	Arco(Nodo *A, Nodo *B);
	Arco(Nodo *A, Nodo *B, int superiorCapacity);
	//distruttore
	virtual ~Arco() {};
	//setters e getters
	void setCapacity(int capacity);
	int getCapacity(void);
	void setFlusso(int flusso);
	int getFlusso(void);
	Nodo* getNodoFrom(void);
	Nodo* getNodoTO(void);
	//stampa
	string toString(void);
	void print(void);
	//per trovarlo in una lista
	bool confronto(Arco arco);
	//disegna
	void draw(sf::RenderWindow &window);
};

Arco inputArco(string vettore[]);

#endif //ARCO_HPP
