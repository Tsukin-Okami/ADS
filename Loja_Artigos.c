#include <stdlib.h>
#include <stdio.h>

// loja de artigos R$1,99

int main(int argc, char const *argv[])
{
    const float valor = 1.99;
    const int itens = 50;

    printf("\nLojas Quase Dois - Tabela de valores:\n");
    for(int i=0;i<itens;i++)
    {
        int n = i+1;
        printf(" %d - R$%.2f\n",n,valor*n);
    }

    return 0;
}
