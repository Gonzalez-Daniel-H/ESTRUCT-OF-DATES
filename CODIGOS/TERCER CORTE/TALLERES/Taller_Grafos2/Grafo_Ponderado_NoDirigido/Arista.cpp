#include "Arista.h"

// Constructor vacio que crea una arista vacia
Arista::Arista(){};

// Constructor que crea una arista no ponderada
Arista::Arista(Vertice * _vertice1,Vertice * _vertice2){
    this->vertice1 = _vertice1;
    this->vertice2 = _vertice2;
};

// Constructor que crea una arista ponderada
Arista::Arista(Vertice* _vertice1,Vertice* _vertice2,int _peso){
    this->vertice1 = _vertice1;
    this->vertice2 = _vertice2;
    this->peso = _peso;
};

// Setters
void Arista::setVertice1(Vertice* vertice){
    this->vertice1 = vertice;
};
void Arista::setVertice2(Vertice* vertice){
    this->vertice2 = vertice;
};
void Arista::setpeso(int _peso){
    this->peso = _peso;
};

// Getters
Vertice * Arista::getVertice1(){
    return vertice1;
};
Vertice * Arista::getVertice2(){
    return vertice2;
};
int Arista::getpeso(){
    return peso;
};