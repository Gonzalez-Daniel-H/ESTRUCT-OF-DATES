/************************************
 Nombres: DANIEL GONZALEZ,JULIANA PACHECO, NICOLAS ALGARA
 TEMA: Proyecto Final
 FECHA: 02/11/2024
 ***********************************/
#include "Libs/Comando.h"
#include "Libs/Objeto.h"
#include "Libs/FuncionesMain.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    list<Comando> comandos=CargarComandos();
    list<Objeto> objetos;
    while (true)
    {
        CargarComando(comandos,objetos);  
    }
}
