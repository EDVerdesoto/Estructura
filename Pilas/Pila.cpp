/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Edison Verdesoto
 * Modified: jueves, 19 de diciembre de 2023 7:48:16:PM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/
#include "Pila.h"

Pila::Pila(){
    cabeza = nullptr;
}

Nodo* Pila::getCabeza(){
    return cabeza;
}

void Pila::setCabeza(Nodo* cabeza){
    this->cabeza = cabeza;
}

void Pila::insertar(int valor){
    Nodo* nuevo_nodo = new Nodo(valor, nullptr);
    if(cabeza == nullptr){
        cabeza = nuevo_nodo;
    }else{
        cabeza->setAbajo(cabeza);
        cabeza = nuevo_nodo;
    }
}

void Pila::eliminar(){
    if(estaVacia()){
        printf("No existen nodos en la pila.\n");
    }else{
        Nodo* aux = cabeza;
        cabeza = cabeza->getAbajo();
        delete aux;
    }
}

void Pila::imprimir(){
    if(estaVacia()){
        printf("No existen nodos en la pila.\n");
    }else{
        Nodo* aux = cabeza;
        while(aux != nullptr){
            printf("%d", aux->getValor());
            printf("\t", 3);
            aux = aux->getAbajo();
        }
    }
}

bool Pila::estaVacia(){
    if(cabeza == nullptr){
        return 1;
    }else{
        return 0;
    }
}

Nodo* Pila::extraer_cabeza(){
    Nodo* aux = cabeza;
    if(aux!=nullptr){
        cabeza = cabeza->getAbajo();
        aux->setAbajo(nullptr);
    }
    return aux;
}

int Pila::actSize(){
    Nodo* aux = cabeza;
    int tamano = 0;
    while(aux!=nullptr){
        aux = aux->getAbajo();
        tamano++;
    }
    return tamano;
}

void Pila::dejarPares(){
    if(!estaVacia())
        dejarParesRec(actSize(), 0, nullptr);
}

void Pila::dejarParesRec(int act_Size, int posicion, Nodo* aux){
    if(posicion<act_Size){
        aux = extraer_cabeza();
        if (aux->getValor()%2==0){
            insertar(aux->getValor());
        }
        dejarParesRec(act_Size, posicion+1, aux);
    }
}

void Pila::invertir(){
    if(!estaVacia())
        invertirRec(actSize(), 0 , nullptr);
}

void Pila::invertirRec(int act_Size, int posicion, Nodo* aux){
    Pila* pilaAux;
    if(posicion < act_Size) {
        aux = extraer_cabeza();
        pilaAux->insertar(aux);
    }
    invertirRec(act_Size, posicion+1, aux);
}

void hanoi_pila_rec(int i, Pila* pila_orig, Pila* pila_aux, Pila* pila_dest){
    if (i > 0) {
        hanoi_pila_rec(i - 1, pila_orig, pila_dest, pila_aux);
        pila_dest->aggregate_node(pila_orig->take_off());
        hanoi_pila_rec(i - 1, pila_aux, pila_orig, pila_dest);
    }
}







