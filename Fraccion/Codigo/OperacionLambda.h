/***************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Edison Verdesoto
 * Fecha de creacion: 16/11/23 22:10
 * Fecha de modificacion:
 * Enunciado:
 * Operacion con fraccion
 *
 ***************************/

#ifndef OPERACIONLAMBDA_H_INCLUDED
#define OPERACIONLAMBDA_H_INCLUDED

#include <iostream>
#include <functional>
#include "Fraccion.h"


    auto calculo1 = [](Fraccion& obj1, Fraccion& obj2) {

        int suma_num = (obj1.getNumerador() * obj2.getDenominador()) + (obj2.getNumerador() * obj1.getDenominador());
        int suma_den = obj1.getDenominador() * obj2.getDenominador();
        return Fraccion(suma_num, suma_den);
        };


    auto calculo2 = [](Fraccion& obj1, Fraccion& obj2) {
        return std::make_pair((obj1.getNumerador() * obj2.getDenominador()) + (obj2.getNumerador() * obj1.getDenominador()),
                obj1.getDenominador() * obj2.getDenominador());
        };

    auto imprimir = [](const Fraccion& fraccion){
        std::cout << fraccion.getNumerador() << "\n---\n" << fraccion.getDenominador()<< "\n";
    }



#endif // OPERACIONLAMBDA_H_INCLUDED
