#include "../header/Nodo.hpp"
#include "../header/Arco.hpp"

int main() {
    float d1 = 50.f;
    float d2 = 150.f;
    Nodo A = Nodo("A", Punto(d1, d1));
    Nodo B = Nodo("B", Punto(d1, d2));
    Nodo C = Nodo("C", Punto(d2, d1));
    Nodo D = Nodo("D", Punto(d2, d2));
    Arco AB = Arco(&A, &B);
    //stampa
    A.print();
    B.print();
    AB.print();
    C.print();
    D.print();
    cout << endl;
    return 0;
}