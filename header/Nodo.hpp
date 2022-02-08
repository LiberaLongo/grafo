//Libera Longo
#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>
#include <string>
using namespace std;

#include "./Punto.hpp"
#include "./ColoreRGB.hpp"

#include <SFML/Graphics.hpp>

class Nodo {
private:
    int id = 0;
    string name = "nodo";
    Punto centro;
    float size = 50.f;
    ColoreRGB colore;
public:
    //costruttori
    Nodo(string name);
    Nodo(string name, Punto p);
    Nodo(string name, Punto p, ColoreRGB color);
    //distruttori
    virtual ~Nodo() {};
    //getters senza setter
    string getName();
    //stampa
    string toString(void);
    void print(void);
    //centro
    void setCentro(float x, float y);
    Punto getCentro();
    //colore
    void setColore(int red, int green, int blue);
    ColoreRGB getColore();
    //disegna
    void draw(sf::RenderWindow &window);
};

#endif