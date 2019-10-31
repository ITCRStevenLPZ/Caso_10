#define HEADER_FILE
#include <stdio.h>
#define TAMANIO 10
//--------------------------STRUCTS----------------------------//

typedef char (*Funcion)(void*);

typedef struct ListaVoid{
int visitado;
void *I;
struct ListaVoid* siguiente;
struct ListaVoid* anterior;
}LisVoid;

typedef struct Matroid{
void *M[TAMANIO];
LisVoid *I;
Funcion W;
}Matroid;

//--------------------------VAR GLOBALES----------------------------//
LisVoid *First;
LisVoid *Last;
LisVoid *ROOT;
LisVoid *FIN;
int Cant_I=0;//cantidad de I's
//--------------------------METODOS AUXILIARES----------------------------//
void InsertarGeneral(void* nova){ //ESTAS DOS FUNCIONES AUXILIARES SON SIMILARES, LA UNICA DIFERENCIA ES QUE InsertarGeneral TRABAJA CON LOS I GLOBALES,LO CUAL AYUDA A ENCONTRAR LA...
    LisVoid *nuev;               //...INTERSECCION EN EL PUNTO B Y InsertarVoid FUNCIONA CON LOS I DE CADA MATROID.
    nuev=malloc(sizeof(LisVoid));
    nuev->I=nova;
    if(ROOT==NULL){
        nuev->visitado=0;
        nuev->anterior=NULL;
        nuev->siguiente=NULL;
        ROOT=nuev;
        FIN=nuev;
        Cant_I++;
    }else{
        nuev->visitado=0;
        nuev->siguiente=NULL;
        nuev->anterior=FIN;
        FIN->siguiente=nuev;
        FIN=nuev;
        Cant_I++;
    }
}
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
        InsertarGeneral(nueva);
        InsertarVoid(nueva);
        printf("Numero par %d \n",*(int *)nueva);
        return '1';
    }else{
        //printf("Numero no-par %d \n",*(int *)nueva);
        return '0';
    }
}
char esMultiplo10(void* nueva){
    if(*(int *)nueva%10==0){
        InsertarGeneral(nueva);
        InsertarVoid(nueva);
        printf("Numero Multiplo %d \n",*(int *)nueva);
        return '1';
    }else{
        printf("Numero No-Multiplo %d \n",*(int *)nueva);
        return '0';
    }
}
char esVocal(void* nueva){
    if(*(char*)nueva=='a'||*(char*)nueva=='e'){
        InsertarGeneral(nueva);
        InsertarVoid(nueva);
        printf("Vocal encontrada %c \n",*(int *)nueva);
        return '1';
    }else{
        printf("Vocal no encontrada %c \n",*(int *)nueva);
        return '0';
    }
}




