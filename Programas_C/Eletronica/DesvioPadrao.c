#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Desvio Padrao

#define MAX_SIZE 100  // Define o tamanho máximo do conjunto
#define FORMAT "%.2f" // Define o formato de saída da impressão

// Função para calcular a média de um conjunto de valores
float calcularMedia(const float conjunto[], int size) {
    float soma = 0;
    for (int i = 0; i < size; i++) {
        soma += conjunto[i];
    }
    return soma / size;
}

// Função para calcular o desvio padrão de um conjunto de valores
float calcularDesvioPadrao(const float conjunto[], int size, float media) {
    float somaDiff = 0;
    for (int i = 0; i < size; i++) {
        float diff = conjunto[i] - media;
        somaDiff += diff * diff;
    }
    float resDiff = somaDiff / size;
    return sqrt(resDiff);
}

int main() {
    int size; // tamanho do conjunto

	// Define o tamanho do conjunto de acordo com a entrada do usuário
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &size);

	// Verifica o tamanho inserido pelo usuário e aplica se for válido
    if (size <= 0 || size > MAX_SIZE) {
        printf("Tamanho invalido.\n");
        return 1;
    }

	// Alocar memória para o conjunto
    float *conjunto = (float*)malloc(size*sizeof(float));
    if (conjunto == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

	// Preencher o conjunto com os valores do usuário
    for (int i=0; i<size; i++) {
        printf("Digite o valor na %da posicao: ", i+1);
        scanf("%f", &conjunto[i]);
    }

	// Calculos essenciais
    float media = calcularMedia(conjunto, size);
    float desvioPadrao = calcularDesvioPadrao(conjunto, size, media);

	// Imprime o desvio padrão na tela
    printf("Desvio padrao: "FORMAT"\n", desvioPadrao);

	// Liberar memória do conjunto
    free(conjunto);

    return 0;
}
