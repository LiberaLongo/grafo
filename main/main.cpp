#include "../header/Grafo.hpp"
#include "../header/window.hpp"
#include "../header/inputOutputGrafo.hpp"

int main() {
    float d1 = 100.f;
    float d2 = 300.f;
    Nodo A = Nodo("A", Punto(d1, d1));
    Nodo B = Nodo("B", Punto(d1, d2));
    Nodo C = Nodo("C", Punto(d2, d1));
    Nodo D = Nodo("D", Punto(d2, d2));
    Arco AB = Arco(&A, &B);
    Arco AC = Arco(&A, &C);
    Arco BC = Arco(&B, &C);
    Grafo grafo = Grafo();
    grafo.insertNodo(A);
    grafo.insertNodo(B);
    grafo.insertArco(AB);
    grafo.insertNodo(C);
    grafo.insertArco(AC);
    grafo.insertArco(BC);
    grafo.insertNodo(D);
    grafo.print();
    outputGrafo("grafoOUT.txt");
    window(grafo);
    cout << endl;
    return 0;
}