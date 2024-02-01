/***********************************************************************
 * Module:  main.cpp
 * Author:  VerdesotoDamian
 * Modified: domingo, 26 de noviembre de 2023 20:23:42
 * Purpose: Operador sobrecargado con Templates
 ***********************************************************************/
#include <cstdio>
#include <cstdlib>
#include "OpSobrecarga.h"
#include "OpSobrecarga.cpp"

int main() {
    Complejo<double> a(1.0, 2.0);
    Complejo<double> b(3.0, 4.0);
    Complejo<double> resultado = a ^ b;

    printf("Resultado: ");
    printComplejo(resultado);

    system("pause");
    return 0;
}
