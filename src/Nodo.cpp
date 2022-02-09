#include "../header/Nodo.hpp"

int currentID = 0;

//costruttori
Nodo::Nodo() {} //non usare questo! il nodo è fasullo / non incrementa currentID, serve per lista!
Nodo::Nodo(string name) {
    currentID ++;
    this->id = currentID;
    this->name = name;
}
Nodo::Nodo(string name, Punto p) {
    currentID ++;
    this->id = currentID;
    this->name = name;
    this->centro = p;
}
Nodo::Nodo(string name, Punto p, ColoreRGB colore) {
    currentID ++;
    this->id = currentID;
    this->name = name;
    this->centro = p;
    this->colore = colore;
}

//getters senza setter
string Nodo::getName() {
    return this->name;
}
int Nodo::getID() {
    return this->id;
}
//setters e getters
//size
void Nodo::setSize(float size) {
    this->size = size;
}
float Nodo::getSize(void) {
    return this->size;
}
//centro
void Nodo::setX(float x) {
    this->centro.setX(x);
}
void Nodo::setY(float y) {
    this->centro.setY(y);
}
void Nodo::setCentro(float x, float y) {
    this->centro = Punto(x, y);
}
float Nodo::getX(void) {
    return this->centro.getX();
}
float Nodo::getY(void) {
    return this->centro.getY();
}
Punto Nodo::getCentro(void) {
    return this->centro;
}
//colore
void Nodo::setColore(int red, int green, int blue) {
    this->colore = ColoreRGB(red, green, blue);
}
ColoreRGB Nodo::getColore() {
    return this->colore;
}

//stampa
string Nodo::toString() {
    string res = "Nodo " + this->name;
    //res = res + ", id: " + to_string(this->id);
    //res = res + ", disegnato nel punto" + this->centro.toString();
    //res = res + "colore " + this->colore.toString();
    return res;
}
void Nodo::print(void) {
    cout << endl << this->toString();
}
//per trovarlo in una lista
bool Nodo::confronto(Nodo nodo) {
    return this->id == nodo.getID();
}
//disegna
void Nodo::draw(sf::RenderWindow &window) {
    //testo e font
    sf::Font Font;
    sf::Text testo;
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
    }
    testo.setFont(Font);
    testo.setCharacterSize(this->size / 5);
    testo.setString(this->name);
    testo.setPosition( { this->centro.getX(), this->centro.getY() - this->size / 10 } );
    //cerchio
    float esterno = -(this->size / 5);
    sf::CircleShape cerchio(this->size);
    float x = this->centro.getX() - this->size;
    float y = this->centro.getY() - this->size;
    cerchio.setPosition(x, y);
    //colore verde
    cerchio.setFillColor(this->colore.getColorLib());
    //setta un bordo di 10 all'interno del cerchio
    cerchio.setOutlineThickness(esterno);
    //colore del bordo giallo
    cerchio.setOutlineColor(sf::Color::Black);
    window.draw(cerchio);
}
