#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BF_N 60
#define BF_T 15 // inclui espaço para (+55) e espaço para o caractere nulo.
#define BF_E 80
#define BF_C 12 // inclui espaço para 11 dígitos e o caractere nulo.

struct FormatoDados {
    char nome[BF_N];
    char telefone[BF_T];
    char endereco[BF_E];
    char cpf[BF_C];
};

void EditData(struct FormatoDados *data)
{
    printf("Digite o nome do cliente: ");
    fgets(data->nome, sizeof(data->nome), stdin);
    data->nome[strcspn(data->nome, "\n")] = '\0'; // Remove a nova linha.

    printf("Digite o telefone do cliente (formato: (+55) 51 99235 3921): ");
    fgets(data->telefone, sizeof(data->telefone), stdin);
    data->telefone[strcspn(data->telefone, "\n")] = '\0'; // Remove a nova linha.

	getchar(); // Evita pular o endereço do cliente.

    printf("Digite o endereco do cliente: ");
    fgets(data->endereco, sizeof(data->endereco), stdin);
    data->endereco[strcspn(data->endereco, "\n")] = '\0'; // Remove a nova linha.

    printf("Digite o cpf do cliente (formato: 05132654210): ");
    fgets(data->cpf, sizeof(data->cpf), stdin);
    data->cpf[strcspn(data->cpf, "\n")] = '\0'; // Remove a nova linha.
}

int main()
{
    struct FormatoDados Cliente;
    //EditData(&Cliente);

	strcpy(Cliente.nome,"Marcos Fontaine");
	strcpy(Cliente.telefone,"+5551992353921");
	strcpy(Cliente.endereco,"Vila Nova");
	strcpy(Cliente.cpf,"05132654210");

	int *memory = malloc(sizeof(struct FormatoDados));
	FILE *database = fopen("cliente.txt", "w");

	if (database == NULL) {
		perror("Erro ao abrir o arquivo");
		return 1;
	}

	fprintf(database, "%s", "Nome: %s\nTelefone: %s\nEndereco: %s\nCPF: %s\n", Cliente.nome, Cliente.telefone, Cliente.endereco, Cliente.cpf);

    return 0;
}

/*

int main() {
    // Nome do arquivo
    char *nome_arquivo = "exemplo.txt";

    // Abrir o arquivo para escrita
    FILE *arquivo = fopen(nome_arquivo, "w");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Pedir ao usuário para digitar o texto
    printf("Digite o texto a ser escrito no arquivo (Ctrl+D para encerrar no Linux ou Ctrl+Z no Windows):\n");

    char linha[100];
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        // Escrever a linha no arquivo
        fprintf(arquivo, "%s", linha);
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Abrir o arquivo para leitura
    arquivo = fopen(nome_arquivo, "r");

    // Verificar se o arquivo foi aberto com sucesso para leitura
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    // Ler e imprimir o conteúdo do arquivo
    printf("\nConteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Fechar o arquivo novamente
    fclose(arquivo);

    return 0;
}

*/