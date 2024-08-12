#include <stdio.h>
#include <stdlib.h>

// determinar par

int main()
{
    int num;
    
    printf("Digite um numero: ");
    scanf("%d",&num);
    
    printf("O numero %d %s par.",num,((num%2 == 0) ? "eh" : "nao eh"));
    return 0;
}
