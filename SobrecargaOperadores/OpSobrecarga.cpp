/***********************************************************************
 * Module:  OpSobrecarga.cpp
 * Author:  VerdesotoDamian
 * Modified: domingo, 26 de noviembre de 2023 20:23:42
 * Purpose: Operador sobrecargado con Templates
 ***********************************************************************/
#include "OpSobrecarga.h"

template <typename T>
Complejo<T>::Complejo(T r, T i) : numReal(r), numImaginario(i){}

template <typename T>
Complejo<T> Complejo<T>::operator^(const Complejo<T>& otro) const{
    return Complejo<T>(numReal + otro.numReal, numImaginario + otro.numImaginario);
}

template <typename U>
void printComplejo(const Complejo<U>& c){
    printf("(%.1f, %.1fi)\n", static_cast<double>(c.numReal),
           static_cast<double>(c.numImaginario));
}

template class Complejo<double>;
template void printComplejo<double>(const Complejo<double>& c);
