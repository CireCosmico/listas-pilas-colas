#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Pilas* crear_pila(){
    Pilas* pila = (Pilas*)malloc(sizeof(Pilas));
    pila->tope = NULL;
    return pila;

}

Nodo* crear_nodo(int info){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = info;
    nodo->next = NULL;
    return nodo;
}

void apilar(Pilas* pila,int valor){
    Nodo* nodo = crear_nodo(valor);

    nodo->next=pila->tope;
    pila->tope=nodo;

}

void desapilar(Pilas* pila){
    Nodo* aux;

    if(pila->tope != NULL){

        aux=pila->tope;
        pila->tope=pila->tope->next;
        free(aux);

    }
}

bool es_vacia_pila(Pilas* pila){
    bool es;

    if(pila->tope==NULL){

        es=true;

    }else {

        es=false;

    }

    return es;
}

int octen_tope(Pilas* pila){
    int tope = -1;

    if (pila->tope != NULL) {

        tope=pila->tope->dato;

    }

    return tope;

}

void elimi_pila(Pilas* pila){

    while (pila->tope != NULL) {

        desapilar(pila);

    }

    free(pila);

}
