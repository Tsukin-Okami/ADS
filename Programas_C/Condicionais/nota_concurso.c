#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// nota concurso

int main(int argc, char const *argv[])
{
    // fatores de nota minima
    const int nota_min=5,nota_prova_min=4;

    char nome[40]; // nome candidato
    char provas[3][40] = {"Portugues","Matematica","Conhecimentos Gerais"}; // nome das provas
    int notas[3],total=0;

    // entrada do nome
    printf("Digite o nome do candidato: ");
    scanf("%s",&nome);

    // entrada das notas
    for (int i = 0; i<3; i++)
    {
        printf("Digite a nota(0/10) do candidato para a prova de %s: ",provas[i]);
        scanf("%d",&notas[i]);
    }
    
    // calculo total das notas
    for (int i = 0; i < 3; i++)
    {
        total = total + notas[i];
    }
    total = total/3;

    // tabela
    printf("    \nDetalhes:\n");
    printf("PROVA       | NOTA  | MAX\n");
    printf("PORTUGUES   | %d    | 10\n",notas[0]);
    printf("MATEMATICA  | %d    | 10\n",notas[1]);
    printf("CON. GERAIS | %d    | 10\n",notas[2]);
    printf("\nNota total: %d\n",total);

    // calcula se as notas do candidato se sao abaixo do min
    bool pass = ((total > nota_min) && ( (notas[0] > nota_prova_min) && (notas[1] > nota_prova_min) && (notas[2] > nota_prova_min)));
    printf("O candidato %s no concurso.",(pass ? "passou" : "nao passou"));
    return 0;
}
