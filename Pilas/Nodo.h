/***********************************************************************
 * Module:  Nodo.h
 * Author:  Edison Verdesoto
 * Modified: jueves, 19 de diciembre de 2023 7:48:16:PM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/
#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo{
private:
    int valor;
    Nodo* abajo;
public:
    Nodo(int, Nodo*);
    Nodo* getAbajo();
    void setAbajo(Nodo*);
    int getValor(void);
    void setValor(int);
    ~Nodo();
};

#endif // NODO_H_INCLUDED
