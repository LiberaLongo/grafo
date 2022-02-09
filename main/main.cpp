#include "../header/Grafo.hpp"
int window(Grafo grafo) {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        grafo.draw(window);
        // end the current frame
        window.display();
    }

    return 0;
}

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
    window(grafo);
    cout << endl;
    return 0;
}