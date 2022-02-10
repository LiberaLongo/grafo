#include "../header/window.hpp"

int window(Grafo grafo) {
	// create the window
	sf::RenderWindow window(sf::VideoMode(1200, 600), "My window");
	Punto mouseClick = Punto();
	int currentNodo = 0;
	char lastClickedKeyboard = '0';

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
					break;//mouse cliccato
				case sf::Event::MouseButtonPressed:
					haCliccato = true;
					mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
					break;
				case sf::Event::KeyPressed :
					switch(event.key.code) {
						case sf::Keyboard::Escape :
							window.close();
							break;
						case sf::Keyboard::N : {
							currentNodo++ ;
							Nodo newNodo = Nodo(to_string(currentNodo), mouseClick);
							grafo.insertNodo(newNodo);
							cout << "newNodo";
							break; }
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
		grafo.draw(window);
		// end the current frame
		window.display();
	}
	//in teoria non dovrebbe arrivare qui?
	outputGrafo("grafoOUT.txt", grafo);
	return 0;
}