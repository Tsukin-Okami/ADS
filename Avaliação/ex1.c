#include <stdlib.h>
#include <stdio.h>

int main() {
	int num,num2, fatorial;

	fatorial = 1;
	
	printf("Digite um valor inteiro positivo: ");
	scanf("%d", &num);
	
	num2 = num;
	
	for(num; num>0; num--){
		fatorial *= num;
	}
	
	printf("Valor do fatorial de %d: %d", num2, fatorial);
	return 0;
}
