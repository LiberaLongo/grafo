//header colori
#ifndef COLORE_HPP
#define COLORE_HPP

#include <iostream>
#include <string>
using namespace std;

#include <SFML/Graphics.hpp>

#define LUMUS_MAXIMA 255

class ColoreRGB
{
private:
    //default bianco
    int red = LUMUS_MAXIMA;
    int green = LUMUS_MAXIMA;
    int blue = LUMUS_MAXIMA;

public:
    //costruttore vuoto
    ColoreRGB(void);
    //costruttore completo
    ColoreRGB(int red, int green, int blue);
    //distruttore
    virtual ~ColoreRGB(void) {};

    //setters
    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);
    void setRGB(int red, int green, int blue);

    //getters
    int getRed(void);
    int getGreen(void);
    int getBlue(void);

    //stampa
    string toString(void);
    void print(void);

    sf::Color getColorLib(void);
};

#endif //COLORE_HPP
