#include "Nodo.h"
/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  DARIO BENAVIDES
 * Modified: jueves, 30 de noviembre de 2023 10:00:16:PM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

Nodo* Nodo::getSiguiente(){
    return siguiente;
}

void Nodo::setSiguiente(Nodo* newNodo)
{
   siguiente = newNodo;
}

int Nodo::getValor(void)
{
   return valor;
}

void Nodo::setValor(int newValor)
{
   valor = newValor;
}

Nodo::Nodo(int valor, Nodo* siguiente)
{
	this->valor = valor;
	this->siguiente = siguiente;
}

Nodo::~Nodo()
{
   // TODO : implement
}

