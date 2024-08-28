/**************************************************************
Autor: Daniel Gonzalez
Materia: Sistemas Operativos
Fecha: 17/07/24
*****************************************************************/
#include <iostream>

using namespace std;


class Cafetera {
public:
    virtual void Capuchino() = 0;
    virtual void Tinto() = 0; 
};

class Oster : public Cafetera {
public:
    void Capuchino() override {
        cout << "Oster haciendo capuchino!!!" << endl;
    }

    void Tinto() override {
        cout << "Oster haciendo tinto!!!" << endl;
    }
};


class Haceb : public Cafetera {
public:
    void Capuchino() override {
        cout << "Haceb haciendo capuchino!!!" << endl;
    }

    void Tinto() override {
        cout << "Haceb haciendo tinto!!!" << endl;
    }
};

int main() {

     int opcion=0;


    Cafetera* c_Oster = new Oster();
    Cafetera* c_Haceb = new Haceb();
   

    while(1){
    cout<<"Que desea Ordenar? \n 1. Capuchino con Oster \n 2. Tinto con Oster\n 3. Capuchino con Haceb \n 4. Tinto con Haceb\n 5. Salir \n"<<endl;
    cin>>opcion;
    
    switch(opcion){
        case 1:
            c_Oster->Capuchino();
            break;
        case 2:
            c_Oster->Capuchino();
            break;
        case 3:
            c_Oster->Tinto();
            break;
        case 4:
            c_Haceb->Capuchino();
            break;
        case 5:
            cout<<"\nGracias por su compra ";
            break;
        
        default:
        cout<<"\nOpcion incorrecta agregue una de las que aparecen en el menu \n "<<endl;
    }

        if(opcion==5){
        break;
        }
    }

    return 0;
}
