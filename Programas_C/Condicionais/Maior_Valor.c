#include <stdio.h>
#include <stdlib.h>

// maior valor

int main()
{
	int a,b,c,m;
	
	printf("Digite o valor de A: ");
	scanf("%d",&a);
	printf("Digite o valor de B: ");
	scanf("%d",&b);
	printf("Digite o valor de C: ");
	scanf("%d",&c);
	
	if (a > b && a > c){
		m = a;
	}else if (b > a && b > c){
		m = b;
	}else{
		m = c;
	}
	
	printf("O maior valor eh: %d",m);
	return 0;
}
