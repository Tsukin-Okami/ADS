#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bf 255 // tamanho máximo do texto

struct T_Carta
{
    int horario[3]; // horas minutos segundos
    int data[3];    // dd/mm/yyyy
    char compromisso[bf];
};

void setCarta(struct T_Carta *c)
{
    printf("Informe o horario no formato [hh mm ss]: ");
    scanf("%d %d %d", &c->horario[0], &c->horario[1], &c->horario[2]);

    printf("Informe a data no formato [dd mm yyyy]: ");
    scanf("%d %d %d", &c->data[0], &c->data[1], &c->data[2]);

    while (getchar() != '\n');

    printf("Descreva o compromisso: ");
    fgets(c->compromisso, bf, stdin);
    strtok(c->compromisso, "\n"); 
}

void Display(struct T_Carta c)
{
    putchar('\n');
    printf("Horario: %d:%d:%d\nData: %d/%d/%d\nCompromisso:\n\t%s\n",
           c.horario[0], c.horario[1], c.horario[2],
           c.data[0], c.data[1], c.data[2],
           c.compromisso);
}

int main()
{
    struct T_Carta c;
    setCarta(&c);
    Display(c);
    return 0;
}
