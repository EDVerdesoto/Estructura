/***********************************************************************
 * Module:  main.cpp
 * Author:  Edison Verdesoto
 * Modified: jueves, 19 de diciembre de 2023 7:48:16:PM
 * Purpose: Main class
 ***********************************************************************/
#include <iostream>
#include "validaciones.h"
#include "Pila.h"

int main()
{
    int opcion, dato;
	Pila pila;
	Pila pila2;
	do {
		system("cls");
		printf("\n1. Insertar elementos a la pila");
		printf("\n2. Eliminar elemento de la pila");
		printf("\n3. Imprimir pila");
		printf("\n4. Sumar todos los elementos");
        printf("\n5. Filtrar pila par");
		printf("\n0. Salir");
		opcion = ingresar_enteros("\nIngrese una opcion del menu");
		switch (opcion) {
		case 1:
			dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar:");
			printf("\n");
			pila.insertar(dato);
			system("pause");
			break;
		case 2:
			printf("\n");
			pila.eliminar();
			system("pause");
			break;
		case 3:
			printf("\n");
			pila.imprimir();
			system("pause");
			break;
        case 4:
            printf("\n");
			pila.imprimir();
            printf("\nCola pares\n");
			pila.dejarPares();
            pila.imprimir();
			system("pause");
			break;
        }
	} while (opcion != 0);

	system("pause");
    return 0;
}
