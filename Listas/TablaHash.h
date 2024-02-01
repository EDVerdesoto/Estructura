#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "ListaDoble.h"

class TablaHash
{
    public:
        TablaHash(int);
        void insertar(int);
        void buscar(int);
        void imprimir();
        ~TablaHash();

    protected:

    private:
        int tam;
        ListaDoble<int>** listas_indices;
};

#endif // TABLAHASH_H
