#include <stdio.h>
#include "Paralelo.h"

#define TAMANIO 10
//-----------------STRUCT DE LA LISTA MATROID----------------------------//

//-----------------STRUCT DE LA LISTA ENLAZADA----------------------------//
typedef struct Lista{
int IdLista;
struct Matroid *Elemento;
struct Lista *siguente;
struct Lista *anterior;
}Lista;
//-----------------PUNTEROS Y VARIABLES GLOBALES----------------------------//
Lista *primero;
Lista *ultimo;


void crearLista(){
    int list[]={1,2,3,4,5,6,7,8,9,10};
    struct Matroid *nueva;
    nueva = malloc(sizeof(struct Matroid));
    AsignarVoids(nueva);
    for(int i=0;i<TAMANIO;i++){
        nueva->M[i]=&list[i];
    }
    esPar(nueva,TAMANIO);

}
void AsignarVoids(struct Matroid *nueva){
    for(int i=0;i<TAMANIO;i++){
        nueva->I[i]=malloc(sizeof(void));
        nueva->M[i]=malloc(sizeof(void));
    }
}
int main(){
crearLista();
//ejemplo2();

    return 0;

}


