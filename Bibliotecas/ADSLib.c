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
        for(int j=i+1; j<vector_size; j++) 
		{ 
			if(vector[i]>vector[j])
            {
                float temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}

void ADS_Vinverse(int vector[], int vector_size) // ADSLib :: inverte vetor do tipo 'int'
{
	for(int i=0; i<(vector_size/2); i++){
		int inv = (vector_size- i - 1);
		int temp = vector[i];
		vector[i] = vector[inv];
		vector[inv] = temp;
	}
}

// --- main --- 
int main()
{
  // intro
  puts("Biblioteca ADSLib Inicializada");
  // chamada
  int buffer = 5;
  int vec[buffer] = {4,5,3,1,2};
  ADS_Vinverse(vec,buffer);
  for(int i=0;i<buffer;i++){
  	printf("%d, ",vec[i]);
  }
  // retorno
  return 0;
}
