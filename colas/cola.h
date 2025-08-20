#ifndef COLA_H
#define COLA_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{

    int dato;
    struct Nodo* next;

} Nodo;

typedef struct Colas{

    Nodo* primero;
    Nodo* ultimo;

} Colas;

Colas* crear_cola();
Nodo* crear_nodo(int info);
void encolar(Colas* cola,int valor);
void desencolar(Colas* cola);
int octe_primaro_cola(Colas* cola);
int despacho(Colas* cola);
bool es_vacia_cola(Colas* cola);
void elim_cola(Colas* cola);

#endif
