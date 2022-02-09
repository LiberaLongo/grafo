#include "../header/Grafo.hpp"
#include "../header/window.hpp"
#include "../header/inputOutputGrafo.hpp"

int main() {
    Grafo grafo = inputGrafo("grafoIN.txt");
    grafo.print();
    outputGrafo("grafoOUT.txt", grafo);
    window(grafo);
    cout << endl;
    return 0;
}