#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// periodo de tempo

int main()
{
    const int s=60,m=60,h=24;
    int segs;
    
    printf("Digite o valor em segundos: ");
    scanf("%d",&segs);
    
    int dia,hora,minuto,segundo;
    segundo = segs % s;
    minuto = (segs/s) % m;
    hora = (segs/(s*m)) % h;
    dia = segs/(s*m*h);
    
    printf("%d segundos equivalem a:\n%d dia(s), %d hora(s), %d minuto(s) e %d segundo(s).",segs,dia,hora,minuto,segundo);
    
    return 0;
}
