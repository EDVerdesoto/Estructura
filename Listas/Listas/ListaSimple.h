#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"

class ListaSimple
{
    public:
        void insertar_cabeza(int);
        void insertar_cola(int);
        void imprimir();
        void imprimirPorCola();
        void buscar(int);
        void eliminarPorCola();
        void eliminarPorCabeza();
        ListaSimple();
        ~ListaSimple();
    protected:

    private:
        Nodo* cabeza;
};

#endif // LISTASIMPLE_H
