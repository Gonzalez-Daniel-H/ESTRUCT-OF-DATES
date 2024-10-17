#include "Grafo.h"

// Se agrega una arista al grafo
void Grafo::agregarArista(Arista * arista){
    bool estaVertice1EnGrafo = false;
    bool estaVertice2EnGrafo = false;

    // Se verifica que los vertices en las aristas se encuentren tambien en la lista de vertices del grafo
    for(Vertice * vertice: vertices){
        if(arista->getVertice1()==vertice){
            estaVertice1EnGrafo = true;
        }
        if(arista->getVertice2()==vertice){
            estaVertice2EnGrafo = true;
        }
        if(estaVertice1EnGrafo && estaVertice2EnGrafo){
            break;
        }
    }

    if(estaVertice1EnGrafo && estaVertice2EnGrafo){
        aristas.push_back(arista);
        return;
    }
    throw invalid_argument("Los vertices no se encuentran en el grafo");
};

// Se agrega un vertice al grafo
void Grafo::agregarVertice(Vertice * vertice){
    vertices.push_back(vertice);
};

// Se imprime por consola la matriz del grafo
void Grafo::imprimirMatrizGrafo(){
    // Se imprime el encabezado de la matriz
    cout<<"   | ";
    for(Vertice * vertice: vertices){
        cout<< vertice->getDato() << " ";
    }
    cout<<endl;
    cout<<"---+";
    for(int i=0;i<vertices.size();++i){
        cout<<"--";
    }
    cout<<endl;

    //Se imprime la matriz completa
    bool existeArista;
    for(Vertice * vertice1: vertices){ // Se recorre las filas
        cout << " " << vertice1->getDato() << " | ";
        for(Vertice * vertice2: vertices){ // Se recorren las columnas
            existeArista = false;
            for(Arista * arista: aristas){// En caso de existir una arista con los dos vertices se imprime su peso
                if((vertice1 == arista->getVertice1() && vertice2 == arista->getVertice2()) || 
                    (vertice2 == arista->getVertice1() && vertice1 == arista->getVertice2()))
                    {
                    cout<< arista->getpeso() << " ";
                    existeArista = true;
                    break;
                }
            }
            if(!existeArista){ // En caso de no existir imprimiir 0
                cout<< "0 ";
            }
        }
        cout<<endl;
    }
}
