/***********************************************************************
 * Module:  validaciones.h
 * Author:  Edison Verdesoto
 * Modified: viernes, 20 de noviembre de 2023 11:05:38 a. m.
 * Purpose: Declaration of the class validaciones
 ***********************************************************************/

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>

int ingresar_enteros(const char* msj);
int borrar(char* datos, int& i);
float ingresar_reales(const char* msj);
std::string ingresar_alfabetico(const char* msj);

bool esEspecial(char tecla){
	return(tecla == 'c' || tecla == 's' ||tecla == 'r'  || tecla == 't');
}

bool esParentesis(char tecla){
	return (tecla == '('|| tecla == ')');
}

bool esOperador(char tecla){
	return (tecla == '+' || tecla == '-' || tecla == '*' || tecla == '/'|| tecla == '^');
}

int ingresar_enteros(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9')|| c == 8) {
            if(c == 8){
                i = borrar(datos,i);
            }else{
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}

float ingresar_reales(const char* msj) {
    char* datos = new char[12];
    char c;
    int i = 0;
    bool hay_punto = false;
    int posicion_punto;

    printf("%s", msj);
    printf("\n");

    while ((c = getch()) != 13 && i < 11) {
        if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto)|| c == 8 || c == '-') {
            if(!((c == '.')&& i == 0)){
                if(!((c == '-') && i != 0)){
                    if (c == 8) {
                        i = borrar(datos, i);
                        if((i+1) == posicion_punto){
                            hay_punto = false;
                        }
                    }
                    else {
                        printf("%c", c);
                        datos[i++] = c;

                        if (c == '.') {
                            posicion_punto = i;
                            hay_punto = true;
                        }
                    }
                }
            }
        }
    }
    datos[i] = '\0';
    return atof(datos);
}

std::string ingresar_alfabetico(const char* msj) {
    char datos[21];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = getch()) != 13 && i < 20) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| c == 32||c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            } else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return std::string(datos);
}


int borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}

int ingresarMenuOpcion(char limiteInferior, char limiteSuperior){
	char *entrada = new char[30];
	char tecla;
	int i = 0;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r' && i==1) { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tecla >= limiteInferior && tecla <= limiteSuperior && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return atoi(entrada); // convierte la entrada a un número int y lo retorna
}

int ingresarDimension(char filas, char columnas){
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	int dim;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r') { // si el usuario presiona Enter
		  dim = atoi(entrada);
		  if (dim >= 2) {
			std::cout << std::endl;
		  	break;
		  } else {
		  	std::cout << "La dimension no puede ser menor a 2" << std::endl;
		  }

		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tecla >= filas && tecla <= columnas && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return dim; // convierte la entrada a un número int y lo retorna
}

int ingresarEntero() {
	char *entrada = new char[30];
	char tecla;
	int i = 0;

	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r') { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i<12) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return atoi(entrada); // convierte la entrada a un número int y lo retorna
}

float ingresarFloat() {
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;
	while(true){
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola

		if (tecla == '\r') { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada
			i--;
			std::cout << "\b \b"; // borra el último caracter de la consola
			if (entrada[i] == '.') { // si se eliminó un punto, reinicia el flag de punto
				punto = false;
			}
			if (i == signoMenosPos) { // si se eliminó el signo menos, reinicia la posición del signo menos
				signoMenosPos = -1;
			}
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (isdigit(tecla) && i < 15) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		} else if (tecla == '.' && !punto) { // si el usuario ingresa un punto y no se ha ingresado ya uno, o si ya se ingresó uno pero se eliminó
			  entrada[i++] = tecla;
			  punto = true; // marca que se ha ingresado un punto
			  std::cout << tecla;
		} else if (tecla == '-' && i == 0) { // si el usuario ingresa un signo menos al principio
			  entrada[i++] = tecla;
			  signoMenosPos = i - 1; // marca la posición del signo menos
			  std::cout << tecla;
		}
	}

	return atof(entrada); // convierte la entrada a un número float y lo retorna
}

