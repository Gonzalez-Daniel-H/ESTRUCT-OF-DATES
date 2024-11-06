/**************************************************
 * Autores: Nicolas Algarra Polanco y Daniel Gonzalez
 * Clase: Estructuras de datos
 * Profesor: John Corredor
 * Programa: DanielGonzalez_Euleriano.cpp
 * Objetivo: Se desea implementar el algoritmo Euleriano para calcular la menor distancia de un vertice a otros en un grafo
 * Fecha: 06/11/2024 
**************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;



void mostrarCircuito(vector<vector<int>> listaAdyacencia) // listaAdyacencia hace referencia a la lista de adyacencia del grafo
{
    // gradosDeVertices es un mapa donde se representa el grado de cada vertice
    unordered_map<int,int> gradosDeVertices;
 
    for (int i=0; i<listaAdyacencia.size(); i++)
    {
        // Se agregan los vertices y el grado de cada uno
        gradosDeVertices[i] = listaAdyacencia[i].size();
    }
 
    if (!listaAdyacencia.size()){
        return; //Se retorna en caso de tener un grafo vacio
    }
 
    // Maintain a stack to keep vertices pila auxiliar que contendra los vertices que se han recorrido 
    stack<int> caminoActual;
 
    // vector que contendra todos los vertices por los que pasa el circuito Euleriano
    vector<int> circuito;
 
    // El camino se inicia desde el vertice 0
    caminoActual.push(0);
    int verticeActual = 0; // Vertice actual
 
    while (!caminoActual.empty())
    {
        // Si el grado del vertice actual no es 0 (no es un vertice final)
        if (gradosDeVertices[verticeActual])
        {
            caminoActual.push(verticeActual); // Se agrega el vertice actual al camino 
            int siguienteVertice = listaAdyacencia[verticeActual].back(); // Se asigna el ultimo vertice vecino en la lista de adyacencia 
 
            // Se elimina la arista que va desde el vertice actual al siguiente de la lista
            gradosDeVertices[verticeActual]--;
            listaAdyacencia[verticeActual].pop_back();
 
            // Se va al siguiente vertice
            verticeActual = siguienteVertice;
        }
 
        // En caso de recorrer todos los vertices
        else
        {
            // Agregar el camino recorrido como el cirtuito euleriano
            circuito.push_back(verticeActual);
            verticeActual = caminoActual.top();
            caminoActual.pop();
        }
    }
 
    // Se imprime el circuito
    for (int i=circuito.size()-1; i>=0; i--)
    {
        cout << circuito[i];
        if (i)
           cout<<" -> ";
    }
}

int main(){
    vector< vector<int> > lista1;
    lista1.resize(3);
    
    lista1[0].push_back(1);
    lista1[1].push_back(2);
    lista1[2].push_back(0);

   
        mostrarCircuito(lista1);
   
}