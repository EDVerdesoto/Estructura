#include <iostream>
#include "ListasDobles.h"

ListasDobles::ListasDobles(){
    nodoCabeza = nullptr;
    nodoCola = nullptr;
    nNodos = 0;
}

void ListasDobles::insertarPorCabeza(int valor){
    Nodo* nuevoNodo = new Nodo(valor, nullptr, nullptr, 0);
    nNodos++;
    if(nodoCabeza == nullptr){
        nodoCabeza = nuevoNodo;
    }else{
        nuevoNodo->setNodoSiguiente(nodoCabeza);
        nodoCabeza->setNodoPrevio(nuevoNodo);
        nodoCabeza = nuevoNodo;
        Nodo* auxiliar = nodoCabeza->getNodoSiguiente();
        while(auxiliar != nullptr){

            auxiliar->setPosicion(auxiliar->getPosicion()+1);
            auxiliar = auxiliar->getNodoSiguiente();
        }
    }
    nodoCola = nodoCabeza;
    while(nodoCola->getNodoSiguiente() != nullptr){
        nodoCola = nodoCola->getNodoSiguiente();
    }
}

void ListasDobles::insertarPorCola(int valor){
    nNodos++;
    Nodo* nuevoNodo = new Nodo(valor, nullptr, nullptr, nNodos-1);
    if(nodoCola == nullptr){
        nodoCola = nuevoNodo;
        nodoCabeza = nuevoNodo;
    }else{
        nodoCola->setNodoSiguiente(nuevoNodo);
        nuevoNodo->setNodoPrevio(nodoCola);
        nodoCola = nuevoNodo;
    }
}

void ListasDobles::insertarEntre(int valor, int posicion){
    if(nodoCabeza->getNodoSiguiente() != nullptr){
        Nodo* nuevoNodo = new Nodo(valor, nullptr, nullptr, 0);
        nNodos++;
        Nodo* auxiliar = nodoCabeza;
        bool seEncontroPos = false;
        while(auxiliar != nullptr){
            if(auxiliar->getPosicion() == posicion){
                if(auxiliar->getNodoSiguiente() == nullptr){
                    seEncontroPos = true;
                    insertarPorCola(valor);
                    printf("Nodo insertado exitosamente.\n");
                    break;
                }else{
                    seEncontroPos = true;
                    Nodo* auxiliar2 = auxiliar->getNodoSiguiente();
                    auxiliar->setNodoSiguiente(nuevoNodo);
                    nuevoNodo->setNodoPrevio(auxiliar);
                    nuevoNodo->setNodoSiguiente(auxiliar2);
                    nuevoNodo->setPosicion(auxiliar2->getPosicion());
                    auxiliar2->setNodoPrevio(nuevoNodo);
                    while(auxiliar2 != nullptr){
                        auxiliar2->setPosicion(auxiliar2->getPosicion()+1);
                        auxiliar2 = auxiliar2->getNodoSiguiente();
                    }
                    printf("Nodo insertado exitosamente.\n");
                    break;
                }
            }
            auxiliar = auxiliar->getNodoSiguiente();
        }
        if(seEncontroPos == false){
            printf("No se hallo la posicion %d.\n",posicion);
        }
    }else{
        printf("No se puede insertar en medio, dado que solo existe un nodo, o ninguno en la lista.\n");
    }

}

void ListasDobles::imprimirListaPorCabeza(){
    Nodo* aux = nodoCabeza;
	while (aux != nullptr) {
		printf("%d, pos=%d", aux->getDato(), aux->getPosicion());
		aux = aux->getNodoSiguiente();
		printf("\t", 2);
	}
	printf("\n");
}

int cifrar_numero(int numero, int cifra){
    if(numero>=10){
        cifra = cifra + (numero % 10);
        cifrar_numero(numero/10 , cifra);
    }
    else{
        cifra = cifra + numero;
        if(cifra>=10){
            cifra = cifrar_numero(cifra, 0);

        }
        return cifra;
    }
}

void cifrar_posiciones_pares(Nodo* cabeza, int posicion){
    if(cabeza!=nullptr){
        if(posicion%2 == 0){
            cabeza->setDato(cifrar_numero(cabeza->getDato(),0));
        }
        cifrar_posiciones_pares(cabeza->getNodoSiguiente(), posicion+1);
    }
}


void ListasDobles::intercambio( Nodo* cabeza, int valorCabeza, Nodo* cabeza2, int posicion, int aux){
	if (cabeza!=nullptr) {
        ListasDobles* lista;
        if (posicion%2!=0){
            valorCabeza = cabeza->getDato();
            cabeza2 = lista->getNodoCabeza();
            cabeza2->setDato(cabeza->getNodoSiguiente()->getDato());
            cabeza->getNodoSiguiente();
            cabeza2->getNodoSiguiente();
            posicion++;
        }
        else {
            cabeza2->setDato(cabeza->getNodoPrevio()->getDato());

        }
        //intercambio();
	}
}



