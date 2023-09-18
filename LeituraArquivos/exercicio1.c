#include <stdlib.h>
#include <stdio.h>

#define bf_n 40
#define bf_t 11
#define bf_e 40
#define bf_c 11

struct FormatoDados {
	char nome[bf_n];
	int telefone[bf_t]; // (+55) > 51 99235 3921
	char endereco[bf_e];
	int cpf[bf_c]; // 05132654210
};

void EditData(struct FormatoDados data)
{
	puts("Digite o nome do cliente: ");
	fgets(data.nome,bf_n,stdin);
	puts("Digite o telefone do cliente: ");
	scanf("%d",&data.telefone);
	puts("Digite o endereco do cliente: ");
	fgets(data.endereco,bf_e,stdin);
	puts("Digite o cpf do cliente: ");
	scanf("%d",&data.cpf);
}

int main()
{
	struct FormatoDados Cliente;
	
	EditData(Cliente);
	
	putchar('\n');
	
	printf("Nome: %s\nTelefone: %d\nEndereco: %s\nCPF: %d\n",Cliente.nome,Cliente.telefone,Cliente.endereco,Cliente.cpf);
	
	return 0;
}
