#include "../header/Arco.hpp"
//costruttori
Arco::Arco() {} //serve per lista!
Arco::Arco(Nodo A, Nodo B) {
	this->fromA = A;
	this->toB = B;
}
Arco::Arco(Nodo A, Nodo B, int superiorCapacity) {
	this->fromA = A;
	this->toB = B;
	this->superiorCapacity = superiorCapacity;
}
//getter fasullo (solo per fare searchID nella lista dei nodi del grafo) restituisce sempre -1
int Arco::getID() { return -1; }
//setters e getters
void Arco::setCapacity(int capacity) {
	this->superiorCapacity = capacity;
}
int Arco::getCapacity(void) {
	return this->superiorCapacity;
}
void Arco::setFlusso(int flusso) {
	this->flusso = flusso;
}
int Arco::getFlusso(void) {
	return this->flusso;
}
Nodo Arco::getNodoFrom() {
	return this->fromA;
}
Nodo Arco::getNodoTO() {
	return this->toB;
}
//stampa
string Arco::toString() {
	string res = "\nArco:( " + to_string(this->fromA.getID());
	res = res + " --> " + to_string(this->toB.getID()) + " )";
	return res;
}
void inputArco(string vettore[], int &idFrom, int &idTO) {
	//supponi di avere le parole scritte dal toString() in un vettore in cui ogni spazio è un separatore.
	if(vettore[0] != "Arco:(") cout << "errore arco" << vettore[0];
	if(vettore[2] != "-->") cout << "errore -->";
	if(vettore[4] != ")") cout << "errore chiusura parentesi";
	idFrom = std::stoi(vettore[1]);
	idTO = std::stoi(vettore[3]);
}
void Arco::print() {
	cout << this->toString();
}
//per trovarlo in una lista
bool Arco::confronto(Arco arco) {
	//se il primo nodo è uguale al primo nodo
	bool first = this->fromA.getID() == arco.getNodoFrom().getID();
	//se il secondo nodo è uguale al secondo nodo
	bool second = this->fromA.getID() == arco.getNodoFrom().getID();
	return first && second;
	//Nota: getNodoFrom() e getNodoTO restituiscono un puntatore
	//quindi non è possibile fare confronto chiamando Nodo.confronto()
	//perchè il compilatore si arrabbia
}
//disegna
void Arco::draw(sf::RenderWindow &window) {
	//centro iniziale della figura prima di fare setPosition
	float x = 0.f, y = 0.f; //centro: (0,0)
	float size = this->fromA.getSize();
	//non so se calcola l'angolo bene...
	float angolo = angoloLibreria(this->fromA.getCentro().calcolaAngolo(this->toB.getCentro()));
	//distanza tra i centri dei nodi
	float distanza = this->fromA.getCentro().distance(this->toB.getCentro());
	//la linea
	sf::RectangleShape linea(sf::Vector2f{ size / 5, distanza});
	//colore linea
	linea.setFillColor(sf::Color::White);
	//ruota di angolo, PRIMA! della rotazione
	linea.setRotation(angolo);
	//spostala  posizione effettiva del centro
	linea.setPosition(this->toB.getX(), this->toB.getY());

	// //la punta della freccia
	// //crea una empty shape convex con 3 punti
	// sf::ConvexShape triangolo;
	// triangolo.setPointCount(3);
	// //definisci i punti rispetto a (0,0)
	// triangolo.setPoint(0, sf::Vector2f(x, y - size * 3));
	// triangolo.setPoint(1, sf::Vector2f(x - size, y + size));
	// triangolo.setPoint(2, sf::Vector2f(x + size, y + size));
	// //colore punta della freccia
	// triangolo.setFillColor(sf::Color::Black);
	// //ruota di angolo, PRIMA! della rotazione
	// triangolo.setRotation(angolo);
	// //spostala  posizione effettiva del centro
	// triangolo.setPosition(this->toB.getX() + size , this->toB.getY() + size);

	//disegna la linea
	window.draw(linea);
	//disegna la punta della freccia
	// window.draw(triangolo);
}
