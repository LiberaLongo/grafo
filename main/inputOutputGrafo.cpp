#include "../header/inputOutputGrafo.hpp"

Grafo inputGrafo(string fileName) {
	cout << "\ninizio lettura file";
	//input from file
	bool finito = false;
	ifstream fin(fileName);
	string lettura = "";
	string vettoreStringhe[9];
	Grafo grafo = Grafo();
	for(int i = 0; i < 3 ; i++) {
		fin >> lettura;
		vettoreStringhe[i] = lettura;
	}
	if(vettoreStringhe[0] != "Grafo:") cout << "errore grafo";
	if(vettoreStringhe[1] != "Nodi:") cout << "errore nodi";
	if(vettoreStringhe[2] != "Lista:[") cout << "errore lista";
	while(lettura != "]") {
		for(int i = 0; i < 9 ; i++) {
			fin >> lettura;
			vettoreStringhe[i] = lettura;
		}
		Nodo newNodo = inputNodo(vettoreStringhe);
		grafo.insertNodo(newNodo);
		fin >> lettura;
	}
	fin >> lettura;
	if(lettura != "Archi:") cout << "errore archi";
	fin >> lettura;
	if(lettura != "Lista:[") cout << "errore lista";
	// while(lettura != "]") {
	// 	for(int i = 0; i < 9 ; i++) {
	// 		fin >> lettura;
	// 		vettoreStringhe[i] = lettura;
	// 	}
	// 	Arco newArco = inputArco(vettoreStringhe);
	// 	grafo.insertArco(newArco);
	// 	fin >> lettura;
	// }
	cout << "\nfine lettura file\n";
	return grafo;
}
void outputGrafo(string fileName, Grafo grafo) {
	//output from file
	ofstream fout(fileName);
	fout << grafo.toString();
	fout << endl;
	fout.close();
}