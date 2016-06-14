#include <stdio.h>
#include <stdlib.h>
#include "testCases.h"


//  PRIMITIVAS DE COLA //

void    tsce_crearCola(tsce_t_cola *c){

    c->pri = NULL;
    c->ult = NULL;

}

int     tsce_acolar(tsce_t_cola *c,const tsce_t_info *info){

tsce_t_nodo_cola *nue = (tsce_t_nodo_cola*)malloc(sizeof(tsce_t_nodo_cola));

if(!nue)
    return 0;

    nue->info = *info;
    nue->sig = NULL;

    if(c->pri == NULL)
        c->pri = nue;
    else
        c->ult->sig = nue;

    c->ult = nue;

    return 1;


}

int tsce_desacolar(tsce_t_cola *c ,tsce_t_info *info){

    tsce_t_nodo_cola *aux;

    if(c->pri == NULL)
        return 0;

    *info = c->pri->info;

    if(c->pri == c->ult)
        c->ult = NULL;

    aux = c->pri;
    c->pri = c->pri->sig;
    free(aux);
    return 1;

}

int tsce_verPrimero(const tsce_t_cola *c ,tsce_t_info *info){

    if(c->pri == NULL)
        return 0;

    *info = c->pri->info;
    return 1;

}

int tsce_colaLlena(const tsce_t_cola *c){

    void *aux = malloc(sizeof(tsce_t_nodo_cola));
    free(aux);
    return (!aux)? 1 : 0;

}

int tsce_colaVacia(const tsce_t_cola *c){

    return (c->pri == NULL)? 1 : 0;

}

void tsce_vaciarCola(tsce_t_cola *c){

    tsce_t_nodo_cola *aux;

    while( c->pri != NULL){

        aux = c->pri;
        c->pri = aux->sig;
        free(aux);
    }
    c->pri = c->ult = NULL;
}
