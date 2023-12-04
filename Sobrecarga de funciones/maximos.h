/***********************************************************************
 * Module:  maximos.h
 * Author:  VerdesotoDamian
 * Modified: sabado, 25 de noviembre de 2023 18:44:51
 * Purpose: Funcion sobrecargada con Templates
 ***********************************************************************/
#ifndef MAXIMOS_H_INCLUDED
#define MAXIMOS_H_INCLUDED

#include <string>
template <typename T>
T numMax(T a, T b);

template <typename T>
T numMax(T a, T b, T c);

template <typename T>
T numMax(T a, T b, T c, T d);

template <typename T>
T longitudMax(T a, T b);

template <typename T>
T longitudMax(T a, T b, T c);

template <typename T>
T longitudMax(T a, T b, T c, T d);

#endif // MAXIMOS_H_INCLUDED
