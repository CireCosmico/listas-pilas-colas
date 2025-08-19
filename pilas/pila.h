#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{

    int dato;
    struct Nodo* next;

} Nodo;

typedef struct Pila{

    Nodo* tope;

} Pilas;

Pilas* crear_pila();
Nodo* crear_nodo(int info);
void apilar(Pilas* pila,int valor);
void desapilar(Pilas* pila);
bool es_vacia_pila(Pilas* pila);
int octen_tope(Pilas* pila);
void elimi_pila(Pilas* pila);

#endif
