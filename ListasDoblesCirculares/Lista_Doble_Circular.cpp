#include <iostream>
#include "Lista_Doble_Circular.h"

Lista_Doble_Circular::Lista_Doble_Circular(){
    cabeza = nullptr;
    cola = nullptr;
    n_nodos = 0;
}

Nodo* Lista_Doble_Circular::getCabeza(){
    return cabeza;
}

void Lista_Doble_Circular::recorrer(int pos, int n_nodos){
    Nodo* auxiliar1 = cabeza;
    bool fue_encontrado = false;
    int contador1 = 0;
    while(contador1 != n_nodos){
        if((auxiliar1->getPos()) == pos){
            fue_encontrado = true;
            Nodo* auxiliar2 = auxiliar1->getSiguiente();
            int contador2 = contador1 + 1;
            while(contador2 != n_nodos){
                auxiliar2 ->setPos(auxiliar2->getPos()+1);
                auxiliar2 = auxiliar2->getSiguiente();
                contador2++;
            }
            break;
        }
        auxiliar1 = auxiliar1->getSiguiente();
        contador1++;
    }
    if(fue_encontrado == false){
        printf("No se encontro un nodo con la posicion %d\n", pos);
    }
}

void Lista_Doble_Circular::recorrer_e_insertar(int pos, int n_nodos, int valor){
    Nodo* auxiliar1 = cabeza;
    int contador1 = 0;
    while(contador1 < n_nodos){
        if((auxiliar1->getPos()) == pos){
            Nodo* auxiliar2 = auxiliar1->getSiguiente();
            Nodo* nuevo_nodo = new Nodo(valor, nullptr, nullptr, auxiliar1->getPos());
            int contador2 = contador1 + 1;

            auxiliar1->setSiguiente(nuevo_nodo);
            nuevo_nodo->setPrevio(auxiliar1);
            auxiliar2->setPrevio(nuevo_nodo);
            nuevo_nodo->setSiguiente(auxiliar2);

            auxiliar2 = nuevo_nodo;

            while(contador2 != n_nodos){
                auxiliar2->setPos((auxiliar2->getPos())+1);
                auxiliar2 = auxiliar2 ->getSiguiente();
                contador2++;
            }

            printf("Nodo insertado exitosamente.\n");
            break;
        }
        auxiliar1 = auxiliar1->getSiguiente();
        contador1++;
    }
}

void Lista_Doble_Circular::insertar_por_cabeza(int valor){
    Nodo* nuevo_nodo = new Nodo(valor, nullptr, nullptr, 0);
    n_nodos++;
    if(cabeza == nullptr){
        cabeza = nuevo_nodo;
        cola = nuevo_nodo;
    }else{
        nuevo_nodo->setSiguiente(cabeza);
        cabeza->setPrevio(nuevo_nodo);
        cabeza=nuevo_nodo;
        cabeza->setPrevio(cola);
        cola->setSiguiente(cabeza);
        recorrer(0,n_nodos);
    }
    printf("Nodo insertado exitosamente.\n");
}

void Lista_Doble_Circular::insertar_por_cola(int valor){
    Nodo* nuevo_nodo = new Nodo(valor, nullptr, nullptr, n_nodos);
    if(cabeza == nullptr){
        cabeza = nuevo_nodo;
        cola = nuevo_nodo;
    }else{
        nuevo_nodo->setPrevio(cola);
        cola->setSiguiente(nuevo_nodo);
        cola=nuevo_nodo;
        cabeza->setPrevio(cola);
        cola->setSiguiente(cabeza);
    }
    n_nodos++;
    printf("Nodo insertado exitosamente.\n");
}

void Lista_Doble_Circular::insertar_entre(int valor, int pos){
    if(n_nodos == 0){
        printf("La lista esta vacia.\n");
    }else if(n_nodos == 1){
        printf("Para insertar entre posiciones debe al menos haber 2 nodos.\n");
    }else{
        if(pos == (n_nodos - 1)){
            insertar_por_cola(valor);
        }else if(pos < n_nodos){
            n_nodos++;
            recorrer_e_insertar(pos, n_nodos, valor);
        }else{
            printf("No se encontro un nodo con la posicion %d\n", pos);
        }
    }
}

void Lista_Doble_Circular::imprimir_por_cabeza(Lista_Doble_Circular* lista){
    int contador = 0;
    Nodo* aux = lista->getCabeza();
    while(contador != n_nodos){
        printf("%d, pos=%d", aux->getDato(), aux->getPos());
        printf("\t", 4);
        aux = aux->getSiguiente();
        contador++;
    }
}

void Lista_Doble_Circular::sumaSig_RestaAnt(Lista_Doble_Circular* lista, Nodo* cabeza, int valorCabeza, int i, int numCiclos){
	if(cabeza==nullptr){
		printf("lista vacia");
	}
	else if (i/2!=numCiclos){ //i=0 va en el main 2
		if (cabeza == lista->getCabeza()){
			valorCabeza = cabeza->getDato();
		}
		if(i%2==0){
			if(cabeza->getSiguiente() == lista->getCabeza()){
				cabeza->setDato(cabeza->getDato() + valorCabeza);
				i++;
                imprimir_por_cabeza(lista);
			}else{
                cabeza->setDato(cabeza->getSiguiente()->getDato() + cabeza->getDato());
			}
			sumaSig_RestaAnt(lista, cabeza->getSiguiente(), valorCabeza, i, numCiclos);
		}
		else{
			if(cabeza->getPrevio() == lista->getCabeza()){
				cabeza->setDato(cabeza->getDato() - valorCabeza);
				i++;
				imprimir_por_cabeza(lista);
			}else{
                cabeza->setDato(cabeza->getDato() - cabeza->getPrevio()->getDato());
			}
			sumaSig_RestaAnt(lista, cabeza->getPrevio(), valorCabeza, i, numCiclos);
		}
	}
}
