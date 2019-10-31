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
Cant=0;//cantidad de matroids
Lista *primero;
Lista *ultimo;
Matroid *nueva;
//-----------------METODOS----------------------------//
void iniciar(){
    Lista *temporal;
    temporal=primero;
    #pragma omp parallel for
    for(int i=0;i<Cant;i++){
        for(int j=0;j<TAMANIO;j++){
            char res=temporal->Elemento->W(temporal->Elemento->M[j]);
            printf("El valor booleano es de = %c\n",res);
        }
        if(temporal->siguente!=NULL){
            temporal=temporal->siguente;
        }else{
            //printf("Fin de ejecucion\n");
        }

    }
    system("Pause");

}


