// Las siguientes lineas se encargan de asegurarse que la clase se crea solo una vez
#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"

class Arista{
    private:
    Vertice * vertice1; // Vertice #1 de la arista
    Vertice * vertice2; // Vertice #2 de la arista
    int peso; // Peso asignado a la arista

    public:
    Arista(); // Constructor vacio
    Arista(Vertice *,Vertice *); // Constructor con vertices pero sin peso
    Arista(Vertice *,Vertice *,int); // Constructor con vertices y peso

    // Setters
    void setVertice1(Vertice *);
    void setVertice2(Vertice *);
    void setpeso(int);

    // Getters
    Vertice * getVertice1();
    Vertice * getVertice2();
    int getpeso();
};

#endif //ARISTA_H