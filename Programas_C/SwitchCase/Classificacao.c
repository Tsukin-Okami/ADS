#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// exercicio 3 - switch case - codigo classificacao

int main(int argc, char const *argv[])
{
    char nome[40],classe[60];
    int id;

    printf("Digite o nome do produto: ");
    scanf("%s",&nome);
    printf("Digite o codigo do produto: ");
    scanf("%d",&id);
    
    switch (id)
    {
        case 1:
            strcpy(classe,"Alimento Nao-perecivel");
            break;
        case 2:
        case 3:
        case 4:
            strcpy(classe,"Alimento Perecivel");
            break;
        case 5:
        case 6:
            strcpy(classe,"Vestuario");
            break;
        case 7:
            strcpy(classe,"Higiene Pessoal");
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            strcpy(classe,"Limpeza e Utensilios Domesticos");
            break;
        default:
            strcpy(classe,"Codigo Invalido");
            break;
    }

    printf("Classificacao do produto %s com codigo(%d) eh:\n%s",nome,id,classe);

    return 0;
}
