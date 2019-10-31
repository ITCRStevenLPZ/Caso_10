#define HEADER_FILE
#include <stdio.h>
#define TAMANIO 10
//--------------------------STRUCTS----------------------------//
typedef char (*Funcion)(void*);
typedef struct ListaVoid{
void *I;
struct ListaVoid* siguiente;
struct ListaVoid* anterior;
}LisVoid;
typedef struct Matroid{
int id;
void *M[TAMANIO];
LisVoid *I;
Funcion W;
}Matroid;
//--------------------------VAR GLOBALES----------------------------//
LisVoid *First;
LisVoid *Last;
//--------------------------METODOS AUXILIARES----------------------------//
void InsertarVoid(void* nova){
    LisVoid *nueva;
    nueva=malloc(sizeof(LisVoid));
    nueva->I=nova;
    if(First==NULL){
        nueva->anterior=NULL;
        nueva->siguiente=NULL;
        First=nueva;
        Last=nueva;
    }else{
        nueva->siguiente=NULL;
        nueva->anterior=Last;
        Last->siguiente=nueva;
        Last=nueva;
    }
}
//--------------------------METODOS----------------------------//
char esPar (void* nueva){
    if(*(int *)nueva%2==0){
        InsertarVoid(nueva);
        printf("Numero par %d \n",*(int *)nueva);
        return '1';
    }else{
        printf("Numero no-par %d \n",*(int *)nueva);
        return '0';
    }
}
char esMultiplo10(void* nueva){
    if(*(int *)nueva%10==0){
        InsertarVoid(nueva);
        printf("Numero Multiplo %d \n",*(int *)nueva);
        return '1';
    }else{
        printf("Numero No-Multiplo %d \n",*(int *)nueva);
        return '0';
    }
}
/*char esMonosilabo(void* nueva){
    int contador=0;
    for(int a=0;a<TAMANIO;a++){
        if(char[a]!=NULL){
            contador++;
        }
    }
    if(*(char[TAMANIO][TAMANIO] *)){

    }
}*/



