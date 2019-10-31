#include <stdio.h>
#include "Paralelo.h"


int arreglo[15]={1,56,4,7,10,5,76,85,98,65,55,43,69,12,47};
void PruebaPar(){
    nueva = malloc(sizeof(Matroid));
    AsignarVoids(nueva);
    for(int i=0;i<TAMANIO;i++){
        nueva->M[i]=&arreglo[rand()%15];
    }
    nueva->W=&esPar;
    anadir(nueva);
}
void PruebaMultiplo(){
    nueva = malloc(sizeof(Matroid));
    AsignarVoids(nueva);
    for(int i=0;i<TAMANIO;i++){
        nueva->M[i]=&arreglo[rand()%15];
    }
    nueva->W=&esMultiplo10;
    anadir(nueva);
}

void anadir(Matroid *nueva){
    Lista *nuevo;
    nuevo=malloc(sizeof(Lista));
    nuevo->Elemento=nueva;
    if(primero==NULL){
        nuevo->anterior=NULL;
        nuevo->siguente=NULL;
        primero=nuevo;
        ultimo=nuevo;
        Cant++;
    }else{
        nuevo->siguente=NULL;
        nuevo->anterior=ultimo;
        ultimo->siguente=nuevo;
        ultimo=nuevo;
        Cant++;
    }
}

void AsignarVoids(Matroid *nueva){
    for(int i=0;i<TAMANIO;i++){
        nueva->I=malloc(sizeof(LisVoid));
        nueva->M[i]=malloc(sizeof(void));
    }
}
int main(){
PruebaPar();
PruebaMultiplo();
iniciar();

    return 666;

}


