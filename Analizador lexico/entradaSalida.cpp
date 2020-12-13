#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

void entrada();
void salida();
int contadorCiclos=2;
int contadorReservadas=222223;

int main(){
	
	entrada();
	salida();

}

void entrada(){
	cout<<"- - - - - Analizador Lexico C++ - - - - -\n";
	cout<<"Abriendo...\n";
	ifstream archivo;
	string contenido;

	archivo.open("entrada.txt", ios::in); 
	
	if(archivo.fail()){
		cout<<"\nError al abrir el archivo entrada.txt ...";
		exit(1);
	}else{
		cout<<"Exitoso.\n\n\n";
	}
	
	if(archivo==NULL){
			cout<<"El archivo esta vacio.";
		}else{
			cout<<"\nInstrucciones en el archivo de texto:\n";
			while(!archivo.eof()){ 
			getline(archivo,contenido);
			cout<<contenido<<endl;
		}
	}
	
	archivo.close();
}

void salida(){
	ofstream archivo;
	archivo.open("salida.txt", ios::app);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	archivo<<"\nPalabras Reservadas: "<<contadorReservadas;
	archivo<<"\nCiclos: "<<contadorCiclos;
	archivo.close();
}
