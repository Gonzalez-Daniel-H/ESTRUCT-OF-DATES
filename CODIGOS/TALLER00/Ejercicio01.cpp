/*
Autor: Daniel Gonzalez
Fecha: 21/08/2024
Tema: Taller00 Estructuras y punteros

*/
// EJERCICIO 01
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generarNumeroAleatorio() {

    return rand() % 26; // Genera un número entre 0 y 25
}

int main(){

  srand(time(0)); //Se crea la semilla
  int array[10]; //Se declara un arreglo de 10 elementos
  int* puntero = array;// se declara el puntero que apunta al arreglo
  for(int i=0; i<10; i++){
  array[i]=generarNumeroAleatorio();//se llena el arreglo con numeros aleatorios
  }

  // Imprimir el contenido del array usando el puntero
  cout << "Contenido del array:" <<endl;
  for (int i = 0; i < 10; ++i) {
      cout << *puntero++ <<" La Direccion es : "<<puntero<<endl;
  }
  cout <<endl;

}




