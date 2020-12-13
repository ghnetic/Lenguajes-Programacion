#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
**ERRORES
	NO VERIFICA SI EMPIEZA CON INICIO
	HAY VARIAS PARTES MARCADA COMO "REVISAR" QUE NECESITAN ATENCION
	NO RECONOCE LAS COMAS COMO SIMBOLOS
*/


void AnalizadorDeCaracter(char car);// Esta funcion se encarga del leer caracter a caracter las palabras para asignarle un estado 
void Estados();//Esta funcion manda los estados de los caracteres leidos
void BuscarReservadas();//Esta funcion se encarga de buscar entre el arreglo de palabras reservadas

const char *reservadas[] = {"encender","apagar","inicio","definir","repetir","fin","mientras","si","sino"}; //arreglo de palabras reservadas

int IndicadorTam=sizeof(reservadas)/sizeof(char *);//El tamano de nuestras las reservadas y el tamano de memoria de el char
int i; //Auxiliar para los ciclos
char palabraIngresada[50]; //Se encarga de guardar y almacenar los caracteres concatenados que forman las palabras
char temp[2]; //temporal para guardar caracteres de una cadena
enum TEstados{q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,q13,q14,q15,q16,q17,q18,q19,q20};
//iniciando el estado en q0
TEstados Estado=q0;
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
	FILE *archivoE; //Archivo de entrada (Incluy el lenguaje a analizar)
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
	printf( "Exitoso.\n" ) ;
	
   	while (1){
	   //fgetch toma el texto del archivo y itera caracter a caracter
	  	caracter=fgetc(archivoE);
	  	if(caracter==EOF){ //EOF:End Of File
	  	break;
	  	}
	  
		//analiza el punto y coma
		AnalizadorDeCaracter(caracter);
		if(caracter==';'){
			contadorSimbolos;
		}
	}
	i++;

   
	/*
		La tabla es impresa de 2 maneras distintas,
		primero es impresa en consola y despues en salida.txt
	*/
	//Imprimos en consola
   	printf("\n\n**********TABLAS DE ELEMENTOS**********\n\n");   
	printf("Palabras Reservadas: %d\n", contadorPalabrasReservadas);
	printf("Variables: %d\n", contadorVariables);
	printf("Numeros: %d\n", contadorNumeros);
	printf("Aritmeticos: %d\n", contadorSignos);
	printf("Simbolos: %d\n", contadorSimbolos);
	printf("Encender: %d\n", contadorEncender);
	printf("Apagado: %d\n", contadorApagado);
	printf("Ciclos: %d\n", contadorCiclos/2);
			
	fputs("\n\n**********TABLAS DE ELEMENTOS**********\n\n", archivoS);
	fprintf(archivoS, "Palabras Reservadas: %d", contadorPalabrasReservadas);
	fprintf(archivoS, "\nVariables: %d", contadorVariables);
	fprintf(archivoS, "\nNumeros: %d", contadorNumeros);
	fprintf(archivoS, "\nAritmeticos: %d", contadorSignos);
	fprintf(archivoS, "\nSimbolos: %d", contadorSimbolos);
	fprintf(archivoS, "\nEncender: %d", contadorEncender);
	fprintf(archivoS, "\nApagado: %d", contadorApagado);
	fprintf(archivoS, "\nCiclos: %d", contadorCiclos/2);
			
}


