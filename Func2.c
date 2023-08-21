#include <stdlib.h>
#include <stdio.h>

// exercicio funcoes 2 - sucessor de 100 e antecessor de 0

int sucessor(int inicio)
{
    int res=inicio;
    for(int i=inicio+1;i<=100;i++){
        res = res + i;
    }
    return res;
}

int antecessor(int inicio)
{
    int res=inicio;
    for(int i=inicio-1;i>=0;i--){
        res = res + i;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int vlr,soma_sr,soma_ar;

    printf("Digite um valor entre 0 a 100: ");
    scanf("%d",&vlr);

    if (vlr > 100 || vlr < 0)
    {
        printf("Valor invalido.");
        return 0;
    }

    soma_sr = sucessor(vlr);
    soma_ar = antecessor(vlr);

    printf("A soma dos sucessores de %d a 100 eh: %d\n",vlr,soma_sr);
    printf("A soma dos antecessores de %d a 0 eh: %d",vlr,soma_ar);

    return 0;
}
