#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED
#include "Nodo.h"

class ListasDobles{
private:
    Nodo* nodoCabeza;
    Nodo* nodoCola;
    int nNodos;
public:
    ListasDobles();
    void insertarPorCabeza(int valor);
    void insertarPorCola(int valor);
    void insertarEntre(int valor, int posicion);
    void imprimirListaPorCabeza();
    void intercambio(Nodo* cabeza, int valorCabeza, Nodo* cabeza2, int posicion, int aux);
    Nodo* getNodoCabeza();
};

#endif // LISTASDOBLES_H_INCLUDED
