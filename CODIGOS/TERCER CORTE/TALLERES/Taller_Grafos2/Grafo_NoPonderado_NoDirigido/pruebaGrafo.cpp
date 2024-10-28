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

    // Se crean los vertices
    Vertice vertice1(1);
    Vertice vertice2(2);
    Vertice vertice3(3);
    Vertice vertice4(6); // Vertice de prueba que no estara en el grafo
    Vertice* ptrVertice; // Apuntador de vertice

    // Se crean las aristas
    Arista arista1(&vertice1,&vertice2);
    Arista arista2(&vertice2,&vertice3);
    Arista* ptrArista; // Apuntador de arista

    grafo.agregarVertice(&vertice1);
    grafo.agregarVertice(&vertice2);
    grafo.agregarVertice(&vertice3);
    cout << "Vertices agregados correctamente\n";

    grafo.agregarArista(&arista1);
    grafo.agregarArista(&arista2);
    cout << "Aristas agregados correctamente\n";

    cout << "\nLa matriz del grafo es la siguiente:\n";
    grafo.imprimirMatrizGrafo();

    cout << "\nEl grafo contiene " << grafo.obtenerCantidadVertices() << " vertices y " << grafo.obtenerCantidadAristas() << " aristas\n";

    // Se prueba la funcion buscarVerticePorDato
    cout << "\nSe busca el vertice con dato 2\n";
    cout << "La direccion en memoria del vertice con dato 2 es " << grafo.buscarVerticePorDato(2) << endl;
    cout << "Se busca el vertice con dato 3\n";
    cout << "La direccion en memoria del vertice con dato 3 es " << grafo.buscarVerticePorDato(3) << endl;
    cout << "Se busca el vertice con dato 6\n";
    cout << "La direccion en memoria del vertice con dato 6 es " << grafo.buscarVerticePorDato(6) << endl; // A pesar de existir un vertice con dato 6, el resultado sera null pues no esta en el grafo

    // Se prueba la funcion buscarAristaPorVertices
    cout << "\nSe busca la arista que contenga a los vertices con dato 1 y 2\n";
    cout << "La direccion en memoria de la arista es " << grafo.buscarAristaPorVertices(*grafo.buscarVerticePorDato(1),*grafo.buscarVerticePorDato(2)) << endl;
    cout << "Se busca la arista que contenga a los vertices con dato 1 y 3\n";
    cout << "La direccion en memoria de la arista es " << grafo.buscarAristaPorVertices(*grafo.buscarVerticePorDato(1),*grafo.buscarVerticePorDato(3)) << endl; // A pesar de ambos vertices estar en el grafo, la arista no existe, por lo que retorna null
}
