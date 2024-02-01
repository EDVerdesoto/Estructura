#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo{
public:
   Nodo* getSiguiente(void);
   void setSiguiente(Nodo*);
   Nodo* getPrevio(void);
   void setPrevio(Nodo*);
   int getDato(void);
   void setDato(int);
   void setPos(int);
   int getPos();
   Nodo(int, Nodo*, Nodo*, int);
   ~Nodo();
   void toString();
protected:
private:
   int dato;
   Nodo* siguiente;
   Nodo* previo;
   int pos;
};


#endif // NODO_H_INCLUDED
