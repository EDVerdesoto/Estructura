#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <iostream>
#include "Nodo.h"

class Cola{
private:
    Nodo* cabeza;
    Nodo* cola;
public:
    Cola();
    Nodo* getCabeza();
    void setCabeza(Nodo*);
    Nodo* getCola();
    void setCola(Nodo*);
    void insertar(int valor);
    void eliminar();
    void imprimir();
    bool estaVacia();
    int sumaDeCola();
    Nodo* extraer_cabeza();
    void dejarPares();
    void dejarParesRec(int actSize, int posicion, Nodo* aux);
    int actSize();
    bool validarSize(int pos);
};

#endif // COLA_H_INCLUDED
