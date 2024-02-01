#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo{
public:
    Nodo* getCabeza();
   Nodo* getNodoSiguiente(void);
   void setNodoSiguiente(Nodo*);
   Nodo* getNodoPrevio(void);
   void setNodoPrevio(Nodo*);
   int getDato(void);
   void setDato(int);
   void setPosicion(int);
   int getPosicion();
   Nodo(int, Nodo*, Nodo*, int);
   ~Nodo();
   void toString();
protected:
private:
   int dato;
   Nodo* nodoSiguiente;
   Nodo* nodoPrevio;
   int posicion;
};


#endif // NODO_H_INCLUDED
