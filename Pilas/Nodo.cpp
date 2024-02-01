/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Edison Verdesoto
 * Modified: jueves, 19 de diciembre de 2023 7:48:16:PM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/
#include "Nodo.h"

Nodo* Nodo::getAbajo(){
    return abajo;
}

void Nodo::setAbajo(Nodo* newNodo)
{
   abajo = newNodo;
}

int Nodo::getValor(void)
{
   return valor;
}

void Nodo::setValor(int newValor)
{
   valor = newValor;
}

Nodo::Nodo(int valor, Nodo* abajo)
{
	this->valor = valor;
	this->abajo = abajo;
}

Nodo::~Nodo()
{
   // TODO : implement
}

