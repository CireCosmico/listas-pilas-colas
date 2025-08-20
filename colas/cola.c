#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Colas* crear_cola(){

    Colas* cola = (Colas*)malloc(sizeof(Colas));
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;

}

Nodo* crear_nodo(int info){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = info;
    nodo->next = NULL;
    return nodo;
}

void encolar(Colas* cola,int valor){
    Nodo* nodo =crear_nodo(valor);

    if(cola->primero == NULL){

        cola->primero = nodo;
        cola->ultimo = nodo;

    }else {

        cola->ultimo->next=nodo;
        cola->ultimo = nodo;

    }

}

void desencolar(Colas* cola){
    Nodo* aux;

    if (!es_vacia_cola(cola)) {

        if (cola->primero == cola->ultimo) {

            free(cola->primero);
            cola->primero = NULL;
            cola->ultimo = NULL;

        }else {

            aux = cola->primero;
            cola->primero = cola->primero->next;
            free(aux);

        }
    }
}

int octe_primaro_cola(Colas* cola){
    int pri = -1;

    if(cola->primero != NULL){

        pri=cola->primero->dato;

    }

    return pri;
}

int despacho(Colas* cola){
    int pri = -1;

    if(!es_vacia_cola(cola)){

        pri = octe_primaro_cola(cola);
        desencolar(cola);

    }

    return pri;
}

bool es_vacia_cola(Colas* cola){
    bool es= false;

    if(cola->primero == NULL){

        es = true;

    }

    return es;
}

void elim_cola(Colas* cola){

    while (cola->primero != NULL) {

        desencolar(cola);

    }

    free(cola);

}
