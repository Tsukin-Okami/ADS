#include <stdlib.h>
#include <stdio.h>

// exercicio 2 - matriz vetor

int main()
{
	int grid=3;
	float matrix[grid][grid];
	
	for(int x=0;x<grid;x++){
		for(int y=0;y<grid;y++){
			printf("Digite o valor para a posicao[%d][%d]: ",x,y);
			scanf("%f",&matrix[x][y]);
		}
	}
	
	for(int x=0;x<grid;x++){
		for(int y=0;y<grid;y++)
		{
			matrix[x][y] *= -1;
		}
	}
	
	for(int x=0;x<grid;x++){
		printf("\n[%d] | ",x);
		for(int y=0;y<grid;y++){
			printf("%.1f | ",matrix[x][y]);
		}
	}
	
	return 0;
}
