#include "../header/Grafo.hpp"

//costruttori
Grafo::Grafo() {}
Grafo::Grafo(Lista<Nodo> nodi, Lista<Arco> archi){
	this->nodi = nodi;
	this->archi = archi;
}
//inserisci
void Grafo::insertNodo(Nodo nodo) {
	this->nodi.insert_head(nodo);
}
void Grafo::insertArco(Arco arco) {
	this->archi.insert_head(arco);
}
//rimuove un nodo dalla lista dei nodi e lo restituisce, NULL altrimenti
Nodo* Grafo::removeNodo(Nodo nodo) {
	// struct Elem<Nodo> *pos = this->nodi.search(nodo);
	// if(pos != nullptr)
	//     return &this->nodi.read(pos);
	// else
		return nullptr;
}
//rimuove un arco dalla lista degli archi e lo restituisce, NULL altrimenti
Arco* Grafo::removeArco(Arco arco) {
	// struct Elem<Arco> *pos = this->archi.search(arco);
	// if(pos != nullptr)
	//     return &this->archi.read(pos);
	// else
		return nullptr;
}
//stampa
string Grafo::toString(){
	string res = "Grafo:\n";
	res = res + "Nodi: " + this->nodi.toString();
	res = res + "Archi: " + this->archi.toString();
	return res;
}
void Grafo::print(){
	cout << endl << this->toString();
}
//disegna
void Grafo::draw(sf::RenderWindow &window){
	this->archi.draw(window);
	this->nodi.draw(window);
}