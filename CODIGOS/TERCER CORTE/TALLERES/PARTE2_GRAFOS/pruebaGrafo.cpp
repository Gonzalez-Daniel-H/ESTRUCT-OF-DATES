/*****************************************************
 * Ausunto: Taller implementacion grafos
 * Autores: Nicolas Algarra y Daniel Gonzalez
 * Materia: Estructura de datos
 * Descripcion: 
 * En este taller se implemento un grafo funcional con sus opciones mas basicas
*****************************************************/

#include "Grafo.h"
#include "Vertice.h"
#include "Arista.h"
#include <iostream>

using namespace std;

int main(){
    Grafo grafo;

    Vertice vertice1(1);
    Vertice vertice2(2);
    Vertice vertice3(3);

    Arista arista1(&vertice1,&vertice2,5);
    Arista arista2(&vertice2,&vertice3,7);

    grafo.agregarVertice(&vertice1);
    grafo.agregarVertice(&vertice2);
    grafo.agregarVertice(&vertice3);
    cout << "Vertices agregados correctamente\n";

    grafo.agregarArista(&arista1);
    grafo.agregarArista(&arista2);
    cout << "Aristas agregados correctamente\n";

    cout << "\nLa matriz del grafo es la siguiente:\n";
    grafo.imprimirMatrizGrafo();
}
