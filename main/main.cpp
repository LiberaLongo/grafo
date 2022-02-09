#include "../header/Grafo.hpp"

int main() {
    float d1 = 50.f;
    float d2 = 150.f;
    Nodo A = Nodo("A", Punto(d1, d1));
    Nodo B = Nodo("B", Punto(d1, d2));
    Nodo C = Nodo("C", Punto(d2, d1));
    Nodo D = Nodo("D", Punto(d2, d2));
    Arco AB = Arco(&A, &B);
    Grafo grafo = Grafo();
    grafo.insertNodo(A);
    grafo.insertNodo(B);
    grafo.insertArco(AB);
    grafo.insertNodo(C);
    grafo.insertNodo(D);
    grafo.print();
    cout << endl;
    return 0;
}