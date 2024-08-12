#include <stdlib.h>
#include <stdio.h>

// exercicio 1 - matriz vetor

#define bf 10 // buffer size

void ADS_Vinverse(int vector[], int vector_size) // ADSLib :: inverte vetor do tipo 'int'
{
	for(int i=0; i<(vector_size/2); i++){
		int inv = (vector_size- i - 1);
		int temp = vector[i];
		vector[i] = vector[inv];
		vector[inv] = temp;
	}
}

int main()
{
	int vetor[bf];
	
	for(int i=0;i<bf;i++)
	{
		printf("Digite um numero para a posicao %d: ",i+1);
		scanf("%d",&vetor[i]);
	}
	
	printf("\n\tVetor inserido:\n");
	for(int i=0;i<bf;i++)
	{
		printf("%d, ",vetor[i]);
	}
	printf("\n");
	
	ADS_Vinverse(vetor,bf);
	
	printf("\n\tVetor inverso:\n");
	for(int i=0;i<bf;i++)
	{
		printf("%d, ",vetor[i]);
	}
	printf("\n");
	
	return 0;
}
