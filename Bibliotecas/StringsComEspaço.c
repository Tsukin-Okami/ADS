#include <stdio.h>
#include <stdlib.h>

#define max 40

int main()
{
	char texto[max];
	
	puts("Digite um texto:");
	fgets(texto,max,stdin);
	
	puts(texto);
	putchar('\a');
	return 0;
}
