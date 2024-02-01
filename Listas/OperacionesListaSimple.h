#ifndef OPERACIONESLISTASIMPLE_H_INCLUDED
#define OPERACIONESLISTASIMPLE_H_INCLUDED

#include "ListaSimple.h"
#include "Nodo.h"

void ingresar_cabezapar_colaimpar(ListaSimple*, int);
void multiplicar_primos_rec(Nodo* aux, int prim_mayor, int i);
int sumar_primos(Nodo*, int, int);
void cifrar_posiciones_pares(Nodo*, int, int);
int cifrar_numero(int numero, int cifra);

void cifrar_posiciones_pares(Nodo* cabeza, int posicion){
    if(cabeza!=nullptr){
        if(posicion%2 == 0){
            cabeza->set_valor(cifrar_numero(cabeza->get_valor(),0));
        }
        cifrar_posiciones_pares(cabeza->get_siguiente(), posicion+1);
    }
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


int sumar_primos(Nodo* cabeza, int sum_inicio, int prim_valid){
    if(cabeza!=nullptr){
        if(cabeza->get_valor() > 1){
            for(prim_valid = cabeza->get_valor()-1; prim_valid>1 ; prim_valid--){
                if(cabeza->get_valor()%prim_valid == 0){
                    break;
                }
            }
            if(prim_valid == 1){
                sum_inicio = sum_inicio + cabeza->get_valor();
            }
        }

        sumar_primos(cabeza->get_siguiente(), sum_inicio, prim_valid);

    }
    else{
        return sum_inicio;
    }
}

void multiplicar_primos_rec(Nodo* aux, int prim_mayor, int i){
    if(aux != nullptr){
        if(prim_mayor>1){
            for(i = prim_mayor-1; i>1; i--){
                if(prim_mayor%i == 0){
                    multiplicar_primos_rec(aux, prim_mayor+1, 0);
                    return;
                }
                else if(i == 2){

                }
            }
            aux->set_valor(aux->get_valor()*prim_mayor);
            multiplicar_primos_rec(aux->get_siguiente(), prim_mayor+1, 0);
        }
        else{
            multiplicar_primos_rec(aux, prim_mayor+1, 0);
        }
    }
}

void ingresar_cabezapar_colaimpar(ListaSimple* lista, int valor){
	Nodo* nodo_ingreso = new Nodo(valor, nullptr);
	Nodo* aux;
	if(lista->get_cabeza()==nullptr){
		lista->set_cabeza(nodo_ingreso);
	}
	else{
		aux = lista->get_cabeza();
		if(valor % 2 == 0){
			lista->set_cabeza(nodo_ingreso);
			lista->get_cabeza()->set_siguiente(aux);
		}
		else{
			while(aux->get_siguiente()!=nullptr){
				aux = aux->get_siguiente();
			}
			aux->set_siguiente(nodo_ingreso);
		}
	}
}


#endif // OPERACIONESLISTASIMPLE_H_INCLUDED
