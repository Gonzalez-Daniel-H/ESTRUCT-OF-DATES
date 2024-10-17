// Las siguientes lineas se encargan de asegurarse que la clase se crea solo una vez
#ifndef GRAFO_H
#define GRAFO_H

#include "Vertice.h"
#include "Arista.h"
#include <stdexcept>
#include <iostream>
#include <list>

using namespace std;

class Grafo{
    private:
    list<Vertice *> vertices; // lista de vertices
    list<Arista *> aristas; // lista de aristas

    public:
    void agregarVertice(Vertice *);
    void agregarArista(Arista *);
    void imprimirMatrizGrafo();

};

#endif //GRAFO_H