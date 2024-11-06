/**************************************************
 * Autores: Nicolas Algarra Polanco y Daniel Gonzalez
 * Clase: Estructuras de datos
 * Profesor: John Corredor
 * Programa: DanielGonzalez_dijkastra.cpp
 * Objetivo: Se desea implementar el algoritmo de dijkstra para calcular la menor distancia de un vertice a otros en un grafo
 * Fecha: 06/11/2024 
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, char> Arista;

// Funcion de Dijkstra para encontrar el camino más corto entre dos nodos
pair<vector<char>, int> CaminoCorto(unordered_map<char, vector<Arista>>& grafo, char inicio, char fin) {
    unordered_map<char, int> dist;
    unordered_map<char, char> prev;
    priority_queue<Arista, vector<Arista>, greater<Arista>> pq;

    // Inicializamos las distancias
    for (auto& nodo : grafo) {
        dist[nodo.first] = INT_MAX;
    }
    dist[inicio] = 0;
    pq.push({0, inicio});

    cout << "Nodos visitados y sus distancias parciales:" << endl;

    while (!pq.empty()) {
        char u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Si llegamos al nodo final, terminamos
        if (u == fin) break;

        // Procesamos cada vecino del nodo actual
        for (auto& vecino : grafo[u]) {
            char v = vecino.second;
            int peso = vecino.first;
            int alt = d + peso;

            // Si encontramos un camino más corto al vecino
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
                pq.push({alt, v});
                cout << u << " -> " << v << ": " << alt << endl;
            }
        }
    }

    // Reconstruimos el camino desde el nodo final al inicial
    vector<char> camino;
    int distanciaTotal = dist[fin];
    for (char at = fin; at != '\0'; at = prev[at]) {
        camino.push_back(at);
        if (at == inicio) break;
    }
    reverse(camino.begin(), camino.end());
    return {camino, distanciaTotal};
}

int main() {
    // Grafo representado como lista de adyacencia, con las conexiones correctas
    unordered_map<char, vector<Arista>> grafo = {
        {'A', {{1, 'B'}, {7, 'C'}, {6, 'D'}}},
        {'B', {{1, 'A'}, {3, 'F'}, {9, 'C'}}},
        {'C', {{7, 'A'}, {9, 'B'}, {1, 'G'}, {3, 'F'}}},
        {'D', {{6, 'A'}, {2, 'E'}}},
        {'E', {{5, 'G'}, {2, 'D'}}},
        {'F', {{3, 'B'}, {3, 'G'}, {3, 'C'}}},
        {'G', {{1, 'C'}, {5, 'E'}, {3, 'F'}}}
    };

    char inicio = 'A';
    char fin = 'E';
    auto [camino, distanciaTotal] = CaminoCorto(grafo, inicio, fin);

    cout << "\nDistancia total de A hacia E es: " << (distanciaTotal != INT_MAX ? distanciaTotal : -1) << endl;

    return 0;
}
