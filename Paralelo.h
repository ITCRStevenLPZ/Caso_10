#define HEADER_FILE
#include <stdio.h>
#include "Matroide.h"

void esPar(struct Matroid* nueva,int TAMANIO){
    #pragma omp parallel
    {
    int conteo=0;
    for(int i=0;i<TAMANIO;i++){
        if(*(int *)nueva->M[i]%2==0){
            printf("Value of i = %d\n", *(int *)nueva->M[i]);
            conteo++;
        }
    }
    }

    system("Pause");
}

void iniciar(){

/*for(int i=0;i<4;i++){
      printf("%d\n",2);
}*/



}


