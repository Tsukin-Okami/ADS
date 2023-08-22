#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// exercicio 1

#define bf_line 60
#define bf_escala 40
#define bf_nome 20
#define bf_origin 40
#define bf_goto 40

// cidades disponiveis
#define cidades 5
char Escalas[cidades][bf_escala] = {
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

void extract_ASCII(char v[]){
    printf("ASCII: ");
    for (int i=0;v[i]!='\0';i++)
    {
        printf("\\%d",v[i]);
    }
    printf("\n");
}

// espaco ocupado pelo vetor
int get_fillers(){
    int filled=0;
    //puts("\nchecking fillers...");
    for(int i=0;vGoto[i][0]!='\0';i++){
        filled += 1;
        //printf("for func_fill: %d - [%d]\n",filled,vNome[i][0]);
    }
    //printf("fillers encountered: %d\n",filled);
    return filled;
}

void limpa_substring(int tipo, int z)
{
    /*  
        remove line feed* que pode ser criado apos inserir uma entrada
        motivo: entra em conflito ao comparar strings

        *comumente relacionado com '\n' ou em ASCII '\10'
    */

    char find = 10;
    char replace = '\0';

    switch (tipo)
    {
    case 1: // vnome
        for(int y=0;vNome[z][y] != '\0';y++){
            if(vNome[z][y] == find){
                vNome[z][y] = replace;
            }
        }
        break;
    case 2: // vorigin
        for(int y=0;vOrigin[z][y] != '\0';y++){
            if(vOrigin[z][y] == find){
                vOrigin[z][y] = replace;
            }
        }
        break; 
    case 3: // vgoto
        //puts("before:");
        //extract_ASCII(vGoto[z]);
        for(int y=0;vGoto[z][y] != '\0';y++){
            if(vGoto[z][y] == find){
                //puts("finded \\10 in string :: replacing");
                vGoto[z][y] = replace;
            }
        }
        //puts("after:");
        //extract_ASCII(vGoto[z]);
        break;
    default:
        break;
    }
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
        scanf("%s%*c",&vNome[fill+i]); // usar fgets pula esse e o proximo fgets

        printf("Digite a cidade de origem do passageiro[%d]: ",i+1);
        /*
        scanf("%s",&vOrigin[fill+i]); 
        fgets(vOrigin[fill+i],bf_origin, stdin);
        */
        fgets(vOrigin[fill+i],bf_origin, stdin);

        printf("Digite a cidade de destino do passageiro[%d]: ",i+1);
        fgets(vGoto[fill+i],bf_goto, stdin);

        /*limpa_substring(1,fill+i);
        limpa_substring(2,fill+i);
        limpa_substring(3,fill+i);*/
        //printf("\nArmazenado:\n\tNome: %s\n\tOrigem: %s\n\tDestino: %s\n",vNome[fill+i],vOrigin[fill+i],vGoto[fill+i]);
    }
}

void lista_escalas()
{
    printf("\n");

    for(int i=0;i<cidades;i++){ // mostra todas as cidades disponiveis
        int ind=0, fill=get_fillers();
        printf("Passageiros de %s:\n",Escalas[i]); // mostra as info dos passageiros de acordo com a cidade
        for(int x=0;x<fill;x++){
            // necessario ao comparar strings
            limpa_substring(1,x);
            limpa_substring(2,x);
            limpa_substring(3,x);
            // compara o destino do passageiro com a cidade
            if(strcmp(vGoto[x],Escalas[i]) == 0){
                ind++; // indice da tabela do passageiro
                printf("\t[%d] --------------------\n\t\tNome: %s\n\t\tOrigem: %s\n\t\tDestino: %s\n",ind,vNome[x],vOrigin[x],vGoto[x]); // imprime tabela do passageiro
            }/*
            else{ // apenas para teste
                printf("\t COMPARE >> %s :: %s << %d\n",vGoto[x],Escalas[i],strcmp(vGoto[x],Escalas[i]));
                extract_ASCII(vGoto[x]);
                extract_ASCII(Escalas[i]);
            }*/
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
    int desejo=0;
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
