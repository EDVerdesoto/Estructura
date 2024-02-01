/***********************************************************************
 * Module:  OpSobrecarga.h
 * Author:  VerdesotoDamian
 * Modified: domingo, 26 de noviembre de 2023 20:23:42
 * Purpose: Operador sobrecargado con Templates
 ***********************************************************************/
#ifndef OPSOBRECARGA_H_INCLUDED
#define OPSOBRECARGA_H_INCLUDED

#include <cstdio>

template <typename T>
class Complejo {
private:
    T numReal;
    T numImaginario;

public:
    Complejo (T r, T i);
    Complejo operator^(const Complejo& otro) const;
    template <typename U>
    friend void printComplejo(const Complejo<U>& c);
};

#endif // OPSOBRECARGA_H_INCLUDED
