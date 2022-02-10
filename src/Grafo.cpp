#include "../header/Grafo.hpp"

//costruttori
Grafo::Grafo() {}
Grafo::Grafo(Lista<Nodo> nodi, Lista<Arco> archi){
	this->nodi = nodi;
	this->archi = archi;
}
//inserisci
void Grafo::insertNodo(Nodo nodo) {
	this->nodi.insert_tail(nodo);
}
void Grafo::insertArco(Arco arco) {
	this->archi.insert_tail(arco);
}
//inserimento di un arco se idFrom e idTO vengono trovati entrambi come id di Nodi già presenti nel grafo.
void Grafo::insertArco(int idFrom, int idTO) {
	struct Elem<Nodo> *posFrom = this->nodi.searchID(idFrom);
	struct Elem<Nodo> *posTO = this->nodi.searchID(idTO);
	if(posFrom != nullptr && posTO != nullptr) {
		Nodo nodoFrom = this->nodi.read(posFrom);
		Nodo nodoTO = this->nodi.read(posTO);
		Arco nuovoArco = Arco(nodoFrom, nodoTO);
		this->insertArco(nuovoArco);
	} else cout << "qualcosa è andato storto nella ricerca dei nodi nella lista tramite id";
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

//controlla se ha cliccato un nodo, ritorna 0 altrimenti
int Grafo::haCliccato(Punto p) {
	//cout << " ";
	if (!(this->nodi.empty()))
	{
		//primo elemento utile non la sentinella
		struct Elem<Nodo> *iter = this->nodi.head();
		//se non vuota e non finita
		while (!(this->nodi.finished(iter)))
		{
			Nodo controllato = this->nodi.read(iter);
			int id = controllato.haCliccato(p);
			if(id != 0)
				return id;
			//passo al successivo
			iter = this->nodi.next(iter);
		}
	}
	return 0;
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
void Grafo::draw(sf::RenderWindow &window, const sf::Font font ){
	this->archi.draw(window, font);
	this->nodi.draw(window, font);
}