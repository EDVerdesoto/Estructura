/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  VerdesotoDamian
 * Modified: martes, 14 de noviembre de 2023 18:44:51
 * Purpose: Implementation of the class Fraccion
 ***********************************************************************/

#include "Fraccion.h"

/**
 * @brief Getter del numerador de la fraccioon
 * @return El valor del numerador
 */

int Fraccion::getNumerador(void)
{
   return numerador;
}

/**
 * @brief Setter del numerador de la fraccion
 * @param newNumerador El nuevo valor para el numerador
 * @return void
 */

void Fraccion::setNumerador(int newNumerador)
{
   numerador = newNumerador;
}

/**
 * @brief Getter del denominador de la fraccion
 * @return El valor del denominador
 */

int Fraccion::getDenominador(void)
{
   return denominador;
}

/**
 * @brief Setter del denominador de la fraccion
 * @param newDenominador El nuevo valor para el denominador
 * @return void
 */

void Fraccion::setDenominador(int newDenominador)
{
   denominador = newDenominador;
}

/**
 * @brief Constructor de la clase Fraccion
 * @param num Valor inicial para el numerador
 * @param den Valor inicial para el denominador
 * @return void
 */

Fraccion::Fraccion(int num, int den)
{
   // TODO : implement
}

/**
 * @brief Destructor de la clase Fraccion
 * @return void
 */

Fraccion::~Fraccion()
{
   // TODO : implement
}