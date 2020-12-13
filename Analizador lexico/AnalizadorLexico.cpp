#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones momentaneamente comentadas
//void AnalizadorDeCaracter(char car);// Esta funcion se encarga del leer caracter a caracter las palabras para asignarle un estado 
//void Estados();//Esta funcion manda los estados de los caracteres leidos
//void BuscarReservadas();//Esta funcion se encarga de buscar entre el arreglo de palabras reservadas

const char *reservadas[] = {"encender","apagar","inicio","definir","repetir","fin","mientras","si","sino"}; //arreglo de palabras reservadas

int IndicadorTam=sizeof(reservadas)/sizeof(char *);//El tamano de nuestras las reservadas y el tamano de memoria de el char
int i; //Auxiliar para los ciclos
char identificador[99]; //un identificador para auxiliar la asignación de estados
char tmp[2]; //temporal para guardar caracteres de una cadena
int estado=0; //El estado es un entero el cual representa el valor de lo encontrado. Ejemp: Variable, reservada, simbolo, etc

//Estos son los contadores de los elementos de la tabla
int contadorVariables=0;
int contadorNumeros=0;
int contadorPalabrasReservadas=0;
int contadorSimbolos=0;
int contadorSignos=0;
int contadorEncender=0;
int contadorApagado=0;
int contadorCiclos=0;

int main(){
	FILE *archivoE; //Archivo de entrada (Incluye el lenguaje a analizar)
	FILE *archivoS; //Archivo de salida (Donde se imprime la tabla)
   
	printf("---- ANALIZADOR LEXICO en C++ ---\n");
	printf("Preparando archivo.....\n");
   
	archivoE=fopen("entrada.txt", "r" ); //Abrimos el archivo que vamos a leer
	archivoS=fopen("salida.txt", "wt"); //Preparamos el archivo de escritura
   
	char caracter;
	//Validamos si el archivo existe
    if ( archivoE == NULL ) {
		printf ( "El archivo no fue encontrado. \n" ) ;
     	return 1;
   	}
    printf( "Leyendo entrada.txt....\n" ) ;
	printf( "Archivo list....\n" ) ;
	
   	while (1){
	   //fgetch toma el texto del archivo y itera caracter a caracter
	  	caracter=fgetc(archivoE);
	  	if(caracter==EOF){ //EOF:End Of File
	  	break;
	  	}
	  	//Verificamos que el programa empieza con la palabra reservada "inicio"
	  	while(i==0){
		   	if(caracter!='i'&&caracter!='n'&&caracter!='i'&&caracter!='c'&&caracter!='i'&&caracter!='o'){
			   	printf("\n\nError, No se encontro el inicio");
		   		exit(-1);
			}
		   	i=1;
	  	}
	  
		//analiza nuestros caracteres mas generales aun no esta construido
		//AnalizadorDeCaracter(caracter);
   	}
 
			
}
