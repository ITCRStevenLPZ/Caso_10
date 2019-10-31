#define HEADER_FILE
#include <stdio.h>
#include "Matroide.h"
//-----------------STRUCT DE LA LISTA ENLAZADA----------------------------//
typedef struct Lista{
int IdLista;
Matroid *Elemento;
struct Lista *siguente;
struct Lista *anterior;
}Lista;
//-----------------PUNTEROS Y VARIABLES GLOBALES----------------------------//
int Cant=0;//cantidad de matroids
Lista *primero;
Lista *ultimo;
Matroid *nueva;
//-----------------METODOS AUXILIARES----------------------------//
int Buscar(LisVoid* DATO){
    DATO->visitado=1;
    LisVoid *tempo;
    tempo=ROOT;
    for(int i=0;i<Cant_I;i++){
        if(tempo->visitado==0){
            if(*(int *)tempo->I==*(int *)DATO->I){
                tempo->visitado=1;
                tempo=tempo->siguiente;
                printf("NICEE\n\n\n");
                return *(int *)DATO->I;
            }else{
                tempo=tempo->siguiente;
            }
        }else{
          tempo=tempo->siguiente;
        }
    }
    return 666;
}

//-----------------METODOS PARALELOS----------------------------//
void PARALELO1(){
    Lista *temporal;
    temporal=primero;
    #pragma omp parallel for
    for(int i=0;i<Cant;i++){
        for(int j=0;j<TAMANIO;j++){
            char res=temporal->Elemento->W(temporal->Elemento->M[j]);
            printf("El valor booleano es de = %c\n\n",res);
        }
        if(temporal->siguente!=NULL){
            temporal=temporal->siguente;
        }else{
            printf("Favor presionar ENTER\n");
        }

    }
    system("Pause");

}
void PARALELO2(){
    LisVoid *temp;
    temp=ROOT;
    printf("Interseccion de los I : \n");
    #pragma omp parallel for
    for(int a=0;a<Cant_I;a++){
        int res = Buscar(temp->I);
        printf("%d ",res);
        if(temp->siguiente!=NULL){
            temp=temp->siguiente;
        }else{
            printf("\nFin de ejecucion\n");
        }
    }

}


