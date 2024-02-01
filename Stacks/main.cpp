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
    Stack<char> operadores;
    int opcion, dato;
    std::string expresion;
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
                reverse_stack(&stack1);
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
                reverse_stack(&stack2);
                stack2.print();
                stack2.remove_all();
                system("pause");
                break;
           case 7:
                std::cout <<"\nIngrese la expresion en notacion infija: "<<std::endl;
                std::string expresion = ingresarExpresion();
                std::string expresion_posfija = polaca_inversa(expresion);
                std::string expresion_prefija = polaca(expresion);
                std::string expresion_impares = polaca_inversa_impares(expresion);
                printf("\nExpresion en notacion infija: %s\n", expresion.c_str());
                printf("Expresion en notacion prefija: %s\n", expresion_prefija.c_str());
                printf("Expresion en notacion postfija: %s\n", expresion_posfija.c_str());
                printf("Calculo con postfija: %.3f\n", calcular(expresion_posfija,"post"));
                printf("Calculo con prefija %.3f\n", calcular(expresion_prefija, "pre"));
                printf("expresion impares: %s\n", expresion_impares.c_str());
                system("pause");
                break;
        }

    }while(opcion!=0);


    system("pause");
    return 0;
}
