#ifndef ALGORITMO_H_INCLUDED
#define ALGORITMO_H_INCLUDED
#include "Cola.h"

void dejar_pares(Cola* cola, Nodo* aux){
    while(aux!=nullptr){
        aux = cola->extraer_cabeza();
        if(aux->getValor()%2 == 0){
            cola->insertar(aux->getValor());
        }
        aux = aux->getSiguiente();}
}

#endif // ALGORITMO_H_INCLUDED
