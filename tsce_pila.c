#include <stdio.h>
#include <stdlib.h>
#include "testCases.h"


int testCase_fullTestCasePila   (void  (*crearPila)(tsce_t_pila*) ,
                                int   (*apilar)(tsce_t_pila*,const tsce_t_info*),
                                int   (*desapilar)(tsce_t_pila*,tsce_t_info*),
                                int   (*verTope)(const tsce_t_pila*,tsce_t_info*),
                                int   (*pilaLlena)(const tsce_t_pila*),
                                int   (*pilaVacia)(const tsce_t_pila*),
                                void  (*vaciarPila)(tsce_t_pila*)){

    printf("\n <<Iniciando Full testCase Pila>>\n\n");
    printf("\n Cargando datos de Inicio\n\n");
    tsce_init();
    printf("Fin de la carga de datos\n\n");
    printf("\n Probando Primitivas\n\n");

    printf("\nProbando Crear Pila...\n");
    if(!testCase_crearPila((*crearPila)))
        return tsce_testErrorMsg(1);
     printf("\nPasa\n\n");

       printf("\nProbando Apilar...\n");
    if(!testCase_apilar((*apilar)))
        return tsce_testErrorMsg(2);
     printf("\nPasa\n\n");

       printf("\nProbando Desapilar...\n");
    if(!testCase_desapilar((*desapilar)))
        return tsce_testErrorMsg(3);
     printf("\nPasa\n\n");

       printf("\nProbando Ver Tope...\n");
    if(!testCase_verTope((*verTope)))
        return tsce_testErrorMsg(4);
     printf("\nPasa\n\n");

       printf("\nProbando Pila Llena...\n");
    if(!testCase_pilaLlena((*pilaLlena)))
        return tsce_testErrorMsg(5);
     printf("\nPasa\n\n");

       printf("\nProbando Pila Vacia...\n");
    if(!testCase_pilaVacia((*pilaVacia)))
        return tsce_testErrorMsg(6);
     printf("\nPasa\n\n");

       printf("\nProbando Vaciar Pila...\n");
    if(!testCase_vaciarPila((*vaciarPila)))
        return tsce_testErrorMsg(7);
     printf("\nPasa\n\n");


     printf("<<TestCase Pila Finalizado Correctamente>>\n");
     return 1;



}

int tsce_testErrorMsg(int x){

    switch(x){

        case 1:
            printf("\nERROR en Crear Pila\n");
        break;

        case 2:
            printf("\nERROR en Apilar\n");
        break;

        case 3:
            printf("\nERROR en Desapilar\n");
        break;

        case 4:
            printf("\nERROR en Ver Primero \n");
        break;

        case 5:
            printf("\nERROR en Pila Llena\n");
        break;

        case 6:
            printf("\nERROR en Pila Vacia\n");
        break;

        case 7:
            printf("\nERROR en Vaciar Pila\n");
        break;
    }
    return 0;

}


int testCase_crearPila(void (*crearPila)(tsce_t_pila*)){


        tsce_t_pila p;
        (*crearPila)(&p);

        return (tsce_pilaVacia(&p))? 1:0;

}

int testCase_apilar(int (*pf_apilar)(tsce_t_pila*,const tsce_t_info*)){

    tsce_t_pila p1;
    int s = 0;
    tsce_t_info info,infoAux;
    FILE *pf = NULL;

    tsce_crearPila(&p1);
    abrirArchivo(&pf,TSCE_DATOS,"rb",1);

    while(getArchivo(&pf,&info) && !s){

        getArchivo(&pf,&info);
        if(!(*pf_apilar)(&p1,&info))
            s = 1;
        if(tsce_pilaVacia(&p1))
            s = 1;
    }
    if(!tsce_desapilar(&p1,&infoAux))
        s = 1;
    if(infoAux.x != info.x)
        s = 1;
    cerrarArchivo(&pf,1);
    return !s;

}

