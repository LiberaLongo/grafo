#include "../header/Nodo.hpp"

int currentID = 0;

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
string Nodo::getName() {
    return this->name;
}
string Nodo::toString() {
    string res = "Nodo " + this->name + ", id: " + to_string(this->id);
    res = res + ", disegnato nel punto" + this->centro.toString();
    //res = res + "colore " + this->colore.toString();
    return res;
}
void Nodo::print(void) {
    cout << endl << this->toString();
}
//centro
void Nodo::setCentro(float x, float y) {
    this->centro = Punto(x, y);
}
Punto Nodo::getCentro() {
    return this->centro;
}
//colore
void Nodo::setColore(int red, int green, int blue) {
    this->colore = ColoreRGB(red, green, blue);
}
ColoreRGB Nodo::getColore() {
    return this->colore;
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
