// Las siguientes lineas se encargan de asegurarse que la clase se crea solo una vez
#ifndef VERTICE_H
#define VERTICE_H

class Vertice{
    private:
    int dato; // dato tipo entero que contendra el vertice

    public:
    Vertice();
    Vertice(int _dato);
    void setDato(int _dato);
    int getDato();
};

#endif //VERTICE_H