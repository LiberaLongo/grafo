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
    //setters e getters
    //stampa
    string toString(void);
    void print(void);
    //size
    void setSize(float size);
    float getSize(void);
    //centro
    void setX(float x);
    void setY(float y);
    void setCentro(float x, float y);
    float getX(void);
    float getY(void);
    Punto getCentro(void);
    //colore
    void setColore(int red, int green, int blue);
    ColoreRGB getColore();
    //disegna
    void draw(sf::RenderWindow &window);
};

#endif