#system, window, graphics, network and audio
SYSTEM := -lsfml-system
WINDOW := -lsfml-window
GRAFICS := -lsfml-graphics
NETWORK := -lsfml-network
AUDIO := -lsfml-audio

#link all
LINK_SFML = $(SYSTEM) $(WINDOW) $(GRAFICS) $(NETWORK) $(AUDIO)

#cartelle progetto
H = ./header/
M = ./main/
S = ./src/

#comando per compilare
CC = g++
LINK = g++
CFLAGS = -c -std=c++11
COMPILE = $(CC) $(CFLAGS)

#indieme di header molto usati
HDR = $(H)DisegnabileI.hpp $(H)utils.hpp $(H)Punto.hpp $(H)Direzione.hpp
#insieme di oggetti che vogliono essere lanciati (chiamati da main)
OBJ = ListaParent.o Lista.o Punto.o ColoreRGB.o \
	Nodo.o Arco.o Grafo.o main.o inputOutputGrafo.o window.o #Button.o
# Controlli.o

all: app
#lancia l'app in automatico
	./$<

ListaParent.o: $(S)ListaParent.cpp $(H)ListaParent.hpp
	$(COMPILE) $(S)ListaParent.cpp -o ListaParent.o

Lista.o: $(S)Lista.cpp $(H)Lista.hpp
	$(COMPILE) $(S)Lista.cpp -o Lista.o

Punto.o: $(S)Punto.cpp $(H)Punto.hpp
	$(COMPILE) $(S)Punto.cpp -o Punto.o

ColoreRGB.o: $(S)ColoreRGB.cpp $(H)ColoreRGB.hpp
	$(COMPILE) $(S)ColoreRGB.cpp -o ColoreRGB.o

#Button.o: $(S)Button.cpp $(H)Button.hpp $(H)Punto.hpp $(H)ColoreRGB.hpp
#	$(COMPILE) $(S)Button.cpp -o Button.o

Nodo.o: $(S)Nodo.cpp $(H)Nodo.hpp
	$(COMPILE) $(S)Nodo.cpp -o Nodo.o

Arco.o: $(S)Arco.cpp $(H)Arco.hpp
	$(COMPILE) $(S)Arco.cpp -o Arco.o

Grafo.o: $(S)Grafo.cpp $(H)Grafo.hpp
	$(COMPILE) $(S)Grafo.cpp -o Grafo.o

inputOutputGrafo.o: $(M)inputOutputGrafo.cpp $(H)inputOutputGrafo.hpp
	$(COMPILE) $(M)inputOutputGrafo.cpp -o inputOutputGrafo.o

window.o: $(M)window.cpp $(H)window.hpp
	$(COMPILE) $(M)window.cpp -o window.o

main.o: $(M)main.cpp
	$(COMPILE) $(M)main.cpp -o main.o

#link all into an executable
app: $(OBJ)
#	linkiamo tutti gli object e la grafica SFML
	$(LINK) $(OBJ) -o app $(LINK_SFML)

#clean target
.PHONY: clean

clean:
	rm -rf *.o app
