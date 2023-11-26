#include <iostream>
#include "Operaciones.cpp"

int main(...)
{
    int a, b;
    system("cls");
    std :: cout << "Ingrese el valor" << std :: endl;
    std :: cin >>a;
    std :: cin >>b;
    Operaciones <int> IntCalculo(a,b);  	//definir una variable, sin el <> es un tipo de dato abstracto
    IntCalculo.calculo();
    Operaciones <float> floatCalculo(a,b);
    floatCalculo.calculo();
}
