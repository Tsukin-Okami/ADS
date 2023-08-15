#include <stdio.h>
#include <stdlib.h>

// exercicio 2 - consoante ou vogal

int main()
{
	char letra;
	
	// entrada
	printf("Digite uma letra: ");
	scanf("%c",&letra);
	
    // se for maiuscula, converte para minuscula
    if ('A' <= letra && letra <= 'Z') {
        letra += 32;
    }
    
    // verifica se eh letra
    if (('a' <= letra && letra <= 'z')) {
        switch(letra) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                printf("Vogal");
                break;
            default:
                printf("Consoante");
        }
    }
    else
    {
    	printf("Indefinido");
	}
	
	return 0;
}
