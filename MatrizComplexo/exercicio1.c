#include <stdlib.h>
#include <stdio.h>

#define X 3 // linhas
#define Y 6 // colunas

int main(int argc, char const *argv[])
{
    int matriz[X][Y];

    // entrada da matriz pelo usuario
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            printf("Digite o valor da linha %d e da coluna %d: ",i,j);
            scanf("%d",&matriz[i][j]);
        }        
    }
    
    puts("\tMatriz antes:");
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            printf("%d\t| ",matriz[i][j]);
        }
        putchar('\n');
    }

    // calculo da soma das colunas impares
    int soma_impares = 0;
    for (int impar = 0; impar < Y; impar++)
    {
        if (impar%2 == 1)
        {
            for (int j = 0; j < X; j++)
            {
                soma_impares += matriz[j][impar];
            }
        }
    }
    
    // calculo da media das colunas 1 e 3
    float media_2,media_4;
    int soma_2=0,soma_4=0;
    for (int x = 0; x < X; x++)
    {
        soma_2 += matriz[x][1];
        soma_4 += matriz[x][3];
    }
    media_2 = (soma_2/X);
    media_4 = (soma_4/X);

    // substituicao dos valores da sexta coluna pela soma da 1 e 2 coluna
    for (int x = 0; x < X; x++)
    {
        int soma_coluna=0;
        for (int y = 0; y < 2; y++)
        {
            soma_coluna += matriz[x][y];
        }
        matriz[x][5] = soma_coluna;
    }
    
    // impressao da matriz
    puts("\tMatriz depois:");
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            printf("%d\t| ",matriz[i][j]);
        }
        putchar('\n');
    }

    printf("Soma dos elementos das colunas impares: %d\nMedia aritmetica dos elementos da segunda e quarta coluna: %.1f, %.1f.\n",
        soma_impares,
        media_2,
        media_4
    );
    puts("Efetuado substituicao dos valores da sexta coluna.");

    return 0;
}