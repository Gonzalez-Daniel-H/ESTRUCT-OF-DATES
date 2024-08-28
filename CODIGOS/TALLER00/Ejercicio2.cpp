/*
Autor: Daniel Gonzalez
Fecha: 21/08/2024
Tema: Taller00 Estructuras y punteros

*/
// EJERCICIO 02
#include <iostream>
#include <fstream>
using namespace std;

struct factura {
    string nombre;
    int cedula;
    int cantidad;
    double precio;
    string NombreProducto;
};

// Función para solicitar los datos del cliente y producto
void ingresarDatos(factura *puntero) {
    cout << "Ingrese el nombre del Cliente: ";
    cin >> puntero->nombre;
    cout << "Ingrese la Cedula del Cliente: ";
    cin >> puntero->cedula;
    cout << "Ingrese el nombre del Producto: ";
    cin >> puntero->NombreProducto;
    cout << "Ingrese la Cantidad del Producto: ";
    cin >> puntero->cantidad;
    cout << "Precio del producto: ";
    cin >> puntero->precio;
}

// Función para escribir los datos en un archivo
void escribirEnArchivo(factura *puntero) {
    ofstream archivo("factura.txt");

    if (archivo.is_open()) {
        archivo << "Nombre del Cliente: " << puntero->nombre << endl;
        archivo << "Cedula del Cliente: " << puntero->cedula << endl;
        archivo << "Nombre del Producto: " << puntero->NombreProducto << endl;
        archivo << "Cantidad del Producto: " << puntero->cantidad << endl;
        archivo << "Precio del producto: " << puntero->precio << endl;
        archivo << "Valor a pagar: " << puntero->cantidad * puntero->precio << endl;
        archivo.close();
        cout << "Factura generada correctamente en 'factura.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }
}

// Función para imprimir los datos en la consola
void imprimirFactura(factura *puntero) {
    cout << "\n--- Factura ---" << endl;
    cout << "Nombre del Cliente: " << (*puntero).nombre << endl;
    cout << "Cedula del Cliente: " << (*puntero).cedula << endl;
    cout << "Nombre del Producto: " << (*puntero).NombreProducto << endl;
    cout << "Cantidad del Producto: " << (*puntero).cantidad << endl;
    cout << "Precio del producto: " << (*puntero).precio << endl;
    cout << "Valor a pagar: " << (*puntero).cantidad * (*puntero).precio << endl;
}

int main() {
    // Asignar memoria para la estructura
    factura *puntero = new factura;

    ingresarDatos(puntero);
    imprimirFactura(puntero);
    escribirEnArchivo(puntero);

    // Liberar memoria asignada dinámicamente
    delete puntero;

    return 0;
}

