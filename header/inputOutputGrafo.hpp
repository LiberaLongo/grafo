#ifndef inputOutputGrafo_HPP
#define inputOutputGrafo_HPP

#include "../header/Grafo.hpp"
#include <fstream>

Grafo inputGrafo(string fileName);
void outputGrafo(string fileName, Grafo grafo);

#endif