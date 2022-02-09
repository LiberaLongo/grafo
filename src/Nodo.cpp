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
    string res = "\nNodo: " + this->name;
    res = res + " id: " + to_string(this->id);
    res = res + " disegnato_nel_punto" + this->centro.toString();
    //res = res + "colore " + this->colore.toString();
    return res;
}
Nodo inputNodo(string vettore[]) {
    //supponi di avere le parole scritte dal toString() in un vettore in cui ogni spazio è un separatore.
    if(vettore[0] != "Nodo:") cout << "errore nodo" << vettore[0];
    if(vettore[2] != "id:") cout << "errore id";
    if(vettore[4] != "disegnato_nel_punto(") cout << "errore disegnato_nel_punto(";
    if(vettore[6] != ",") cout << "errore virgola";
    if(vettore[8] != ")") cout << "errore chiusura parentesi";
    string name = vettore[1];
    int id = std::stoi(vettore[3]);
    float x = std::stof(vettore[5]);
    float y = std::stof(vettore[7]);
    Nodo nodo = Nodo(name, Punto(x, y));
    if(id != nodo.getID()) cout << "errore id creati sono diversi";
    return nodo;
}
void Nodo::print(void) {
    cout << this->toString();
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
    testo.setCharacterSize(this->size);
    testo.setString(this->name);
    float x_testo = this->centro.getX() - this->size / 2;
    float y_testo = this->centro.getY() - this->size *2/3;
    testo.setPosition( {x_testo, y_testo} );
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
    cerchio.setOutlineColor(sf::Color::White);
    window.draw(cerchio);
    window.draw(testo);
}
