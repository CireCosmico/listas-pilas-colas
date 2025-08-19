#include "pila.h"
#include <stdio.h>
#include <stdbool.h>

int main(){

    Pilas* pila = crear_pila();

    apilar(pila,5 );

    printf("tope de la pila %d \n",octen_tope(pila));

    apilar(pila,7 );

    printf("tope de la pila %d \n",octen_tope(pila));

    desapilar(pila);

    printf("tope de la pila %d \n",octen_tope(pila));

    if(es_vacia_pila(pila)){
        printf("es vavia \n");
    }else {
        printf("no es vavia \n");
    }

    elimi_pila(pila);

    if(es_vacia_pila(pila)){
        printf("es vavia \n");
    }

    return 0;
}
