/***************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Edison Verdesoto
 * Fecha de creacion: 16/11/23 22:12
 * Fecha de modificacion:
 * Enunciado:
 * Operacion con fraccion
 *
 ***************************/
#include <iostream>
#include "Fraccion.h"
#include "OperacionLambda.h"

int main(){
    Fraccion obj1 = Fraccion(3,5);
    Fraccion obj2 = Fraccion(4,3);

    Fraccion suma1 = calculo1(obj1, obj2);

    imprimir(suma1);

    Fraccion suma2 = calculo2(obj1, obj2);

    imprimir(suma2);


    system("pause");
    }
    return 0;
