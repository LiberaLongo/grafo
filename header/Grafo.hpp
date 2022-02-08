//Libera Longo
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <string>
using namespace std;

#include "./Nodo.hpp"
#include "./Arco.hpp"

class Grafo {
private:
	
public:
	Grafo();
	virtual ~Grafo() {};
	string toString();
	void draw(sf::RenderWindow &window);
};

#endif
