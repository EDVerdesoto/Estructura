#include <iostream>
#include "ListasDobles.h"
#include "validaciones.h"

int main()
{
    int opcion, dato, pos;
    ListasDobles listaDoble;
	do {
		system("cls");
		printf("\n1. Insertar elementos por cabeza a la lista");
		printf("\n2. Insertar elementos por cola a la lista");
		printf("\n3. Insertar elementos entre posiciones a la lista");
		printf("\n4. Imprimir lista por cabeza");
		printf("\n0. Salir");
		opcion = ingresar_enteros("\nIngrese una opcion del menu");
		switch (opcion) {
		case 1:
			dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar:");
			printf("\n");
			listaDoble.insertarPorCabeza(dato);
			system("pause");
			break;
		case 2:
			dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar:");
			printf("\n");
			listaDoble.insertarPorCola(dato);
			system("pause");
			break;
		case 3:
			dato = ingresar_enteros("\nIngresar un entero para insertar:");
			printf("\n");
			pos = ingresar_enteros("\nIngresar la posicion en la que quiere insertar el dato:");
            printf("\n");
			listaDoble.insertarEntre(dato, pos);
			system("pause");
			break;
        case 4:
            printf("\n");
            listaDoble.imprimirListaPorCabeza();
            system("pause");
			break;
		}

	} while (opcion != 0);

	system("pause");
    return 0;
}
