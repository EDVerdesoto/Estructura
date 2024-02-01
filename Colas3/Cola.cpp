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
    if(aux!=nullptr){
        cabeza = cabeza->getSiguiente();
        aux->setSiguiente(nullptr);
    }
    return aux;
}

int Cola::sumaDeCola(){
    int resultado = 0;
    if(estaVacia()){
        printf("No existen nodos en la cola.\n");
    }else{
        int pos = 0;
        int tamano = actSize();
        Nodo* aux;
        while(pos<tamano){
            aux = extraer_cabeza();
            resultado = resultado + aux->getValor();
            insertar(aux->getValor());
            pos++;
        }
    }
    return resultado;
}

int Cola::actSize(){
    Nodo* aux = cabeza;
    int tamano = 0;
    while(aux!=nullptr){
        aux = aux->getSiguiente();
        tamano++;
    }
    return tamano;
}

void Cola::dejarPares(){
    if(!estaVacia())
        dejarParesRec(actSize(), 0, nullptr);
}

void Cola::dejarParesRec(int act_Size, int posicion, Nodo* aux){
    if(posicion<act_Size){
        aux = extraer_cabeza();
        if (aux->getValor()%2==0){
            insertar(aux->getValor());
        }
        dejarParesRec(act_Size, posicion+1, aux);
    }
}

