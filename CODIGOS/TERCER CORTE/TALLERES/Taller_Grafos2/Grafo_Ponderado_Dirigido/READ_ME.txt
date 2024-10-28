COMPILACIÓN:
Para compilar este programa usar el siguiente comando:
	g++ *.cpp -o ejecutable

Y para ejecutarlo usar el comando
	./ejecutable.exe

RESULTADOS:
El código debe mostrar la siguiente matriz del grafo

   | 1 2 3
---+------
 1 | 0 5 0
 2 | 0 0 7
 3 | 0 0 0

Donde cada fila y columna corresponde al dato en cada nodo. Y los números dentro de la matriz a las aristas del grafo y sus correspondientes pesos 

Tambien se mostrara las siguientes líneas:

El grafo contiene 3 vertices y 2 aristas (Se muestra la cantidad de vertices y aristas que tiene el grafo)

Se busca el vertice con dato 2
La direccion en memoria del vertice con dato 2 es {dir del vertice2}
Se busca el vertice con dato 3
La direccion en memoria del vertice con dato 3 es {dir del vertice3}
Se busca el vertice con dato 6
La direccion en memoria del vertice con dato 6 es 0
(Se va a buscar varios vertices en el grafo y se mostrara su dirección en memoria, en caso de no existir un vertice consultado en el grafo se mostrara un 0 representado una direccion nula)

Se busca la arista que contenga a los vertices con dato 1 y 2
La direccion en memoria de la arista es {dir de arista1}
Se busca la arista que contenga a los vertices con dato 2 y 1
La direccion en memoria de la arista es 0
Se busca la arista que contenga a los vertices con dato 1 y 3
La direccion en memoria de la arista es 0
(Se va a buscar varias aristas en el grafo y se mostrara su dirección en memoria, en caso de no existir una arista en el grafo se mostrara un 0)
