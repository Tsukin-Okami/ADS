#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// exercicio 4 - SwitchCase - operadores

char operadores[4][50] = {"Media entre os numeros","Diferenca entre numeros","Produto dos numeros","Divisao do primeiro pelo segundo"};

int main(int argc, char const *argv[])
{
    float aa,bb;
    int tipo;
    float res;

    printf("Digite o valor de A: ");
    scanf("%f",&aa);
    printf("Digite o valor de B: ");
    scanf("%f",&bb);

    printf("\n\tTipos de operadores:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("[%d] - %s\n",i+1,operadores[i]);
    }

    printf("Digite o tipo de operacao: ");
    scanf("%d",&tipo);
    
    switch (tipo)
    {
    case 1:
        res = (aa+bb)/2;
        break;
    case 2:
        res = abs(bb-aa);
        break;
    case 3:
        res = aa*bb;
        break;
    case 4:
        res = aa/bb;
        break;
    default:
        break;
    }

    printf("\nO resultado eh: %.2f",res);
    return 0;
}
