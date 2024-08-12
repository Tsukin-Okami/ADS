#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// exercicio 1 - matrizes

#define bf_lista 2
#define clientes 12 // 12
#define bf_nome 40 // buffer size
#define promotion 15 // quantidade de compras para 1 garrafa

char nomes[clientes][bf_nome];
int lista[clientes][bf_lista];

/*  COMPRAS | VINHOS
    0       | 0 [compras/promotion]
*/

void forPromoted()
{
    for(int id=0; id<clientes; id++){
        if(lista[id][0] >= promotion){
            lista[id][1] = floor((lista[id][0])/15);
        }
	}
}

void setTempLista(int i, int j)
{
	int temp;
	for(int x=0;x<2;x++){
		temp = lista[i][x];
		lista[i][x] = lista[j][x];
		lista[j][x] = temp;
	}
	char temp_nome[bf_nome];
	strcpy(temp_nome,nomes[i]);
	strcpy(nomes[i],nomes[j]);
	strcpy(nomes[j],temp_nome);
}

void Sort()
{
	for(int i=0; i<clientes; i++)
	{
		for(int j=i+1; j<clientes; j++)
		{ 
			if(lista[i][1]>lista[j][1])
			{
				setTempLista(i,j);
            }
        }
	}
}

void registra()
{
	for(int i=0;i<clientes;i++)
	{
		printf("Digite o nome do cliente[%d]: ",i+1);
		scanf("%s",&nomes[i]);
		printf("Digite a quantidade de compras do mes anterior: ");
		scanf("%d",&lista[i][0]);
	}
}

void list()
{
	printf("\nLista dos clientes com maior numero de garrafas de vinho:\n");
    forPromoted();
    Sort();
	for(int i=clientes-1;i>=0;i--){
        printf("Cliente: %s - %d[%d] garrafas.\n",nomes[i],lista[i][1],lista[i][0]);
	}
}

int main()
{
	registra();
    list();
	return 0;
}
