#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <iostream>
#include "Nodo.h"

class Pila{
private:
    Nodo* cabeza;
public:
    Pila();
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
    void invertirRec(int act_Size, int posicion, Nodo* aux);
    void invertir();
};

#endif // PILA_H_INCLUDED
