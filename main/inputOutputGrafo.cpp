#include "../header/inputOutputGrafo.hpp"

Grafo inputGrafo(string fileName) {
	//cout << "\ninizio lettura file";
	//input from file
	bool finito = false;
	ifstream fin(fileName);
	string lettura = "";
	string vettoreStringhe[9];
	//creazione grafo
	Grafo grafo = Grafo();
	//lettura parte prima della lista dei nodi
	for(int i = 0; i < 3 ; i++) {
		fin >> lettura;
		vettoreStringhe[i] = lettura;
	}
	if(vettoreStringhe[0] != "Grafo:") cout << "errore grafo";
	if(vettoreStringhe[1] != "Nodi:") cout << "errore nodi";
	if(vettoreStringhe[2] != "Lista:[") cout << "errore lista";
	//lettura all'interno della lista dei nodi
	while(lettura != "]") {
		for(int i = 0; i < 9 && lettura != "]" ; i++) {
			fin >> lettura;
			if(lettura == "]") break;
			vettoreStringhe[i] = lettura;
		}
		if(vettoreStringhe[0] == "Nodo:") {
			Nodo newNodo = inputNodo(vettoreStringhe);
			grafo.insertNodo(newNodo);
			fin >> lettura; //lettura di freccia o di parentesi quadra chiusa
		}
	}
	//lettura in mezzo alla lista di nodi e archi
	fin >> lettura;
	if(lettura != "Archi:") cout << "errore archi";
	fin >> lettura;
	if(lettura != "Lista:[") cout << "errore lista";
	//lettura all'interno della lista degli archi
	while(lettura != "]" ) {
		for(int i = 0; i < 5 && lettura != "]" ; i++) {
			fin >> lettura;
			vettoreStringhe[i] = lettura;
		}
		if(vettoreStringhe[0] == "Arco:(") {
			int idFrom, idTO;
			inputArco(vettoreStringhe, idFrom, idTO);
			// cout << "id" << idFrom << idTO;
			grafo.insertArco(idFrom, idTO);
			fin >> lettura; //lettura di freccia o di parentesi quadra chiusa
		}
	}
	//cout << "\nfine lettura file\n";
	return grafo;
}
void outputGrafo(string fileName, Grafo grafo) {
	//output from file
	ofstream fout(fileName);
	fout << grafo.toString();
	fout << endl;
	fout.close();
}