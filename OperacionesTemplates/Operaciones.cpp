#include <iostream>
#include "Operaciones.h"
template <typename T>
    void Operaciones <T> :: calculo(){
        std :: cout <<valor1 << "+" << valor2 << "=" << suma() << std::endl;
        std :: cout <<valor1 << "-" << valor2 << "=" << resta() << std::endl;
        std :: cout <<valor1 << "*" << valor2 << "=" << multiplicacion() << std::endl;
        std :: cout <<valor1 << "/" << valor2 << "=" << division() << std::endl;
    }

template <typename T>
    T Operaciones <T> :: suma(){
        return valor1 + valor2;
    }

template <typename T>
    T Operaciones <T> :: resta(){
        return valor1 - valor2;
    }

template <typename T>
    T Operaciones <T> :: multiplicacion(){
        return valor1 * valor2;
    }

template <typename T>
    T Operaciones <T> :: division(){
        return valor1 / valor2;
    }
