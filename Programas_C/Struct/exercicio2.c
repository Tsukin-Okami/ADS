#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bf 255 // tamanho máximo do texto

struct T_Dados
{
    char nome[bf];
    int idade;
    char endereco[bf];
};

void setCarta(struct T_Dados *c)
{
    printf("informe seu nome: ");
    fgets(c->nome, bf, stdin);
    strtok(c->nome, "\n");
    
    printf("Informe a sua idade: ");
    scanf("%d", &c->idade);

    while (getchar() != '\n');
	
    printf("informe seu endereco: ");
    fgets(c->endereco, bf, stdin);
    strtok(c->endereco, "\n"); 
}

void Display(struct T_Dados c)
{
    putchar('\n');
    printf("nome: %s\nidade: %d\nendereco: %s\n",
           c.nome,
           c.idade,
           c.endereco);
}

int main()
{
    struct T_Dados c;
    setCarta(&c);
    Display(c);
    return 0;
}
