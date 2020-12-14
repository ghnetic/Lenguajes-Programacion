#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones momentaneamente comentadas
void AnalizadorDeCaracter(char letra);// Esta funcion se encarga del leer caracter a caracter las palabras para asignarle un estado 
void Estados();//Esta funcion manda los estados de los caracteres leidos
void PalabrasReservadas();//Esta funcion se encarga de buscar entre el arreglo de palabras reservadas

const char *reservadas[] = {"encender","apagar","inicio","definir","repetir","fin","mientras","si","sino"}; //arreglo de palabras reservadas

int IndicadorTam=sizeof(reservadas)/sizeof(char *);//El tamano de nuestras las reservadas y el tamano de memoria de el char
int i; //Auxiliar para los ciclos
char identificador[99]; //un identificador para auxiliar la asignacion de estados
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
		AnalizadorDeCaracter(caracter);
			switch(caracter){
			//caso opcional ya que no usamos parentesis en el lenguaje nuestro
			case '(':contadorSimbolos++;
				break;
			case ')':contadorSimbolos++;
				break;
			case '{':contadorSimbolos++;
				break;
			case '}':contadorSimbolos++;
				break;
			//caso requerido
			case ';':contadorSimbolos++;
				break;
		}
		i++;
   	}
 
			
}


void AnalizadorDeCaracter(char letra){
		
		if(letra==32||letra=='}'||letra=='{'||letra=='('
		||letra==')'||letra==';'){
			Estados();
		}
		
		if( letra>='A' && letra<='Z' ){
			if(estado==0){
				estado=1;
			}else if(estado==1||estado==2){
				estado=2;
			}
			else if(estado!=0 && estado!=1 && estado!=2){
				printf("\nNo es valido");
				exit(-1);
			}
		}
		if(letra>='a' && letra<='z'){
			if(estado==0){
				tmp[0]=letra; 
				strcat(identificador,tmp); 
				estado=3;
			}else if(estado==1||estado==2){
				estado=2;
			}
			else if(estado==3){
				tmp[0]=letra; 
				strcat(identificador,tmp);
				estado=3;}
			else{
				printf("\nNo es valido"); 
				exit(-1);
			}
		}
if(letra<='9'&&letra>='0'){
			if(estado==0){
				estado=4;
			}else if(estado==4||estado==5){
				estado=5;
			}else if(estado==13||estado==6){
				estado=6;
			}else if(estado==1||estado==2){
				estado=2;
			}else if(estado==7){
				estado=4;
			}else{
				printf("\n ERROR"); 
				exit(-1);
			}
		}
		if(letra=='+'){
			if(estado==0){
				estado=8;
			}else if(estado==8){
				estado=17;
			}
		}
		if(letra=='.'){
            if((letra)<'1' || (letra)>='9'){
                estado=19;
            }else{
                if(estado==4||estado==5&&((letra)=='1'||(letra)=='2'||(letra)=='3'
					||(letra)=='4'||(letra)=='5'||(letra)=='6'||(letra)=='7'||(letra)=='8'
					||(letra)=='9')){
                    estado=20;
                }
                else if(estado!=4 && estado!=5){
                    printf("\n ERROR"); 
                    exit(-1);
                }
            }
        }
       if(letra=='^'){
            if(estado==0){
                estado=18;
            }
            else{
                printf("\n ERROR '^'");
                exit(-1);
            } 
        }
        if(letra=='-'){
            if(estado==0){
                estado=7;
            }else if(estado==12){
                estado=10;}
        }   else if(estado==7){
            estado=17;
        }
        if(letra=='='){
            if(estado==0){
                estado=9;
            }else if(estado==18){
                estado=11;
            }
        }else if(estado==12){
            estado=16;
           }else if(estado==13){
                 estado=15;
           }
        
        
        if(letra=='/'||letra=='*'){
            if(estado==0){
                estado=18;
            }else{
                printf("ERROR");
                exit(-1);
            }
        }
        if(letra=='<'){                
            if(estado==0){
                estado=12;
            }else{
                printf("ERROR '<'");
                exit(-1);
            }
        }
        if(letra=='>'){   
            if(estado==0){
                estado=14;
            }else{
                printf("ERROR '>'");
                exit(-1);
            }
        }   
        
        
        if(letra=='!'){
            if(estado==0){
                estado=18;
            }else{
                printf("\n ERROR '!'");} 
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



void Estados(){
	
	switch(estado){
			case 1:contadorVariables++; 	// Suma variables A ... Z	
			estado=0;						
			break;
			case 2:contadorVariables++; 	//  A ... Z	 a ... z  0 ... 9	
			estado=0;
			break;
			case 3: BuscarReservadas();		// Palabras reservadas
			estado=0;
			break;
			case 4:contadorNumeros++; 		//Numeros 0 ... 9
			estado=0;
			break;
			case 5:contadorNumeros++; 		// 0 ... 9
			estado=0;
			break;
			case 6:contadorNumeros++; 		// 0 ... 9
			estado=0;
			break;
			case 7:contadorSignos++;			// -
			estado=0;
			break;
			case 8:contadorSignos++; 			// +
			estado=0;
			break;
			case 9:contadorSimbolos++; 			// =
			estado=0;
			break;
			case 10:contadorSignos++; 			// -
			estado=0;
			break;
			case 11:contadorSimbolos++; 		// =
			estado=0;
			break;
			case 12:contadorSimbolos++; 		// <
			estado=0;
			break;
			case 14:contadorSimbolos++; 		// >
			estado=0;
			break;
			case 15:contadorSimbolos++; 		// = 
			estado=0;
			break;
			case 16:contadorSimbolos++; 		// =
			estado=0;
			break;
			case 17:contadorSignos++; 			// - +
			estado=0;
			break;
			case 18:contadorSignos++; 			//  / * ^ !
			estado=0;
			break;
			default:
				break;
			}		
}
