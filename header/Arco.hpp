//Libera Longo
#ifndef ARCO_HPP
#define ARCO_HPP

#include <iostream>
#include <string>
using namespace std;

#include "./Nodo.hpp"

class Arco {
private:
	int superiorCapacity;
	int flusso = 0;
	Nodo *fromA;	//puntatore al nodo di partenza
	Nodo *toB;		//puntatore al nodo di arrivo
public:
	Arco(Nodo *A, Nodo *B, int superiorCapacity);
	virtual ~Arco() {};
	Nodo* getNodoFrom();
	Nodo* getNodoTO();
	string toString();
	void draw(sf::RenderWindow &window);
};

#endif //ARCO_HPP
