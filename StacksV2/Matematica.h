/***********************************************************************
 * Module:  Matematica.h
 * Author:  Edison Verdesoto, Joan Cobeña
 * Modified: 19 de enero de 2024
 * Purpose: Declaration of the class Matematica
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Matematica_h)
#define __Class_Diagram_1_Matematica_h

class Matematica
{
public:
	int redondear(double numero);
	bool isNaN(double valor);
    double abs(double valor);
    double normalizaRadian(double radian);
    double sin(double operando);
    double cos(double operando);
    double tan(double operando);
    double log(double operando);
    double pow(double base, double exponente);
    double sqrt(int operando);
    double getPI();
    double getEPSILON();
    Matematica();
    ~Matematica();

private:
    double EPSILON;
    double PI;
};

#endif
