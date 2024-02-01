#ifndef LISTA_DOBLE_CIRCULAR_H_INCLUDED
#define LISTA_DOBLE_CIRCULAR_H_INCLUDED
#include "Nodo.h"
#include "Lista_Doble_Circular.h"

class Lista_Doble_Circular{
private:
    Nodo* cabeza;
    Nodo* cola;
    int n_nodos;
public:
    Lista_Doble_Circular();
    void insertar_por_cabeza(int valor);
    void insertar_por_cola(int valor);
    void insertar_entre(int valor, int pos);
    void imprimir_por_cabeza(Lista_Doble_Circular* lista);
    void recorrer(int pos, int n_nodos);
    void recorrer_e_insertar(int pos, int n_nodos, int valor);
    void sumaSig_RestaAnt(Lista_Doble_Circular* lista, Nodo* cabeza, int valorCabeza, int i, int numCiclos);
    void intercambio(Lista_Doble_Circular* lista, Nodo* cabeza, int aux, int posicion);

    Nodo* getCabeza();
};

#endif // LISTA_DOBLE_CIRCULAR_H_INCLUDED
