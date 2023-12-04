#include <iostream>
#include "Nodo.h"
#include "ListaSimple.h"
#include "../../../../../../validaciones.h"

int main()
{
    int opcion, dato;
    ListaSimple lista;

    do{
        system("cls");
        printf("\n1. Insertar elementos a la lista por cabeza");
        printf("\n2. Insertar elementos a la lista por cola");
        printf("\n3. Imprimir lista por cabeza");
        printf("\n4. Imprimir lista por cola");
        printf("\n5. Buscar en lista");
        printf("\n6. Eliminar por cabeza");
        printf("\n7. Eliminar por cola");
        printf("\n0. Salir");
        opcion = ingresar_enteros("\nIngrese una opcion del menu");
        switch(opcion){
            case 1:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                lista.insertar_cabeza(dato);
                system("pause");
                break;
            case 2:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                lista.insertar_cola(dato);
                system("pause");
                break;
            case 3:
                lista.imprimir();
                system("pause");
                break;
            case 4:
                lista.imprimirPorCola();
                system("pause");
                break;
            case 5:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a buscar");
                printf("\n");
                lista.buscar(dato);
                system("pause");
                break;
            case 6:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a buscar");
                printf("\n");
                lista.buscar(dato);
                system("pause");
                break;
            case 7:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a buscar");
                printf("\n");
                lista.buscar(dato);
                system("pause");
                break;
        }
    }while(opcion != 0);

    system("pause");
    return 0;
}
