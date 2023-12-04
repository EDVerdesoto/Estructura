/***********************************************************************
 * Module:  maximos.cpp
 * Author:  VerdesotoDamian
 * Modified: sabado, 25 de noviembre de 2023 18:44:51
 * Purpose: Funcion sobrecargada con Templates
 ***********************************************************************/
#include "maximos.h"
#include <string>

template <typename T>
T numMax(T a, T b) {
	return a > b ? a : b;
}

template <typename T>
T numMax(T a, T b, T c) {
	return numMax(numMax(a, b), c);
}

template <typename T>
T numMax(T a, T b, T c, T d) {
	return numMax(numMax(a, b, c), d);
}

template <typename T>
T longitudMax(T a, T b) {
	return (a.length() > b.length()) ? a : b;
}

template <typename T>
T longitudMax(T a, T b, T c) {
	return longitudMax(longitudMax(a, b), c);
}

template <typename T>
T longitudMax(T a, T b, T c, T d) {
	return longitudMax(longitudMax(a, b, c), d);
}
