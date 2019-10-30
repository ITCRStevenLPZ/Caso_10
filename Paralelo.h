#define HEADER_FILE
#include <stdio.h>
#include "Matroid.h"


void iniciar(){
#pragma omp parallel for
for(int i=0;i<4;i++){
      printf("%d\n",2);
}

system("Pause");

}


