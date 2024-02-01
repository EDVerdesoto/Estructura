#include <iostream>
#include "validaciones.h"
#include "Cola.h"

int main()
{
    int opcion, dato;
	Cola cola;
	do {
		system("cls");
		printf("\n1. Insertar elementos a la cola");
		printf("\n2. Eliminar elemento de la cola");
		printf("\n3. Imprimir cola");
		printf("\n4. Dejar Pares");
		printf("\n5. Sumar posiciones");
		printf("\n0. Salir");
		opcion = ingresar_enteros("\nIngrese una opcion del menu");
		switch (opcion) {
		case 1:
			dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar:");
			printf("\n");
			cola.insertar(dato);
			system("pause");
			break;
		case 2:
			printf("\n");
			cola.eliminar();
			system("pause");
			break;
		case 3:
			printf("\n");
			cola.imprimir();
			system("pause");
			break;
		case 4:
			printf("\n");
			cola.dejar_pares(cola.getCabeza());
			system("pause");
			break;
        case 5:
            printf("\n");
			cola.sumarPosicionesRec(cola.getCabeza(), 0, 0);
			system("pause");
			break;
		}
	} while (opcion != 0);

	system("pause");
    return 0;
}
