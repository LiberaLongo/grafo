#include "../header/Arco.hpp"
//costruttori
Arco::Arco(Nodo *A, Nodo *B) {
    this->fromA = A;
    this->toB = B;
}
Arco::Arco(Nodo *A, Nodo *B, int superiorCapacity) {
    this->fromA = A;
    this->toB = B;
    this->superiorCapacity = superiorCapacity;
}
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
Nodo* Arco::getNodoFrom() {
    return this->fromA;
}
Nodo* Arco::getNodoTO() {
    return this->toB;
}
//stampa
string Arco::toString() {
    string res = "Arco dal Nodo: " + this->fromA->getName();// + this->fromA->getCentro().toString();
    res = res + " al Nodo: " + this->toB->getName();// + this->toB->getCentro().toString();
    return res;
}
void Arco::print() {
    cout << endl << this->toString();
}
//disegna
void Arco::draw(sf::RenderWindow &window) {
    //centro iniziale della figura prima di fare setPosition
    float x = 0.f, y = 0.f; //centro: (0,0)
    float size = this->fromA->getSize();
    //non so se calcola l'angolo bene...
    float angolo = angoloLibreria(this->fromA->getCentro().calcolaAngolo(this->toB->getCentro()));
    //distanza tra i centri dei nodi
    float distanza = this->fromA->getCentro().distance(this->toB->getCentro());

    //la linea
    sf::RectangleShape linea(sf::Vector2f{ size / 5, distanza});
    //colore linea
    linea.setFillColor(sf::Color::Black);
    //ruota di angolo, PRIMA! della rotazione
    linea.setRotation(angolo);
    //spostala  posizione effettiva del centro
    linea.setPosition(this->toB->getX(), this->toB->getY());

    //la punta della freccia
    //crea una empty shape convex con 3 punti
    sf::ConvexShape triangolo;
    triangolo.setPointCount(3);
    //definisci i punti rispetto a (0,0)
    triangolo.setPoint(0, sf::Vector2f(x, y - size * 3));
    triangolo.setPoint(1, sf::Vector2f(x - size, y + size));
    triangolo.setPoint(2, sf::Vector2f(x + size, y + size));
    //colore punta della freccia
    triangolo.setFillColor(sf::Color::Black);
    //ruota di angolo, PRIMA! della rotazione
    triangolo.setRotation(angolo);
    //spostala  posizione effettiva del centro
    triangolo.setPosition(this->toB->getX(), this->toB->getY());

    //disegna la linea
    window.draw(linea);
    //disegna la punta della freccia
    window.draw(triangolo);
}
