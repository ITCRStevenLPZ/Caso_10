#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<omp.h>
#include "lib.h"
#include "struct.h"


void sumar (int a);
int esPalindromo(char *cadena);
int esPar(int x);

int main()
{


   matroid_t *test;
   test = (matroid_t*)malloc(sizeof(matroid_t*));

   test->j=200;

   test->func = sumar;

   matroide(test);

   return 0;


}


void sumar (int a){
    a+=5;
    printf("%i\n",a);
}

int esPar(int x){
   if(x%2==0){
      return 1;
   }else{
      return 0;
   }
}

int esPalindromo(char *cadena) {
    int longitud = strlen(cadena);
    if (longitud <= 1){
     printf("PALINDROMO");
         return 1;
    }
    int inicio = 0, fin = longitud - 1;
    while (cadena[inicio] == cadena[fin]){
        if (inicio >= fin){
            printf("PALINDROMO");
            return 1;
        }
        inicio++;
        fin--;
    }
    printf("no PALINDROMO");
    return 0;
}