int testCase_desapilar(int (*pf_desapilar)(tsce_t_pila*,tsce_t_info*)){

    tsce_t_pila p1;
    tsce_t_info info,infoAux;
    FILE *pf = NULL;
    int s = 0 , c = 0;

    tsce_crearPila(&p1);
    abrirArchivo(&pf,TSCE_DATOS,"rb",1);

    while(getArchivo(&pf,&info) && !s){

        getArchivo(&pf,&info);
        if(!tsce_apilar(&p1,&info))
            s = 1;
        if(tsce_pilaVacia(&p1))
            s = 1;
        c++;
    }
    cerrarArchivo(&pf,1);
    if(!tsce_verTope(&p1,&infoAux))
        s = 1;
    if(info.x != infoAux.x)
        s = 1;

    while((*pf_desapilar)(&p1,&info))
        c--;

    if(!(!c && tsce_pilaVacia(&p1)))
        s = 1;

     return !s;


}

int testCase_verTope(int (*pf_verTope)(const tsce_t_pila*,tsce_t_info*)){


    tsce_t_pila p1;
    tsce_t_info info;
    tsce_t_info infoAux;
    FILE *pf = NULL;
    int s = 0;

    tsce_crearPila(&p1);
    abrirArchivo(&pf,TSCE_DATOS,"rb",1);

    while(getArchivo(&pf,&info) && !s){

        if(!tsce_apilar(&p1,&info))
            s = 1;
        if(tsce_pilaVacia(&p1))
            s = 1;
    }
    cerrarArchivo(&pf,1);

    (*pf_verTope)(&p1,&infoAux);

    return (infoAux.x == info.x)? 1 : 0;

}

int testCase_pilaLlena(int (*pf_pilaLlena)(const tsce_t_pila*)){
    return 1;

}


int testCase_pilaVacia(int (*pf_pilaVacia)(const tsce_t_pila*)){

    tsce_t_pila p1;
    tsce_crearPila(&p1);

    return((*pf_pilaVacia)(&p1))? 1 : 0;

}

int testCase_vaciarPila(void (*pf_vaciarPila)(tsce_t_pila*)){

    tsce_t_pila p1;
    tsce_t_info info;
    int s = 0;
    FILE **pf;
    tsce_crearPila(&p1);

    abrirArchivo(&pf,TSCE_DATOS,"rb",1);

      while(getArchivo(&pf,&info) && !s){

        if(!tsce_apilar(&p1,&info))
            s = 1;
        if(tsce_pilaVacia(&p1))
            s = 1;
    }
    cerrarArchivo(&pf,1);
    (*pf_vaciarPila)(&p1);

    return (tsce_pilaVacia(&p1) && !s)? 1 : 0;

}


/* PRIMITIVAS DE PILA */

void    tsce_crearPila(tsce_t_pila* p){

    *p = NULL;
}

int       tsce_apilar(tsce_t_pila* p, const tsce_t_info* info){

    tsce_t_nodo_pila *nue = (tsce_t_nodo_pila*)malloc(sizeof(tsce_t_nodo_pila));

    if(!nue)
        return 0;

        nue->info = *info;
        nue->sig = *p;
        *p = nue;
        return 1;

}

int       tsce_desapilar(tsce_t_pila* p, tsce_t_info* info){

    tsce_t_nodo_pila *aux;

    if(*p == NULL)
        return 0;

    *info = (*p)->info;
    aux = *p;
    *p =aux->sig;
    free(aux);
    return 1;
}
int       tsce_verTope(const tsce_t_pila* p , tsce_t_info* info){

    if(*p == NULL)
        return 0;

    *info = (*p)->info;
    return 1;
}
int       tsce_pilaLlena(const tsce_t_pila* p){



    void *nue = malloc(sizeof(tsce_t_nodo_pila));
    free(nue);

    return(!nue)? 1: 0;
}
int       tsce_pilaVacia(const tsce_t_pila* p){


    return( *p == NULL)? 1 : 0;
}
void    tsce_vaciarPila(tsce_t_pila* p){

    tsce_t_nodo_pila *aux;

    while(*p != NULL){

        aux = *p;
        *p = aux->sig;
        free(aux);
    }
    *p = NULL;

}
