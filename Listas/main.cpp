#include <iostream>
#include "Nodo.h"
#include "menus.h"
#include "../validaciones.h"
#include "OperacionesListaDoble.h"
#include "TablaHash.h"

int main()
{
    int opcion, dato, seguir;
    ListaDoble<int> lista;
    ListaDoble<int> listainv;
    TablaHash tablaHash(14);
    do{
        system("cls");
        opcion = desplegar_menu_principal();
        switch(opcion){
            case 1:
                system("cls");
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                lista.insertar_cola(dato);
                printf("\n");
                lista.imprimir();
                system("pause");
                break;
            case 2:
                system("cls");
                lista.imprimir();
                printf("\n");
                system("pause");
                break;
            case 3:
                system("cls");
                dato = ingresar_enteros("\nIngresar entero a eliminar");
                lista.eliminar(dato);
                printf("\n");
                system("pause");
                break;
            case 4:
                system("cls");
                dato = ingresar_enteros("\nIngresar el dato despues del cual se va a insertar el nuevo nodo");
                lista.insertar_entre(dato, ingresar_enteros("\nIngresar el dato a insertar"));
                printf("\n");
                system("pause");
                break;
            case 5:
                system("cls");
                invertir_pares(&listainv, lista.get_cabeza());
                listainv.imprimir();
                printf("\n");
                system("pause");
                break;
            case 6:
                system("cls");
                listainv.imprimir();
                printf("\n");
                system("pause");
                break;
            case 7:
                system("cls");
                printf("\nLista antes de ordenar\n");
                lista.imprimir();
                ordenar_impares(&lista);
                printf("\nLista despues de ordenar\n");
                lista.imprimir();
                system("pause");
                break;
            case 8:
                system("cls");
                dato = ingresar_enteros("\nIngresar un entero al hash");
                tablaHash.insertar(dato);
                printf("\n");
                tablaHash.imprimir();
                system("pause");
                break;
            case 9:
                system("cls");
                printf("\nOrdenando la lista con Bubble Sort...\n");
                lista.orden_burbuja();
                printf("\nLista ordenada con Bubble Sort:\n");
                lista.imprimir();
                printf("\n");
                system("pause");
                break;
        }
    }while(opcion != 9);

    return 0;
}
