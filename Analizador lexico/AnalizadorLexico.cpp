#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipo de funciones
void analizador(); //funcion que cambia/analiza los estados o verifica errores
void Estado();  //verifica al estado que pertenece
void buscar();  //compara identificador con la tabla de simbolos, nos dice si ecuentra o no

//Variables globales
char *tablaDeSimbolos[] = {"definir, enceder, repetir, mientras, finrepetir, apagar"};
char identificador[99];
int tamIndicador=sizeof(tablaDeSimbolos)/sizeof(char *); //devuelve el tamaño en bytes que abarca la variable
int i; //manejo de ciclos
int estado=0; //el entero que asignara el estado
FILE entradaF;
FILE salidaF;

//contadores
int variablesCont=0;
int encenderCont=0;
int apagarCont=0;
int cicloCont=0;
int aritmeticaCont=0;


int main(){

    int a = 0;

}
