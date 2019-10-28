#include <stdio.h>
//#include <Matroid.h>
int prueba[]={1,2,3,4};
int main(){
    //int indice=0;
    /*for(int i = 0; i < 4 ;i++){

    }*/
#pragma omp parallel for
for(int i=0;i<4;i++){
      printf("%d\n",prueba[i]);
}

system("Pause");
return 0;
}
