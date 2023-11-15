/***********************************************************************
 * Module:  Fraccion.h
 * Author:  VerdesotoDamian
 * Modified: martes, 14 de noviembre de 2023 18:44:51
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(__Fraccion_Modelo_Fraccion_h)
#define __Fraccion_Modelo_Fraccion_h

class Fraccion
{
public:
   int getNumerador(void);
   void setNumerador(int newNumerador);
   int getDenominador(void);
   void setDenominador(int newDenominador);
   Fraccion(int num, int den);
   ~Fraccion();

protected:
private:
   int numerador;
   int denominador;


};

#endif