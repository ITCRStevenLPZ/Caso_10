//ALGORITMO CREADO POR RONALD ESQUIVEL LOPEZ Y FABIAN VIVES
#include <stdio.h>
#include "Paralelo.h"
//--------------------------VAR GLOBALES----------------------------//
char letras[15]={'a','e','f','j','k','h','l','q','d','b','p','v','w','z'};
int arreglo[15]={1,56,4,7,10,5,76,85,98,65,55,43,69,12,47};
//--------------------------METODOS AUXILIARES----------------------------//
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
    nueva->I=malloc(sizeof(LisVoid));
    for(int i=0;i<TAMANIO;i++){
        nueva->M[i]=malloc(sizeof(void));
    }
}
//--------------------------METODOS PRUEBAS----------------------------//
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
void PruebaVocales(){
    nueva = malloc(sizeof(Matroid));
    AsignarVoids(nueva);
    for(int i=0;i<TAMANIO;i++){
        nueva->M[i]=&letras[rand()%15];
    }
    nueva->W=&esVocal;
    anadir(nueva);
}
//--------------------------METODOS EJEMPLO----------------------------//
void PuntoA(){
    PruebaPar();
    PruebaMultiplo();
    PruebaVocales();
    PARALELO1();
}
void PuntoB(){
    for(int i=0;i<5;i++){
        PruebaPar();
    }
    PARALELO1();
    PARALELO2();
}
//--------------------------MAIN----------------------------//
int main(){ //PARA PROBAR  EL PUNTO A Y EL PUNTO B DEL ENUNCIADO SE DEBE ESCOJER UNO, SOLO UNO. CASO CONTRARIO EL PUNTO B VA A SALIR CORRUPTO
PuntoA();
//PuntoB(); //el punto B no salio como debia debido a razones de tiempo
    return 0;

}


