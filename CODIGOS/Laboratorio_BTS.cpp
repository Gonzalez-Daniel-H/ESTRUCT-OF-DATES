/****************************************
Autor: Nicolas Algarra Polanco y Daniel Gonzalez
Fecha: 28 de agosto 2024
Materia: Estructura de Datos
Tema: implementacion BST 
****************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

// Se crea una estructura que va a representar cada nodo dentro del arbol
struct Nodo{
	int dato; //Cada nodo guardara un dato tipo entero
	struct Nodo *left, *right; // A cada nodo se le relacionara otros 2 nodos diferentes, uno a la izquierda y otro a la derecha, formando dos posibles aristas
};	

// Se crea un nuevo nodo que guardara un dato dado el cual no tendra ningun nodo hijo y se retornara este nuevo nodo
struct Nodo *nuevoNodo(int dato){
	struct Nodo *temporal = new struct Nodo();  // Se crea un nuevo nodo vacio
	temporal->dato = dato; // Se le asigna al dato del nodo, el valor dato dado por parametro
	temporal->left = temporal->right = NULL; 
	return temporal;
}

/*
* Se crearan 3 funciones diferentes que imprimiran cada uno de los datos dentro del arbol siguiendo
* los 3 tipos diferentes de busqueda DFS (preorder, inorder, postorder)
*/

/******* Preorder *********/

// Muestra los datos desde arriba a abajo
void preOrdenT(struct Nodo *raiz){
	if (raiz==NULL)
		return;
	cout << raiz->dato << "->"; 
	preOrdenT(raiz->left);
	preOrdenT(raiz->right);
}

/******* Postorder *********/

// Muestra los datos desde abajo hasta arriba
void postOrdenT(struct Nodo *raiz){
	if (raiz==NULL)
		return;
	postOrdenT(raiz->left);
	postOrdenT(raiz->right);
	cout << raiz->dato << "->"; 
}

/******* Inorder *********/

// Muestra los datos de izquierda a derecha
void inOrdenT(struct Nodo *raiz){
	if (raiz==NULL)
		return;
	inOrdenT(raiz->left);
	cout << raiz->dato << "->"; 
	inOrdenT(raiz->right);
}

/****** Insertar nuevo nodo, dado un valor (BST) ********/
struct Nodo *insertarBST(struct Nodo *nodo, int newDato){
	if (nodo==NULL)
		return nuevoNodo(newDato);
	if (newDato < nodo->dato)
		nodo->left = insertarBST(nodo->left, newDato);
	else
		nodo->right = insertarBST(nodo->right, newDato);

	return nodo;
}


/****** funcion que retorna el nodo con menor valor en un BST ********/
struct Nodo *minValorNodo(struct Nodo *nodo){
	struct Nodo *actual = nodo;
	/*Se busca iterativamente el elemento menor a la izquierda*/
	while(actual && actual->left !=NULL)
		actual = actual->left;
	return actual;
}


/****** funcion que elimina un nodo con valor en un BST ********/
struct Nodo *borrarNodo(struct Nodo *nodo, int dato){
	/*=Arbol vacio=*/
	if(nodo == NULL)
		return nodo;
	/*=si el valor es menor a la raiz, ir por la izquierda=*/
	if(dato < nodo->dato)
		nodo->left = borrarNodo(nodo->left, dato);
	/*=si el valor es mayor a la raiz, ir por la derecha=*/
	else if (dato > nodo->dato)
		nodo->right = borrarNodo(nodo->right, dato);
	/*=el valor esta en la misma raiz=*/
	else {
		/*=Nodo con solo un hijo o sin hijos=*/	
		if(nodo->left == NULL){
			struct Nodo *temporal = nodo->right;
			free(nodo);
			return temporal;
		}else if(nodo->right == NULL){
			struct Nodo *temporal = nodo->left;
			free(nodo);
			return temporal;
		}
		/*=Nodo con ambos hijos, tomar el sucesor y borrar el nodo=*/
		struct Nodo *temp = minValorNodo(nodo->right);
		/*=copiar el contenido InOrder sucesor a el nodo=*/
		nodo->dato = temp->dato;
		/*=borrar el InOrder sucesor=*/
		nodo->right = borrarNodo(nodo->right, temp->dato);
	}
	return nodo;
}



int main(){
	struct Nodo *arbol1 = NULL; 
	arbol1 = insertarBST(arbol1, 40);
	arbol1 = insertarBST(arbol1, 30);
	arbol1 = insertarBST(arbol1, 60);
	arbol1 = insertarBST(arbol1, 65);
	arbol1 = insertarBST(arbol1, 70);
	
	cout << "\n -PreOrden ";  
	preOrdenT(arbol1);
	cout << "\n -PostOrden "; 
	postOrdenT(arbol1);
	cout << "\n -InOrden ";
	inOrdenT(arbol1);

	cout << "Se elimina el nodo(40)" << endl;
	arbol1 = borrarNodo(arbol1, 40);
	inOrdenT(arbol1);
	
	
	// Nuevo ejercicio
	
	Nodo* arbol2 = NULL;
	arbol2 = insertarBST(arbol2, 1);
	arbol2 = insertarBST(arbol2, 2);
	arbol2 = insertarBST(arbol2, 3);
	arbol2 = insertarBST(arbol2, 4);
	
	cout << "\n -PreOrden ";  
	preOrdenT(arbol2);
	cout << "\n -PostOrden "; 
	postOrdenT(arbol2);
	cout << "\n -InOrden ";
	inOrdenT(arbol2);

	return 0;	
}



