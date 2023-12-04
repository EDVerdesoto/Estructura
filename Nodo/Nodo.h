/***********************************************************************
 * Module:  Nodo.h
 * Author:  ediso
 * Modified: jueves, 30 de noviembre de 2023 23:36:54
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Nodo_Nodo_h)
#define __Nodo_Nodo_h

class Nodo
{
public:
   int getDato(void);
   void setDato(int newDato);
   Nodo getSiguiente(void);
   void setSiguiente(Nodo newSiguiente);
   Nodo();
   ~Nodo();
   void toString(void);

protected:
private:
   int dato;
   Nodo siguiente;


};

#endif