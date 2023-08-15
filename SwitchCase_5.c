#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// exercicio 5 - switch case - preco do produto

int main(int argc, char const *argv[])
{
    int id,qtd;
    float valor;

    printf("Digite o codigo do produto: ");
    scanf("%d",&id);
    
    switch (id)
    {
    case 100:
        valor = 1.7;
        break;
    case 101:
        valor = 2.3;
        break;
    case 102:
        valor = 2.6;
        break;
    case 103:
        valor = 2.4;
        break;
    case 104:
        valor = 2.5;
        break;
    case 105:
        valor = 1;
        break;
    default:
        printf("Codigo Invalido");
        return 0;
        break;
    }

    printf("Digite a quantidade do produto: ");
    scanf("%d",&qtd);

    printf("O valor total do produto eh: R$%.2f",valor*qtd);
    return 0;
}
