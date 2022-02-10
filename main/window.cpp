#include "../header/window.hpp"

int window(Grafo grafo) {
	// create the window
	sf::RenderWindow window(sf::VideoMode(1200, 600), "My window");

	Punto mouseClick = Punto();
	int currentNodo = 0;
	//se i nodi selezionati sono validi
	bool nodoFrom = false;
	bool nodoTO = false;
	//gli id dei nodi cliccati
	int idFrom = 0, idTO = 0;

	//font
	sf::Font font;
	if (!font.loadFromFile("verdanab.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
	}

	// run the program as long as the window is open
	while (window.isOpen())
	{
		bool haCliccato = false;

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type) {
			// "close requested" event: we close the window
				case sf::Event::Closed :
					window.close();
					break;
				//mouse cliccato
				case sf::Event::MouseButtonPressed: {
					haCliccato = true;
					mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
					int id_nodo_cliccato = grafo.haCliccato(mouseClick);
					/*cout << "\nid cliccato = " << id_nodo_cliccato;*/
					if(id_nodo_cliccato != 0) {
						if(!nodoFrom) { nodoFrom = true; idFrom = id_nodo_cliccato; /*cout << " ok nodoFrom";*/ }
						else if(!nodoTO) { nodoTO = true; idTO = id_nodo_cliccato; /*cout << " ok nodoTO";*/ }
					}
					/*cout << "id from = " << idFrom << " id to = " << idTO;*/
					break; }
				//tasto sulla tastiera premuto
				case sf::Event::KeyPressed :
					switch(event.key.code) {
						//Esc per uscire
						case sf::Keyboard::Escape :
							window.close();
							break;
						//per creare nuovo nodo
						case sf::Keyboard::N : {
								currentNodo++ ;
								Nodo newNodo = Nodo(to_string(currentNodo), mouseClick);
								grafo.insertNodo(newNodo);
								cout << " newNodo ";
							}
							break;
						//per creare un nuovo arco (in inglese Edge)
						case sf::Keyboard::E :
							if(nodoFrom && nodoTO && (idFrom != idTO)) {
								grafo.insertArco(idFrom, idTO);
								cout << " newArco ";
								//se i nodi selezionati sono validi
								nodoFrom = false;
								nodoTO = false;
							}/* else {
								cout << "\nnodoFrom valido = " << nodoFrom << " id from = " << idFrom;
								cout << "\nnodoTO   valido = " << nodoFrom << " id to   = " << idTO;
							}*/
							break;
						default:
							break;
					}
				default:
					break;
			}
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		grafo.draw(window, font);
		// end the current frame
		window.display();
	}
	//in teoria non dovrebbe arrivare qui?
	outputGrafo("grafoOUT.txt", grafo);
	return 0;
}