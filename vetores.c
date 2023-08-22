#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define bf_line 60
#define bf_escala 40
#define bf_nome 20
#define bf_origin 40
#define bf_goto 40

// cidades disponiveis
#define cidades 5
const char Escalas[cidades][bf_escala] = {
    "Florianopolis", "Curitiba", "Sao Paulo", "Rio de Janeiro", "Belo Horizonte"
};

// listas de passageiros
char vNome[5][bf_nome]; // nomes
char vOrigin[5][bf_origin]; // cidade origem
char vGoto[5][bf_goto]; // cidade destino

const char cline = '/';

void crline(){
    for(int i=0;i<=bf_line;i++){
        printf("%c",cline);
    }
    printf("\n");
}

// espaco ocupado pelo vetor vNome
int get_fillers(){
    int filled=0;
    for(int i=0;vNome[i][0]!='\0';i++){
        filled += 1;
        //printf("for func_fill: %d - [%d]\n",filled,vNome[i][0]);
    }
    return filled;
}

void passageiro_add()
{
    int fill = get_fillers(); // pega espaco usado atualmente
    int qtd;
    printf("Quantos passageiros deseja adicionar: ");
    scanf("%d",&qtd);
    // repete ate a quantidade de passeiros selecionada
    for(int i=0;i<qtd;i++){
        printf("\nDigite o nome do passageiro[%d]: ",i+1);
        scanf("%s%*c",&vNome[fill+i]);
        printf("Digite a cidade de origem do passageiro[%d]: ",i+1);
        fgets(vOrigin[fill+i],bf_origin, stdin);
        printf("Digite a cidade de destino do passageiro[%d]: ",i+1);
        fgets(vGoto[fill+i],bf_goto, stdin);
    }
}

void lista_escalas()
{
    printf("\n");
    for(int i=0;i<cidades;i++){ // mostra todas as cidades disponiveis
        int z=0, fill=get_fillers();
        printf("Passageiros de %s:\n",Escalas[i]); // mostra as info dos passageiros de acordo com a cidade
        for(int x=0;x<fill;x++){
            if(strcmp(vGoto[x],Escalas[i]) == 0){ // compara o destino do passageiro com a cidade
                z++; // indice da tabela do passageiro
                printf("\t[%d]:\n\t\tNome: %s\n\t\tOrigem: %s\n\t\tDestino: %s\n",z,vNome[x],vOrigin[x],vGoto[x]); // imprime tabela do passageiro
            }
        }
    }

    // espera a entrada do usuario para voltar
    // sem isso ele automaticamente volta pro menu e nao aparece a tabela de passageiros
    int vlr=0;
    while (vlr != 1)
    {
        printf("\nDigite [1] para voltar: ");
        scanf("%d",&vlr);
    }
}

void intro()
{
    int desejo;
    system("cls");
    crline();
    printf("\tBem vindo ao Terminal da Aero Milhas\n");
    crline();
    printf("\tO que deseja?\n[1] - Adicionar um passageiro\n[2] - Ver lista de passageiros\n[3] - Sair\nResposta: ");
    scanf("%d",&desejo);

    switch (desejo)
    {
    case 1:
        passageiro_add();
        intro();
        break;
    case 2:
        lista_escalas();
        intro();
        break;
    case 3:
        printf("\nVoce escolheu sair.");
        break;
    default:
        //printf("\nEscolha invalida.");
        intro();
        break;
    }
}

int main(int argc, char const *argv[])
{
    intro();
    return 0;
}

/*

O voo de uma empresa aérea possui escalas em cinco cidades: 

- Florianópolis, 

- Curitiba; 

- São Paulo

- Rio de Janeiro,

- Belo Horizonte.

Considerando que para cada passageiro tem-se o seu nome, cidade de origem, 
e cidade de destino, escreva um programa em C, que para cada cidade, 
imprima a lista dos passageiros que a tem como destino. 

*/
