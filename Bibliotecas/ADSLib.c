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

void ADS_Vreverse(int vector[], int vector_size) // ADSLib :: inverte vetor do tipo 'int'
{
	for(int i=0; i<(vector_size/2); i++){
		int inv = (vector_size- i - 1);
		int temp = vector[i];
		vector[i] = vector[inv];
		vector[inv] = temp;
	}
}

const int xm=3, ym=2;
void ADS_Minverse(int matrix[xm][ym])
{
	for(int x=0;x<xm;x++){
		for(int y=0;y<ym;y++)
		{
			matrix[x][y] *= -1;
		}
	}
}

// --- main --- 
int main()
{
  // intro
  puts("Biblioteca ADSLib Inicializada");
  // chamada
  int mtx[xm][ym] = {
  	{1,-2},
	{-3,4},
	{5,-6}
  };
  
  ADS_Minverse(mtx);
  
  for(int x=0;x<xm;x++){
  	printf("[%d]\t| %d\t| %d\n",x,mtx[x][0],mtx[x][1]);
  }
  // retorno
  return 0;
}
