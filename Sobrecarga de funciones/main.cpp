/***********************************************************************
 * Module:  main.cpp
 * Author:  VerdesotoDamian
 * Modified: sabado, 25 de noviembre de 2023 18:44:51
 * Purpose: Funcion sobrecargada con Templates
 ***********************************************************************/
#include <iostream>
#include <string>
#include "maximos.h"
#include "maximos.cpp"

int main()
{
    int numMaxInt = numMax(125, 126);
	float numMaxFloat = numMax(12.5f, 12.4f, 13.5f);
	double numMaxDouble = numMax(8.5, 4.2, 1.8, 7.4);
	std::string longitudMax2 = longitudMax(std::string("Hola"), std::string("Mundo"));
	std::string longitudMax3 = longitudMax(std::string("Hola"), std::string("Mundo"), std::string("Programacion"));
	std::string longitudMax4 = longitudMax(std::string("Hola"), std::string("Mundo"), std::string("Programacion"),
								std::string("Parangaricutirimicuaro"));

	printf("Entero Maximo: %d\n", numMaxInt);
	printf("Flotante Maximo: %.1f\n", numMaxFloat);
	printf("Doble Maximo: %.1f\n", numMaxDouble);
	printf("Palabra con longitud maxima entre 2: %s\n", longitudMax2.c_str());
	printf("Palabra con longitud maxima entre 3: %s\n", longitudMax3.c_str());
	printf("Palabra con longitud maxima entre 4: %s\n", longitudMax4.c_str());

	system("pause");

	return 0;
    return 0;
}
