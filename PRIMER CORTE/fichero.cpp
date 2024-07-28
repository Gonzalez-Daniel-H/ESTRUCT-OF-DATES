#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int sumaRecursiva(int n){
	if(n <= 1) {
		return n;
	}
	else{
		return n + sumaRecursiva(n-1);
	}
}

int cuadradosPares(int n){
	if(n == 0){
		return n;
	}
	else if(n % 2 == 0) {
		return n*n + cuadradosPares(n-1);
	} else {
		return cuadradosPares(n - 1);
	}
}

int cuadradosPares2(int n){
	if(n == 0){
		return n;
	} else {
		return pow(n+n,2) + cuadradosPares2(n - 1);
	}
}

int fibNumero(int n){
 	if(n <= 1){
		return n;
	} else {
		return fibNumero(n-1) + fibNumero(n-2);
	}
}


bool lineal(string s, char c, int l){
	if(l < 0){
		return false;
	} else if (s[l] == c){
		return true;		
	} else {
		return lineal(s, c, l-1);
	}
}


int main(){
	int sumaRecursiva(int n);
	int cuadradosPares(int n);
	int cuadradosPares2(int n);
	int fibNumero(int n);
	string palabra = "Palabra";
	char substring = 'g';
	bool caracter = lineal(palabra, substring, palabra.length()-1);
	int opcion,n;


	while(1){
		
	cout<<" Que operacion desea hacer \n 1: Suma \n 2: Cuadrados \n 3: Fibnumero \n 4: Salir "<<endl;
	cin>>opcion;
	if(opcion==1 || opcion==2 || opcion==3){
	
	cout<<" que numero desea operar"<<endl;;
	cin>>n;
	
	}
	
	
	switch (opcion){
		case 1:
			sumaRecursiva(n);
			cout<<" la respuesta es \n "<<sumaRecursiva(n)<<endl;

			break;
		case 2:

			cuadradosPares2(n);
			cout<<" la respuesta es \n"<<cuadradosPares2(n)<<endl;

			break;
		case 3:
			fibNumero(n);
			cout<<" la respuesta es \n"<<fibNumero(n)<<endl;

		case 4:
			cout<<"Gracias por su coperacion, vuelva pronto \n"<<endl;
			break;
			
			default:
				cout<<"opcion incorrecta vuelva a selecionar alguna \n"<<endl;
			break;
		
			}
				if(opcion==4){
					break;
		}
	}




	
}
