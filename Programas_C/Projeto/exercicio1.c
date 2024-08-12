#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define pjmax 15

// 'R' receita - 'D' despesa

struct Project {
	int id;
	float value;
	char type;
};

int tipo;

void editProject(struct Project projetos[])
{
	printf("\tDetalhes do projeto:\nId: %d\nValor: ",projetos[tipo-1].id);
	
	float valor;
	char format;
	
	scanf("%f",&valor);
	valor = abs(valor);
	
	printf("Tipo: ");
	scanf(" %c",&format);
	format = toupper(format);
	
	if (format == 'D') {
		valor *= -1;
	}
	
	projetos[tipo-1].value += valor;
	projetos[tipo-1].type = format;
}

void intro(struct Project projetos[])
{
	printf("Numeros de projetos: 15\nDigite o numero do projeto que deseja editar: ");
	scanf("%d",&tipo);
	
	if (tipo == 0) {
		return;
	}
	
	editProject(projetos);
}

int main()
{
	struct Project projetos[pjmax];
	
	for (int i=0;i<pjmax;i++) {
		projetos[i].id = i+1;
		projetos[i].value = 0;
		projetos[i].type = 'R';
	}
	
	intro(projetos);
	while (tipo != 0) {
		intro(projetos);
	}
	
	printf("\n\tLista de projetos:\n");
	for (int i=0;i<pjmax;i++) {
		//char modo = (projetos[i].type == 'R') ? '+' : '-';
		printf("Projeto %d : R$%.2f\n",projetos[i].id,projetos[i].value);
	}
	
	return 0;
}
