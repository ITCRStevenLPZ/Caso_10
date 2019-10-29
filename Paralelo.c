/*#include <stdio.h>
#include <Matroid.h>
int prueba[]={1,2,3,4};
int main(){
    //int indice=0;
    /*for(int i = 0; i < 4 ;i++){

    }
#pragma omp parallel for
for(int i=0;i<4;i++){
      printf("%d\n",prueba[i]);
}
system("Pause");
return 0;
*/

#include "omp.h"


int main()
{


    int tamano = 600;
    int A [tamano][tamano], B [tamano][tamano], C [tamano][tamano], C2[tamano][tamano];

    for(int i=0; i < tamano; ++i)
        for(int j=0; j < tamano; ++j){
            A[i][j] = 0;
            B[i][j] = 0;
            C[i][j] = 0;

        }

    for(int i=0; i < tamano; ++i)
        for(int j=0; j < tamano; ++j){
            A[i][j] = j;
            B[i][j] = j;
            C[i][j] = 0;
        }

   struct timeval t0, t1;
   gettimeofday(&t0, 0);
   for(int i=0; i < tamano; i++)
        for(int j=0; j < tamano;j++)
            for(int z=0; z < tamano; z++){

                C[i][j] += A[i][z] * B[z][j];

            }
    gettimeofday(&t1, 0);
	double elapsed2 = (t1.tv_sec-t0.tv_sec) * 1.0f + (t1.tv_usec - t0.tv_usec) / 1000000.0f;
    printf("tiempo secuencial: ")<< elapsed2;

   struct timeval t2, t3;
   gettimeofday(&t2, 0);
   #pragma omp parallel for
   for(int i=0; i< tamano; i++)
        for(int j=0; j< tamano;j++)
            for(int z=0; z< tamano; z++){

                C[i][j] += A[i][z] * B[z][j];

            }


    return 0;
}
