#include <iostream>
#include "validaciones.h"
#include "Cola.h"

int main()
{
    int opcion, dato;
	Cola cola;
	Cola cola2;
	do {
		system("cls");
		printf("\n1. Insertar elementos a la cola");
		printf("\n2. Eliminar elemento de la cola");
		printf("\n3. Imprimir cola");
		printf("\n4. Sumar todos los elementos");
        printf("\n5. Filtrar cola par");
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
			cola.imprimir();
            printf("\n");
			printf("%d",cola.sumaDeCola());
            printf("\n");
			system("pause");
			break;
        case 5:
            printf("\n");
			cola.imprimir();
            printf("\nCola pares\n");
			cola.dejarPares();
            cola.imprimir();
			system("pause");
			break;
        }
	} while (opcion != 0);

	system("pause");
    return 0;
}
