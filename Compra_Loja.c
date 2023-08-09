#include <stdlib.h>
#include <stdio.h>

// compra loja

int main(int argc, char const *argv[])
{
    char nome[4][40]; // 4 nomes com max de 40 caracteres
    float valores[4],porcentagem[4],desconto[4]; // armazena 4 valores
    float total=0;

    // entrada das informacoes
    for (int i = 0; i<4; i++)
    {
        printf("Digite o nome do produto %d: ",i+1);
        scanf("%s",&nome[i]);
        printf("Digite o valor do produto %d: R$",i+1);
        scanf("%f",&valores[i]);
        printf("Digite a porcentagem de desconto do produto %d: ",i+1);
        scanf("%f",&porcentagem[i]);
    }

    // efetua o calculo do desconto
    for (int i = 0; i<4; i++)
    {
        desconto[i] = (valores[i]*(1-porcentagem[i]/100));
        total = total + desconto[i];
    }
    
    // imprime valores finais
    printf("  \nDetalhes:\n");
    printf("PRODUTO   | VALOR    | C/DESCONTO\n");
    for (int i = 0; i<4; i++)
    {
        printf("%s  | R$%.2f    | R$%.2f\n",nome[i],valores[i],desconto[i]);
    }
    printf("\nTotal a pagar: R$%.2f",total);

    return 0;
}