std::string ingresarExpresion() {
    char *entrada = new char[10000]; //Arreglo dinámico para la entrada
    char tecla;                      //Caracter de entrada
    int i = 0;                       //Contador de caracteres
    int parentesisApertura = 0;      //Contador de paréntesis de apertura
    int parentesisCierre = 0;        //Contador de paréntesis de cierre
	bool eliminarEspeciales = false; //Verificador de eliminación de sin(, cos(, tan(, raiz( y pi
	int caracteresEliminar= 0;       //Cantidad de caracteres de expresiones especiales para eliminar
	char elementoAnterior = '\0';    //Caracter anterior al actual
	bool huboPunto = false;          //Indicador de aparición de punto '.' anterior
	bool hayPunto = false;           //Indicador de aparición de punto '.'
    while (true) {
        tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
        elementoAnterior = (i > 0) ? entrada[i - 1] : '\0'; //Guarda el elemento anterior del arreglo de la entrada
    // Si el usuario presiona Enter
		if (tecla == '\r' && i > 0 && !esOperador(elementoAnterior) && elementoAnterior !='.') { //Si hay almenos un caracter en la entrada y el último no es operador
            if (parentesisApertura == parentesisCierre){ // Validar que se encuentren cerrados todos los paréntesis
            	break;
			}
	// si el usuario presiona Backspace y hay caracteres en la entrada
        }else if (tecla == '\b' && i > 0) {
        // Si el elemento a borrar es pi, sin(, cos(, tan( o raiz(
		      if (elementoAnterior == 'i' || (elementoAnterior == '(' && (entrada[i - 2] == 's' ||
			                                  entrada[i - 2] == 'n' || entrada[i - 2] == 'z'))) {
		        caracteresEliminar = 4;
				if(elementoAnterior == 'i'){
		        	caracteresEliminar = 2;
		    	}else if(entrada[i - 2] == 'z'){
		    		caracteresEliminar = 5;
				}
				eliminarEspeciales = true;
		//Si el usuario borra únicamente un paréntesis
		    } else if (esParentesis(elementoAnterior)) {
		        std::cout << "\b \b";
			    entrada[i] = 0; // elimina el último caracter de la entrada
			    i--;
			    parentesisCierre -= (elementoAnterior == ')'); //Disminución de contadores
			    parentesisApertura -= (elementoAnterior == '(');
		    }
                // Si el usuario borra un punto entonces la bandera de punto debe reiniciarse
				else if (elementoAnterior == '.'){
				std::cout << "\b \b";
		        i--;
		        entrada[i] = 0;// elimina el último caracter de la entrada
				hayPunto = false;
		    }
                //Si el usuario borra un operador y ya se ingresó un número entonces no debe reiniciar la bandera del punto
                else if (esOperador(elementoAnterior)){
		    	std::cout << "\b \b";
		        i--;
		        entrada[i] = 0;// elimina el último caracter de la entrada
				hayPunto = huboPunto;
			}else {
		        std::cout << "\b \b";
		        i--;
		        entrada[i] = 0;// elimina el último caracter de la entrada
		    }
		// Condicional para eliminar elementos especiales sin(, cos(, tan(, raiz(, pi
		    if (eliminarEspeciales){
		        for (int j = 1; j<=caracteresEliminar; j++){ //Elimina la cantidad de caracteres según la funcion
		        	std::cout << "\b \b";
		        	elementoAnterior = 0;
		        	i--;
				}
				if(caracteresEliminar > 2){
					parentesisApertura--;
				}
				eliminarEspeciales = false;
			}
	// Si el usuario ingresa una letra que además puede ser el primer caracter o puede precedida por un operador o paréntesis de apertura
        } else if (isalpha(tecla) && elementoAnterior !='.' && (esOperador(elementoAnterior) || elementoAnterior == '('|| i == 0)) {
        // Si la legra es 's', 'c', 't' o 'r'
			if (esEspecial(tecla)){
			    const char* texto = "";
			    switch (tecla) {
			        case 'c':
			            entrada[i++] = 'c';
			            entrada[i++] = 'o';
			            entrada[i++] = 's';
			            texto = "os(";
			            break;
			        case 's':
			            entrada[i++] = 's';
			            entrada[i++] = 'i';
			            entrada[i++] = 'n';
			            texto = "in(";
			            break;
			        case 't':
			            entrada[i++] = 't';
			            entrada[i++] = 'a';
			            entrada[i++] = 'n';
			            texto = "an(";
			            break;
			        case 'r':
			            entrada[i++] = 'r';
			            entrada[i++] = 'a';
			            entrada[i++] = 'i';
			            entrada[i++] = 'z';
			            texto = "aiz(";
			            break;
			    	}
		        entrada[i++] = '(';
			    parentesisApertura++;
			    std::cout << tecla << texto;
		//Si la letra es 'p'
			}else if ((tecla == 'p')){
			    entrada[i++] = tecla;
			    entrada[i++] = 'i';
			    std::cout << tecla << "i";
			}
	//Si el usuario ingresa un paréntesis
        }else if(esParentesis(tecla)){
       	//Paréntesis de apertura: puede ser el primer caracter o puede ser precedido por un operador u otro paréntesis de apertura
        	if (tecla == '(' && elementoAnterior !='.' && (esOperador(elementoAnterior) || elementoAnterior == '(' || i == 0)) {
			    parentesisApertura++;
			    entrada[i++] = tecla;
				std::cout << tecla;
		//Paréntesis de cierre: no puede ser precedido por uno de apertura o un operador pero si por un número, otro paréntesis de cierre o pi
			} else if (tecla == ')' && elementoAnterior !='.' && elementoAnterior != '(' && !esOperador(elementoAnterior) && (isdigit(elementoAnterior) || elementoAnterior == ')'|| elementoAnterior == 'i')) {
			    parentesisCierre++;
				if(parentesisApertura>0 && parentesisCierre <= parentesisApertura){
				    entrada[i++] = tecla;
					std::cout << tecla;
				}else{
					parentesisCierre--;
				}
			}
	//Si el usuario ingresa un número entonces no puede ser precedido por pi pero si por
	//un operador, un paréntesis de apertura u otro número, así también puede ser el primer caracter de la expresión
		} else if (isdigit(tecla) && elementoAnterior!= 'i' && (esOperador(elementoAnterior)||
		                       elementoAnterior == '(' || isdigit(elementoAnterior) || i == 0 || elementoAnterior =='.')){
			int k = 1;
			while(isdigit(entrada[i-k])){
				k++;
			}
			if(k<7){ //Para delimitar la cantidad de números permitidos (6)
				entrada[i++] = tecla;
				std::cout << tecla;
			}

	//Si el usuario ingresa un operador entonces no puede ser precedido por otro operador
	//a excepción del '-' (menos) los operadores no pueden ser precedidos por un punto,  paréntesis de apertura ni ser el primer caracter de la expresión
		} else if(esOperador(tecla) && elementoAnterior !='.' && !esOperador(elementoAnterior) && tecla != '-' && elementoAnterior!='(' && i>0){
			entrada[i++] = tecla;
			std::cout << tecla;
			huboPunto = hayPunto;
			hayPunto = false; //Cuando se ingresa un operador se reinicia el indicador de punto a falso
	//Si el usuario ingresa un signo negativo entonces solo no puede ser precedido por otro operador o un punto
		} else if(tecla == '-' && !esOperador(elementoAnterior) && elementoAnterior !='.'){
			entrada[i++] = tecla;
			std::cout << tecla;
			hayPunto = false; //Cuando se ingresa un operador se reinicia el indicador de punto a falso
	//Si el usuario ingresa un punto, entonces debe estar precedido de almenos un número
		} else if(tecla =='.' && isdigit(elementoAnterior)){
			if(!hayPunto){ //Si el indicador muestra que no se ha añadido un punto en ese conjunto de números
				entrada[i++] = tecla;
				std::cout << tecla;
				hayPunto = true; //Se marca verdadero la presencia del punto
			}

		}
    }
    entrada[i] = '\0';
	return entrada;
}

#endif // VALIDACIONES_H_INCLUDED
