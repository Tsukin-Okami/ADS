#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// desvio padrao

int main()
{
	int size;
	
	printf("Digite o tamanho do conjunto: ");
	scanf("%d",&size);
	
	float conjunto[size];
	
	for(int i=0;i<size;i++)
	{
		printf("Digite o valor na %da posicao: ",i+1);
		scanf("%f",&conjunto[i]);
	}
	
	// passo 1
	
	float soma_cj=0;
	for(int i=0;i<size;i++)
	{
		soma_cj += conjunto[i];
	}
	float res_cj = soma_cj/size;

	// passo 2

	float conjunto_diff[size];
	for(int i=0;i<size;i++)
	{
		conjunto_diff[i] = pow((conjunto[i]-res_cj),2);
	}
	
	// passo 3
	float soma_diff=0;
	for(int i=0;i<size;i++)
	{
		soma_diff += conjunto_diff[i];
	}
	float res_diff = soma_diff/size;
	float desvio = sqrt(res_diff);
	
	// fim
	
	printf("Desvio padrao: %.2f",desvio);
	
	return 0;
}
