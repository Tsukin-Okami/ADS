#include <stdio.h>
#include <stdlib.h>

// imposto de renda

int main(int argc, char const *argv[])
{
    const int Renda_Baixa=10000, Renda_Alta=25000; // fatores constantes
    float renda,final; // valores de entrada
    int aliquota,deducao; // fatores diferenciais

    // entradas
    printf("Digite a renda anual: R$");
    scanf("%f",&renda);

    // checagem de renda
    if(renda <= Renda_Baixa)
    {
        aliquota = 0;
        deducao = 0;
    }
    else if (renda <= Renda_Alta)
    {
        aliquota = 10;
        deducao = 1000;
    }
    else
    {
        aliquota = 25;
        deducao = 4750;
    }
    
    // calculo do imposto
    final = (renda - (renda * aliquota/100)) - deducao;

    // final
    printf("O imposto de renda eh: R$%.2f",final);
    return 0;
}
