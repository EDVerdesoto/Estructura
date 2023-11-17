/***************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Joan Cobeña, Ruben Benavides, Edison Verdesoto
 * Fecha de creacion: 15/11/23 12:10
 * Fecha de modificacion:
 * Enunciado:
 * Operacion con fraccion
 *
 ***************************/

#ifndef OPERACIONESFRACCION_H_INCLUDED
#define OPERACIONESFRACCION_H_INCLUDED

#include <iostream>
#include "Fraccion.h"

Fraccion calculo(Fraccion& obj1, Fraccion& obj2);
bool sonHomogeneas(Fraccion& obj1, Fraccion& obj2);


Fraccion calculo(Fraccion& obj1, Fraccion& obj2){
    int sum_num = (obj1.getNumerador()*obj2.getDenominador()) + (obj2.getNumerador()*obj1.getDenominador());
    int sum_den = obj1.getDenominador() * obj2.getDenominador();

    return Fraccion(sum_num, sum_den);
}



#endif // OPERACIONESFRACCION_H_INCLUDED
