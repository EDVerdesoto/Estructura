/***********************************************************************
 * Module:  main.cpp
 * Author:  Edison Verdesoto
 * Modified: viernes, 19 de diciembre de 2023 15:05:38 a. m.
 * Purpose: main class
 ***********************************************************************/

#include <iostream>
#include "Stack.h"
#include "Stacks_operations.h"
#include "validaciones.h"
#include <string>

int main()
{
    Stack<int> stack1;
    Stack<int> stack2;
    Stack<char> stack3;
    Stack<char> operadores;
    int opcion, dato;
    char tecla;
    Stack<char> expresion;
    Stack<char> post_pre;
    Stack<char> expresion_prefija;
    Stack<char> expresion_posfija;
    do{
        system("cls");
        printf("PILAS");
        printf("\n1. Insertar a la pila");
        printf("\n2. Eliminar de la pila");
        printf("\n3. Imprimir pila");
        printf("\n4. Invertir pila");
        printf("\n5. Torres de Hanoi con pilas");
        printf("\n6. Primos en pila");
        printf("\n7. Polaca Inversa");
        printf("\n8. Signos de la expresion");
        printf("\n0. Salir");

        opcion = ingresar_enteros("\nEscoja una opcion del menu");

        switch(opcion){
            case 1:
                dato = ingresar_enteros("\nIngrese el entero a insertar en la pila");
                stack1.aggregate(dato);
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 2:
                stack1.remove_top();
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 3:
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 4:
                reverse_stack(&stack3);
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 5:
                dato = ingresar_enteros("\nIngrese el numero de discos");
                hanoi_stack(dato);
                system("pause");
                break;
           case 6:
                cantidad_Primos(&stack1, &stack2);
                printf("\n\n");
                reverse_stack(&stack3);
                stack2.print();
                stack2.remove_all();
                system("pause");
                break;
           case 7:
                printf("\nIngrese la expresion en notacion infija: ");
                ingresar_expresion(&expresion, tecla);

                polaca(&expresion, &expresion_prefija);
                polaca_inversa(&expresion, &expresion_prefija);

                std::cout << "\nExpresion en notacion infija\n" << std::endl;
                expresion.print();
                std::cout << "Expresion en notacion prefija:\n" << std::endl;
                expresion_prefija.print();
                std::cout << "Expresion en notacion postfija:\n" << std::endl;
                expresion_posfija.print();

                printf("Calculo con polaca inversa: %.3f\n", calcular(&expresion, &post_pre));
                printf("Calculo posiciones impares \n");
                calc_impares(&expresion);
                printf("\nSignos: %c\n", conteo_menos(&expresion));

                system("pause");
                break;

        }

    }while(opcion!=0);


    system("pause");
    return 0;
}
