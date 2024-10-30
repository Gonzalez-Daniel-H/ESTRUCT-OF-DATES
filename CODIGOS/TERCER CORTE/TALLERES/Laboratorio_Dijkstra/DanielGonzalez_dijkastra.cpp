/**************************************************
 * Autores: Nicolas Algarra Polanco y Daniel Gonzalez
 * Clase: Estructuras de datos
 * Profesor: John Corredor
 * Programa: DanielGonzalez_dijkastra.cpp
 * Objetivo: Se desea implementar el algoritmo de dijkstra para calcular la menor distancia de un vertice a otros en un grafo
 * Fecha: 30/10/2024 
**************************************************/
#include <iostream>
#include <limits.h>

using namespace std;

#define NUM_VERTICES 7 // Numero de vertices que contiene el grafo

// Esta función retorna el vertice en la con menor distancia hacia el vertice seleccionado y que no ha sido visitado aun
int miniDist(int distance[], bool Tset[]) {
    int minimum=INT_MAX,ind;

    for(int k=0;k<NUM_VERTICES;k++)
    {
        if(Tset[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

// Funcion que imprime en pantalla la menor distancia desde el nodo "src" del grafo, hasta los demas usando el algoritmo de Dijkstra
void DijkstraAlgo(int graph[NUM_VERTICES][NUM_VERTICES],int src) {
    int distance[NUM_VERTICES]; // Arreglo de distancias para cada nodo
    bool Tset[NUM_VERTICES]; // Arreglo de booleanos que indica si el nodo en x posicion ya fue visitado

    // Se inician los arreglos para cada posicion
    for(int k = 0; k<NUM_VERTICES; k++){
        distance[k] = INT_MAX; // Se inician todas las distancias como "infinitos"
        Tset[k] = false; // Se indica que no se ha visitado ningun vertice
    }

    distance[src] = 0;

    // Se calcula la distancia para cada nodo usando Dijkstra
    for(int k = 0; k<NUM_VERTICES; k++) {
        int m=miniDist(distance,Tset);
        Tset[m]=true;
        for(int k = 0; k<NUM_VERTICES; k++){
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }

    // Se imprimen las distancias en pantalla
    cout<<"Vertice \t\t Distancia desde la fuente al Vertice" << endl;
    for(int k = 0; k<NUM_VERTICES; k++){
        char str=65+k;
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main() {
    int graph[NUM_VERTICES][NUM_VERTICES]={ // Se define la matriz de adyacencia del grafo
        {0, 2, 4, 0, 0, 0, 0}, 
        {2, 0, 0, 5, 0, 0, 0}, 
        {4, 0, 0, 8, 0, 0, 0}, 
        {0, 5, 8, 0, 10, 15, 0}, 
        {0, 0, 0, 10, 0, 6, 2}, 
        {0, 0, 0, 15, 6, 0, 6}, 
        {0, 0, 0, 0, 2, 6, 0}};
    DijkstraAlgo(graph,0); // Se desarrolla el algoritmo de dijkstra en base al vertice 0 (A)
    return 0;
}
