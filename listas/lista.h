#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{

    int dato;
    struct Nodo* next;
    
} Nodo;

typedef struct listas{

    Nodo* cabeza;
    int longui;

}listas;

listas* crear_lista();
Nodo* crear_nodo(int info);
void inset_one(listas* lista,int valor);
void inset_ulti(listas* lista,int valor);
void inset_posi(listas* lista,int valor, int pos);
void spaw_lis(listas* lista,int pos1,int pos2);
listas* voltear_lista(listas* Orlista,listas* Inlista);
void vaciar_one(listas* lista);
void vaciar_ulti(listas* lista);
void vaciar_posi(listas* lista,int pos);
bool es_vacia_lista(listas* lista);
int lon_lista(listas* lista);
int esta_en_lista(listas* lista,int dato);
int oten_ele_lista(listas* lista,int pos);
void impri_lista(listas* lista);
void elimi_lista(listas* lista);

#endif
