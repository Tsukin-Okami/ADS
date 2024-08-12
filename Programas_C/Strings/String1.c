#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// exercicio 1 - string

int main()
{
	char cargo[30];
	float sal,per,salnew,diff;
	
	puts("Digite o seu cargo:");
	gets(cargo);
	puts("Digite o seu salario:");
	scanf("%f",&sal);
	
	if(strcmp(cargo,"Gerente") == 0){
		per = .1;
	}
	else if(strcmp(cargo,"Engenheiro") == 0){
		per = .2;
	}
	else if(strcmp(cargo,"Tecnico") == 0){
		per = .3;
	}
	else{
		per = .4;
	}
	
	diff = sal*per;
	salnew = sal+diff;
	
	printf("\nSalario Antigo: R$%.2f\nSalario Novo: R$%.2f\nDiferenca Salarial: R$%.2f\n",sal,salnew,diff);
	
	return 0;
}
