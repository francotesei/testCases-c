#ifndef TESTCASES_H_INCLUDED
#define TESTCASES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define tsce_TAM1 50
#define TSCE_DATOS "testcase.in"

/*
NOTA: Todas las definiciones de funciones y var etc, tiene el prefijo "tsce_" para no ocasionar
    conflicto con otros nombre y para hacer referencia al testCase.
*/

/* STRUCTS  */


typedef struct{

  int x;

}tsce_t_info;

typedef struct tsce_s_nodo_pila{

    tsce_t_info info;
    struct tsce_s_nodo_pila *sig;

}tsce_t_nodo_pila;

typedef tsce_t_nodo_pila *tsce_t_pila;
typedef   tsce_t_nodo_pila  tsce_t_nodo_cola;

typedef struct {

    tsce_t_nodo_cola *pri,*ult;
}tsce_t_cola;


typedef  (*pf_crearPila)(tsce_t_pila*) tsce_t_crearPila
//#####################################//


            //DECLARACIONES //

void          tsce_crearPila(tsce_t_pila*);
int           tsce_apilar(tsce_t_pila*,const tsce_t_info*);
int           tsce_desapilar(tsce_t_pila*,tsce_t_info*);
int           tsce_verTope(const tsce_t_pila*,tsce_t_info*);
int           tsce_pilaVacia(const tsce_t_pila*);
int           tsce_pilaLlena(const tsce_t_pila*);
void          tsce_vaciarPila(tsce_t_pila*);

void          tsce_crearCola(tsce_t_cola*);
int           tsce_acolar(tsce_t_cola*,const tsce_t_info*);
int           tsce_desacolar(tsce_t_cola*,tsce_t_info*);
int           tsce_verPrimero(const tsce_t_cola*,tsce_t_info*);
int           tsce_colaVacia(const tsce_t_cola*);
int           tsce_colaLlena(const tsce_t_cola*);
void          tsce_vaciarCola(tsce_t_cola*);

int abrirArchivo(FILE **,const char*,const char*,int);
int cerrarArchivo(FILE **,int);
int setArchivo(FILE**,const tsce_t_info*);
int getArchivo(FILE**,tsce_t_info*);
int showArchivo(FILE**);


int tsce_init(); // CARGA EL TESTCASE.IN CON DATOS RAMDON //
int tsce_testErrorMsg(int);


// TESTCASE DE PILA //
int testCase_crearPila      (void (*pf_crearPila)(tsce_t_pila*));
int testCase_apilar         (int (*pf_apilar)(tsce_t_pila*,const tsce_t_info*));
int testCase_desapilar      (int (*pf_desapilar)(tsce_t_pila*,tsce_t_info*));
int testCase_verTope        (int (*pf_verTope)(const tsce_t_pila*,tsce_t_info*));
int testCase_pilaLlena      (int (*pf_pilaLlena)(const tsce_t_pila*));
int testCase_pilaVacia      (int (*pf_pilaVacia)(const tsce_t_pila*));
int testCase_vaciarPila     (void (*pf_vaciarPila)(tsce_t_pila*));
int testCase_fullTestCasePila   (void  (*crearPila)(tsce_t_pila*) ,
                                int   (*apilar)(tsce_t_pila*,const tsce_t_info*),
                                int   (*desapilar)(tsce_t_pila*,tsce_t_info*),
                                int   (*verTope)(const tsce_t_pila*,tsce_t_info*),
                                int   (*pilaLlena)(const tsce_t_pila*),
                                int   (*pilaVacia)(const tsce_t_pila*),
                                void  (*vaciarPila)(tsce_t_pila*));


int testCase_crearCola  (void (*pf_crearCola)(tsce_t_cola*));
int testCase_acolar     (int (*pf_acolar)(tsce_t_cola*,const tsce_t_info*));
int testCase_desacolar  (int (*pf_desacolar)(tsce_t_cola*,tsce_t_info*));
int testCase_VerPrimero (int (*pf_verPrimero)(const tsce_t_cola*,tsce_t_info*));
int testCase_colaLlena  (int (*pf_colaLlena)(const tsce_t_cola*));
int testCase_colaVacia  (int (*pf_colaVacia)(const tsce_t_cola*));
int testCase_vaciarCola (int (*pf_vaciarCola)(tsce_t_cola*));



































#endif /* TESTCASES_H_INCLUDED*/
