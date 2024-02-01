#ifndef MATEMATICAS_H_INCLUDED
#define MATEMATICAS_H_INCLUDED

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

#endif // MATEMATICAS_H_INCLUDED
