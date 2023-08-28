#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* 
    - Modulo de Bibliotecas -
*/
#define prefix ADS

void ADS_Vsort(int vector[], int vector_size) // ADSLib :: organiza vetor numeral em ordem crescente
{
	for(int i=0; i<vector_size; i++)
    {
        for(int j=i+1; j<vector_size; j++) { if(vector[i]>vector[j])
            {
                float temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}



// --- main --- 
int main()
{
  // intro
  puts("Biblioteca ADSLib Inicializada");
  // chamada
  int vec[5] = {5,3,9,4,6};
  ADS_Vsort(vec,5);
  for(int i=0;vec[i]!='\0';i++){
  	printf("%d, ",vec[i]);
  }
  // retorno
  return 0;
}
