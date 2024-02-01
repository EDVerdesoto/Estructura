#include "Cola.h"

Cola::Cola(){
    cabeza = nullptr;
    cola = nullptr;
}

Nodo* Cola::getCabeza(){
    return cabeza;
}

void Cola::setCabeza(Nodo* cabeza){
    this->cabeza = cabeza;
}

Nodo* Cola::getCola(){
    return cola;
}

void Cola::setCola(Nodo* cola){
    this->cola = cola;
}

void Cola::insertar(int valor){
    Nodo* nuevo_nodo = new Nodo(valor, nullptr);
    if(cabeza == nullptr){
        cabeza = nuevo_nodo;
        cola = nuevo_nodo;
    }else{
        cola->setSiguiente(nuevo_nodo);
        cola = nuevo_nodo;
    }
}

void Cola::eliminar(){
    if(estaVacia()){
        printf("No existen nodos en la cola.\n");
    }else{
        Nodo* aux = cabeza->getSiguiente();
        cabeza->setSiguiente(nullptr);
        delete cabeza;
        cabeza = aux;
    }
}

void Cola::imprimir(){
    if(estaVacia()){
        printf("No existen nodos en la cola.\n");
    }else{
        Nodo* aux = cabeza;
        while(aux != nullptr){
            printf("%d", aux->getValor());
            printf("\t", 3);
            aux = aux->getSiguiente();
        }
    }
}

bool Cola::estaVacia(){
    if(cabeza == nullptr){
        return 1;
    }else{
        return 0;
    }
}

Nodo* Cola::extraer_cabeza(){
    Nodo* aux = cabeza;
    cabeza = cabeza->getSiguiente();
    return aux;
}

void Cola::dejar_pares(Nodo* aux){
    while(aux!=nullptr){
        aux = extraer_cabeza();
        if(aux->getValor()%2 == 0){
            insertar(aux->getValor());
        }
        aux = aux->getSiguiente();
    }
}

void Cola::sumarPosicionesRec(Nodo* aux, int posicion, int suma){
    if(estaVacia()){
        printf("la cola esta vacia");
    }
    else{
        while(aux!=nullptr){
            if (posicion%2==0){
                suma = suma + aux->getValor();
                aux->setValor(suma);
                aux->getSiguiente();
                sumarPosicionesRec(aux, posicion+1, suma);
            }
        }
    }
}

