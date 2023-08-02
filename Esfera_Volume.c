#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// volume da esfera

#define pi 3.14159

int main()
{
    float raio, volume;

    printf("Digite o valor do raio: ");
    scanf("%f", &raio); 

    volume = (4*(pi*pow(raio,3)))/3;

    printf("O volume da sua esfera eh: %f", volume);
    
    return 0;
}
