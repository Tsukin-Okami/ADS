#include <stdlib.h>
#include <stdio.h>

// exercicio logica 1 - elevador

int main()
{
	const int moradores=50;
	int elevador[3][2] = {{'A',0},{'B',0},{'C',0}};
	
	for(int i=0;i<moradores;i++)
	{
		char elv;
		printf("Qual elevador o morador %d utiliza frequentemente?\n [A] / [B] / [C]\nElevador: ",i+1);
		scanf(" %c",&elv);
		
		if ('a' <= elv && elv <= 'c') {
        	elv -= 32;
    	}
		
		if ('A' <= elv && elv <= 'C') {
        	switch(elv)
			{
				case 'A':
					elevador[0][1]++;
					break;
				case 'B':
					elevador[1][1]++;
					break;
				case 'C':
					elevador[2][1]++;
					break;
			}
			printf("\n");
    	}
    	else
    	{
    		printf("\nEste elevador nao existe.");
			return 0;
		}
	}
	
	printf("Tabela de elevadores utilizados:\n");
	for(int i=0;i<3;i++)
	{
		printf("%c :: %d\n",elevador[i][0],elevador[i][1]);
	}
	
	return 0;
}
