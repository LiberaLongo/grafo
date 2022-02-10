#include "../header/Grafo.hpp"
#include "../header/window.hpp"
#include "../header/inputOutputGrafo.hpp"

int main() {
	Grafo grafo = inputGrafo("grafoIN.txt");
	// Grafo grafo = Grafo();
	// Nodo A = Nodo("A", Punto(100, 200));
	// Nodo B = Nodo("B", Punto(600, 200));
	// grafo.insertNodo(A);
	// grafo.insertNodo(B);
	// grafo.insertArco(Arco(A, B));
	grafo.print();
	outputGrafo("grafoOUT.txt", grafo);
	window(grafo);
	cout << endl;
	return 0;
}