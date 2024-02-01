#include "TablaHash.h"
#include "iostream"
#include "ListaDoble.cpp"

TablaHash::TablaHash(int t)
{
    tam = t;
    listas_indices = new ListaDoble<int>*[tam];
    for(int i = 0; i<tam;i++){
        listas_indices[i] = new ListaDoble<int>();
    }
}

void TablaHash::insertar(int dato){
    int pos_hash = dato % tam;

    listas_indices[pos_hash]->insertar_cola(dato);
}

void TablaHash::buscar(int dato){
    int pos_hash = dato % tam;
    printf("Lista %d de la tabla hash ", pos_hash);
    listas_indices[pos_hash]->buscar(dato);
}

void TablaHash::imprimir(){
    for(int i = 0; i<tam; i++){
        printf("%d\t", i);
        listas_indices[i]->imprimir();
        printf("\n");
    }
}

TablaHash::~TablaHash()
{
    //dtor
}
