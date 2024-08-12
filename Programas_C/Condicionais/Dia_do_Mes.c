#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// dias do mes - mes do ano

int main()
{
    int ano,mes,dia=0;
    printf("Digite o ano: ");
    scanf("%d",&ano);
    printf("Digite o mes: ");
    scanf("%d",&mes);
    
    // calculate the leap year
    bool bissexto = (ano % 4 == 0) && (ano % 100 != 0) || (ano % 400 == 0);

    // check the month
    if(mes<1 || mes>12){
        printf("%d nao eh um mes.",mes);
    }
    else if(mes == 2){
        dia = 28;
        if(bissexto){
            dia++;
        }
    }
    else if(mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        dia = 31;
    }
    else{
        dia = 30;
    }
    
    // print
    if(dia>1){
        printf("O mes %d do ano de %d tem %d dias.",mes,ano,dia);
    }
    return 0;
}
