#include "Vertice.h"

// Constructor que crea un Vertice vacio
Vertice::Vertice(){};

// Constructor que crea un vertice con un dato
Vertice::Vertice(int _dato){
    this->dato = _dato;
};

// Getters
int Vertice::getDato(){
    return dato;
}

// Setters
void Vertice::setDato(int _dato){
    this->dato = _dato;
}