#include <stdlib.h>
#include <stdio.h>

#define X 5
#define Y 4

#define bf 20
const char tipos[Y][bf] = {
    "Numero da matricula",
    "Media das provas",
    "Media dos trabalhos",
    "Nota final"
};

int data_disciplina[X][Y];

int main(int argc, char const *argv[])
{
    puts("*Este algoritmo aceita apenas inteiros.");
    for (int x = 0; x < X; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            printf("Digite o(a) %s do aluno %d: ",tipos[y],x+1);
            scanf("%d",&data_disciplina[x][y]);
        }
    }

    for (int x = 0; x < X; x++)
    {
        int final = (data_disciplina[x][1] + data_disciplina[x][2]) / 2;
        data_disciplina[x][3] = final;
    }
    
    int nota[2]={0,0};
    for (int x = 0; x < X; x++)
    {
        if (nota[0] < data_disciplina[x][3]) {
            nota[0] = data_disciplina[x][3];
            nota[1] = x;
        }
    }

    printf("\tMaior nota:\nMatricula: %d\nNota: %d\n", data_disciplina[nota[1]][0], nota[0]);
    printf("\tNotas finais:\n");
    for (int x = 0; x < X; x++)
    {
        printf("%d, ", data_disciplina[x][3],x);
    }

    return 0;
}