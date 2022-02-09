//lista per le classi ereditata
#ifndef LISTA_HPP
#define LISTA_HPP

#include <SFML/Graphics.hpp>
#include "./ListaParent.hpp"

template <typename Tipo>
class Lista : public ListaParent<Tipo> {
public:
	//costruttore e distruttore
	Lista(void);
	virtual ~Lista(void) {};

	//cerca v scorrendo la lista
	//override
	struct Elem<Tipo>* search(Tipo v);
	struct Elem<Tipo>* searchID(int id);

	//stampe
	//override
	string toString(void);
	void print(void);
	
	//disegna elementi
	void draw(sf::RenderWindow &window);
};
#endif //LISTA_HPP
