#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


listas* crear_lista(){
    listas* lista = (listas*)malloc(sizeof(Nodo));
    lista->cabeza = NULL;
    lista->final = NULL;
    lista->longui = 0;
    return lista;
}

Nodo* crear_nodo(int info){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = info;
    nodo->next = NULL;
    return nodo;
}

void inset_one(listas* lista,int valor){

    Nodo* nodo = crear_nodo(valor);

    if(lista->cabeza==NULL){

        nodo->next=lista->cabeza;
        lista->final=nodo;
        lista->cabeza = nodo;
        lista->longui++;

    }else{

        nodo->next=lista->cabeza;
        lista->cabeza = nodo;
        lista->longui++;

    }



}

void inset_ulti(listas* lista,int valor){
    Nodo* nodo = crear_nodo(valor);

    if (lista->cabeza==NULL) {

        nodo->next=lista->cabeza;
        lista->final = nodo;
        lista->cabeza = nodo;
        lista->longui++;

    }else {

        lista->final->next=nodo;
        lista->final=lista->final->next;
        lista->longui++;

    }

}

void inset_posi(listas* lista,int valor, int pos){

    if(pos<=lista->longui+1 && pos>0){

        if(pos==1){
            inset_one(lista,valor );
        }else if(pos == lista->longui+1){
            inset_ulti(lista,valor );
        }else {
            Nodo* nodo = crear_nodo(valor);
            Nodo* aux;
            int i;

            aux=lista->cabeza;

            for(i=1;i<pos-1;i++){

                aux=aux->next;

            }

            nodo->next=aux->next;
            aux->next=nodo;
            lista->longui++;

        }
    }else if(lista->cabeza==NULL && pos>0){

        inset_one(lista,valor );

    }
}

void spaw_lis(listas* lista,int pos1,int pos2){
    int A,B,i;
    Nodo* aux;

    A=oten_ele_lista(lista,pos1 );
    B=oten_ele_lista(lista,pos2 );

    aux=lista->cabeza;

    for(i=1;i<pos1;i++){
        aux=aux->next;
    }

    aux->dato=B;
    aux=lista->cabeza;

    for(i=1;i<pos2;i++){
        aux=aux->next;
    }

    aux->dato=A;

}

listas* voltear_lista(listas* Orlista,listas* Inlista){
    Nodo* aux;
    aux=Orlista->cabeza;

    while (aux!=NULL) {

        inset_one(Inlista,aux->dato );
        aux=aux->next;

    }

    return Inlista;

}

void vaciar_one(listas* lista){
    Nodo* aux;

    if(lista->cabeza != NULL){

        aux=lista->cabeza;
        lista->cabeza=lista->cabeza->next;
        lista->longui--;
        free(aux);

    }
}

void vaciar_ulti(listas* lista){
    Nodo* aux;

    if(lista->cabeza->next==NULL){

        free(lista->cabeza);
        lista->cabeza = NULL;

    }else {
        aux=lista->cabeza;
        while (aux->next->next != NULL) {

            aux=aux->next;

        }

        free(aux->next);
        aux->next=NULL;
        lista->final=aux;

    }


}

void vaciar_posi(listas* lista,int pos){

    if(pos<=lista->longui && pos>0){

        if(pos==1){
            vaciar_one(lista);
        }else if(pos==lista->longui){
            vaciar_ulti(lista);
        }else {
            Nodo* aux,*aux2;
            int i;
            aux=lista->cabeza;

            for(i=1;i<pos-1;i++){

                aux=aux->next;

            }

            aux2=aux->next;
            aux->next=aux2->next;
            free(aux2);
            lista->longui--;

        }


    }

}

bool es_vacia(listas* lista){
    bool es;
    if(lista->cabeza==NULL){

        es=true;

    }else {

        es=false;

    }

    return es;
}

int lon_lista(listas* lista){
    int lon;

    lon=lista->longui;

    return lon;
}

int esta_en_lista(listas* lista,int dato){
    int esta = -1,cont = 0;
    Nodo* aux;

    aux=lista->cabeza;

    while (aux!=NULL) {

        cont++;
        if(dato==aux->dato){

            esta=cont;
            aux=NULL;

        }else {

            aux=aux->next;

        }

    }
    return esta;
}

int oten_ele_lista(listas* lista,int pos){
    int dato = -1,i;
    Nodo* aux;

    aux=lista->cabeza;

        if(pos<=lista->longui && pos>0){

            for(i=1;i<pos;i++){

                aux=aux->next;

            }

            dato=aux->dato;

        }

    return dato;
}


void impri_lista(listas* lista){
    Nodo* aux;
    int cont=1;

    aux=lista->cabeza;

    while (aux!=NULL) {

        printf("posicion %d tiene el valor: %d\n",cont,aux->dato);
        cont++;
        aux=aux->next;

    }
    free(aux);
}

void elimi_lista(listas* lista){
    Nodo* aux;
    Nodo* aux2;
    aux=lista->cabeza;

    while (aux!=NULL) {
        aux2=aux;
        aux=aux2->next;
        free(aux2);

    }
    free(aux);
    free(lista);

}
