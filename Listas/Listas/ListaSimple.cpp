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
    }
    else{
        Nodo* aux = cabeza;
        while(aux->get_siguiente()!=nullptr){
            aux = aux->get_siguiente();
        }
        aux->set_siguiente(nodo_nuevo);
    }
}

void ListaSimple::imprimir(){
    Nodo* aux = cabeza;
    printf("\n");
    while(!(aux==nullptr)){
        printf("%d", aux->get_valor());
        aux = aux->get_siguiente();
        printf("\t");
    }
    printf("\n");
}


void ListaSimple::imprimirPorCola(){
    Nodo* it = cabeza;
    ListaSimple reversa;
    printf("\n");
    while(it!=NULL){
        reversa.insertar_cabeza(it->get_valor());
        it = it->get_siguiente();
    }
    it = reversa.cabeza;
    while(it!=NULL){
        printf("%d", it->get_valor());
        it = it->get_siguiente();
        printf("\t");
    }
    printf("\n");
}

void ListaSimple::buscar(int valor){
    Nodo* aux = cabeza;
    printf("\n");
    int valorP = 0;
    if(cabeza == nullptr){
        printf("no hay elementos en la lista");
    }
    else{
        while(aux != nullptr){
            valorP=aux->get_valor();
            if (valorP==valor){
                printf("Encontrado en %p \n", aux);
                break;
            }
            else{
                if(aux->get_siguiente()==nullptr){
                    printf("no existe el valor\n");
                }
            aux = aux->get_siguiente();
            }
        }
    }
}


void ListaSimple::eliminarPorCabeza(){
    printf("\n");
    if(cabeza == nullptr){
        printf("no hay elementos en la lista");
    }
    else{
        cabeza=cabeza->get_siguiente();
    }
}

void ListaSimple::eliminarPorCola(){
    printf("\n");
    Nodo* aux = cabeza;
    if(cabeza == nullptr){
        printf("no hay elementos en la lista");
    }
    else{
        while(aux->get_siguiente()->get_siguiente()!=nullptr){
            aux = aux->get_siguiente();
            }
        aux->set_siguiente(nullptr);
    }
}

int ListaSimple::sumaDigitosPares(Nodo* nodo) {
    if (nodo == nullptr) {
        printf("No hay elementos en la lista");
        return 0;
    } else {
        while(nodo!=nullptr){
                int num = nodo->get_valor();
            while (num>10){
                if (esPosicionPar) {

                    int suma = 0;
                    while (num > 0) {
                        suma += num % 10;
                        num /= 10;
                    }
                    nodo->set_valor(suma);
                    return suma;
                    nodo->get_siguiente();
                    nodo->get_siguiente();
                } else {
                    return sumaDigitosPares(nodo->get_siguiente());
                }
            }
        }
    }
}

int ListaSimple::sumaDigitosPares() {
    return sumaDigitosPares(cabeza, true);
}

ListaSimple::~ListaSimple()
{
    //dtor
}
