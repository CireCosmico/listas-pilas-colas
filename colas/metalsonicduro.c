#include "cola.h"
#include <stdio.h>
#include <stdbool.h>

int main(){

    Colas* cola = crear_cola();

    encolar(cola,5 );
    encolar(cola,8 );
    encolar(cola,10 );

    printf("primero de la cola %d \n",octe_primaro_cola(cola));

    desencolar(cola);

    printf("primero de la cola %d \n",octe_primaro_cola(cola));

    desencolar(cola);

    elim_cola(cola);

    if(es_vacia_cola(cola)){

        printf("es vacia\n");

    }else {

        printf("no es vacia\n");

    }


    return 0;
}