void AnalizadorDeCaracter(char letra){
		
		if(letra==32||letra=='}'||letra=='{'
		||letra=='('||letra==')'||letra==';'){
			Estados();
		}
		
		if( letra>='A' && letra<='Z' ){
			if(Estado==q0){
				Estado=q1;
			}else if(Estado==q1||Estado==q2){
				Estado=q2;
			}
			else if(Estado!=q0 && Estado!=q1 && Estado!=q2){
				exit(-1);
			}
		}
		
		if(letra>='a' && letra<='z'){
			if(Estado==q0){
				tmp[0]=letra; 
				strcat(identificador,tmp); 
				Estado=q3;
			}else if(Estado==q1||Estado==q2){
				Estado=q2;
			}
			else if(Estado==q3){
				tmp[0]=letra; 
				strcat(identificador,tmp);
				Estado=q3;}
			else{
				printf("\nNo es valido"); 
				exit(-1);
			}
		}
		if(letra<='9'&&letra>='0'){
			if(Estado==q0){
				Estado=q4;
			}else if(Estado==q4||Estado==q5){
				Estado=q5;
			}else if(Estado==q13||Estado==q6){
				Estado=q6;
			}else if(Estado==q1||Estado==q2){
				Estado=q2;
			}else if(Estado==q7){
				Estado=q4;
			}else{
				exit(-1);
			}
		}
		if(letra=='+'){
			if(Estado==q0){
				Estado=q8;
			}else if(Estado==q8){
				Estado=q17;
			}
		}
		
		if(letra=='.'){
			if((letra)<'1' || (letra)>='9'){
				Estado=q19;
			}else{
				if(Estado==q4||Estado==q5&&((letra)=='1'||(letra)=='2'
				||(letra)=='3'||(letra)=='4'||(letra)=='5'||(letra)=='6'
				||(letra)=='7'||(letra)=='8'||(letra)=='9')){
					Estado=q20;
				}
				else if(Estado!=q4 && Estado!=q5){
					exit(-1);
				}
			}
		}
		if(letra=='^'){
			if(Estado==q0){
				Estado=q18;
			}
			else{
				exit(-1);
			} 
		}
		
		if(letra=='-'){
			if(Estado==q0){
				Estado=q7;
			}else if(Estado==q12){
				Estado=q10;}
		}	else if(Estado==q7){
			Estado=q17;
		}
		
		if(letra=='='){
			if(Estado==q0){
				Estado=q9;
			}else if(Estado==q18){
				Estado=q11;
			}
		}else if(Estado==q12){
			Estado=q16;
		}else if(Estado==q13){
			Estado=q15;
		}
		
		
		if(letra=='/'||letra=='*'){
			if(Estado==q0){
				Estado=q18;
			}else{
				exit(-1);
			}
		}
		
		if(letra=='<'){                
			if(Estado==q0){
				Estado=q12;
			}else{
				exit(-1);
			}
		}
		if(letra=='>'){   
			if(Estado==q0){
				Estado=q14;
			}else{
				exit(-1);
			}
		}	
		
		
		if(letra=='!'){
			if(Estado==q0){
				Estado=q18;
			}else{
				exit(-1);
			} 
		}

}  // FINAL


//Funcion encargada de buscar en nuestro arreglo de palabras reservadas
void Reservadas(){
	for(int i=0;i<IndicadorTam;i++){
		//strcmp se encarga de comparar caracter por caracter dos Strings
		//reservadas[i] son las palabras reservadas que declaramos como variable global al inicio del programa
		//identificados es la palabra que el analizador lexico encontro
		if(strcmp(reservadas[i],identificador)==0){
			//Cuenta las palabras reservadas que encuentre
			contadorPalabrasReservadas++;
			identificador[0]='\0';
			break;
		}
		if(i==(IndicadorTam)-1){
			exit(-1);
		}
	}		
}


//Funcion que analiza caracter a carater y decide a que tipo de elemento pertenec
void Estados(){
	
	switch(estado){
			case 1:contadorVariables++; 	// Suma variables A ... Z							//Estado vuelve ser 0
			break;
			case 2:contadorVariables++; 	//  A ... Z	 a ... z  0 ... 9	
			break;
			case 3: BuscarReservadas();		// Palabras reservadas
			break;
			case 4:contadorNumeros++; 		//Numeros 0 ... 9
			break;
			case 5:contadorNumeros++; 		// 0 ... 9
			break;
			case 6:contadorNumeros++; 		// 0 ... 9
			break;
			case 7:contadorSignos++;			// -
			break;
			case 8:contadorSignos++; 			// +
			break;
			case 9:contadorSimbolos++; 			// =
			break;
			case 10:contadorSignos++; 			// -
			break;
			case 11:contadorSimbolos++; 		// =
			break;
			case 12:contadorSimbolos++; 		// <
			break;
			case 14:contadorSimbolos++; 		// >
			break;
			case 15:contadorSimbolos++; 		// = 
			break;
			case 16:contadorSimbolos++; 		// =;
			break;
			case 17:contadorSignos++; 			// - +
			break;
			case 18:contadorSignos++; 			//  / * ^ !
			break;
			case 19:contadorSimbolos++; 		// . \n \t etc... 
			break;
			case 20:contadorNumeros++; 			// .   0 ... 9				Para decimal
			break;
			default:
				break;
			}	
			
			estado = 0;	
}
