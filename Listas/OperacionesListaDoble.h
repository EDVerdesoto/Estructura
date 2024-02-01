#ifndef OPERACIONESLISTADOBLE_H_INCLUDED
#define OPERACIONESLISTADOBLE_H_INCLUDED

#include "ListaDoble.cpp"
#include "Nodo.cpp"

void invertir_pares_rec(ListaDoble<int>* lista_dest, Nodo<int>* cabeza, int posicion);

void invertir_pares(ListaDoble<int>* lista_dest, Nodo<int>* cabeza){
    lista_dest->set_cabeza(nullptr);
    lista_dest->set_cola(nullptr);
    invertir_pares_rec(lista_dest, cabeza, 0);
}

void invertir_pares_rec(ListaDoble<int>* lista_dest, Nodo<int>* cabeza, int posicion){
    if(cabeza->get_siguiente()!=nullptr){
        if(posicion%2==0){
            lista_dest->insertar_cola(cabeza->get_siguiente()->get_valor());
            lista_dest->insertar_cola(cabeza->get_valor());
        }
        invertir_pares_rec(lista_dest, cabeza->get_siguiente(), posicion+1);
    }
    else if(posicion%2==0){
        lista_dest ->insertar_cola(cabeza->get_valor());
    }
}

void ordenar_impares(ListaDoble<int>* lista){
    Nodo<int>* aux = lista->get_cabeza();
    Nodo<int>* dir_temp;
    int temp;
    while(aux!=nullptr){
        if(aux->get_valor()%2!=0){
            dir_temp = aux;
            while(dir_temp!=nullptr){
                if(dir_temp->get_valor()%2!=0){
                    if(aux->get_valor()>dir_temp->get_valor()){
                        temp = dir_temp->get_valor();
                        dir_temp->set_valor(aux->get_valor());
                        aux->set_valor(temp);
                        if(aux->get_anterior()!=nullptr){
                            aux = aux->get_anterior();
                        }
                    }
                }
                dir_temp = dir_temp->get_siguiente();
            }
        }
        aux = aux->get_siguiente();
    }
}


#endif // OPERACIONESLISTADOBLE_H_INCLUDED
