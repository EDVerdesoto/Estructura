#include <iostream>
#include "ListaSimple.h"
#include "Nodo.h"

ListaSimple::ListaSimple()
{
    cabeza = nullptr;
}

void ListaSimple::insertar_cabeza(int valor){
    Nodo* nodo_nuevo = new Nodo(valor, nullptr);
    if(cabeza == nullptr){
        cabeza = nodo_nuevo;
    }
    else{
        Nodo* aux = cabeza;
        cabeza = nodo_nuevo;
        cabeza->set_siguiente(aux);
    }
}

void ListaSimple::insertar_cola(int valor){
    Nodo* nodo_nuevo = new Nodo(valor, nullptr);
    if(cabeza == nullptr){
        cabeza = nodo_nuevo;
        return;
    }
    else{
        Nodo* cola = cabeza;
        while(cola!=nullptr){
            cola = cola->get_siguiente();
        }
        cola = nodo_nuevo;
    }
}

void ListaSimple::imprimir(){
    Nodo* aux = cabeza;
    printf("\n");
    while(!(aux==nullptr)){
        printf("%d", aux->get_valor());
        aux = aux->get_siguiente();
        printf("\t", 4);
    }
    printf("\n");
}


void ListaSimple::imprimirPorCola(){
    Nodo* it = cabeza;
    ListaSimple reversa;
    while(it!=NULL){
        reversa.insertar_cabeza(it->get_valor());
        it = it->get_siguiente();
    }
    it = reversa.cabeza;
    while(it!=NULL){
        printf("%d ", it->get_valor());
        it = it->get_siguiente();
    }
}

void ListaSimple::buscar(int valor){
    Nodo* aux = cabeza;
    int valorP = 0;
    if(cabeza == nullptr){
        printf("no hay elementos en la lista");
    }
    else{
        scanf("Ingrese el valor a buscar %d", &valor);
        while(aux != nullptr){
            valorP=aux->get_valor();
            if (valorP==valor){
                printf("Encontrado en %d", &aux);
            }
            else{
                if(aux->get_siguiente()==NULL){
                    printf("No existe el valor");
                }
                aux = aux->get_siguiente();
            }
        }
    }
}

void ListaSimple::eliminarPorCabeza(){
    Nodo* aux = cabeza;
    int valorP = 0;
    if(cabeza == nullptr){
        printf("no hay elementos en la lista");
    }
    else{
        cabeza->get_valor()=NULL;
    }
}

void ListaSimple::eliminarPorCola(){
    Nodo* aux = cabeza;
    int valorP = 0;
    if(cabeza == nullptr){
        printf("no hay elementos en la lista");
    }
    else{

    }
}
ListaSimple::~ListaSimple()
{
    //dtor
}
