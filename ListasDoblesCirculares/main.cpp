#include <iostream>
#include "Lista_Doble_Circular.h"
#include "validaciones.h"
int main()
{
    int opcion, dato, pos;
	Lista_Doble_Circular lista;
	do {
		system("cls");
		printf("\n1. Insertar elementos por cabeza a la lista");
		printf("\n2. Insertar elementos por cola a la lista");
		printf("\n3. Insertar elementos entre la lista");
		printf("\n4. Imprimir elementos por cabeza de la lista");
		printf("\n5. Algoritmo Joan");
		printf("\n0. Salir");
		opcion = ingresar_enteros("\nIngrese una opcion del menu");
		switch (opcion) {
		case 1:
			dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar:");
			printf("\n");
			lista.insertar_por_cabeza(dato);
			system("pause");
			break;
		case 2:
			dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar:");
			printf("\n");
			lista.insertar_por_cola(dato);
			system("pause");
			break;
		case 3:
			dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar:");
			printf("\n");
			pos = ingresar_enteros("\nIngresar un entero como posicion en la que se insertara el dato:");
			printf("\n");
			lista.insertar_entre(dato, pos);
			system("pause");
			break;
		case 4:
			printf("\n");
			lista.imprimir_por_cabeza(&lista);
			system("pause");
			break;
        case 5:
			printf("\n");
			lista.sumaSig_RestaAnt(&lista, lista.getCabeza(), lista.getCabeza()->getDato(), 0, 1);
			system("pause");
			break;
		}
	} while (opcion != 0);
	system("pause");
	return 0;
}
