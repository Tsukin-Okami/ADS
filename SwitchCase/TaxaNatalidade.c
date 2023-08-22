#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// exercicio 1 - Switch case - Taxa Natalidade e Mortalidade

int main()
{
    int tipo,hab,num;
    float taxa;

    printf("Digite o numero de habitantes: ");
    scanf("%d",&hab);

    printf("O que deseja ver: \n[1] Taxa de Natalidade.\n[2] Taxa de Mortalidade.\n");
    scanf("%d",&tipo);

    char nometipo[12]; // aloca uma cadeia de caracteres
    switch (tipo)
    {
        case 1:
            strcpy(nometipo, "Natalidade"); // define a cadeia de caracteres
            printf("Digite a numero de nascimentos: ");
            scanf("%d",&num);
            break;

        case 2:
            strcpy(nometipo, "Mortalidade"); // define a cadeia de caracteres
            printf("Digite a numero de obitos: ");
            scanf("%d",&num);
            break;

        default:
            printf("Valor inserido nao eh valido.");
            return 0;
            break;
    }
    
    taxa = (num * 1000) / hab;

    printf("Taxa de %s: %.1f%%",nometipo,taxa);

    return 0;
}
