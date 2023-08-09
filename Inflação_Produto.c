#include <stdio.h>
#include <stdlib.h>

// inflacao do produto

int main()
{
	float t4_p1, t4_p2, t4_p3; // produto mes 4
	float t5_p1, t5_p2, t5_p3; // produto mes 5
	float inf_1, inf_2, inf_3; // inflacao
	
	// mes de abril
	printf("Digite o valor do produto 1 no periodo de Abril: R$");
	scanf("%f",&t4_p1);
	printf("Digite o valor do produto 2 no periodo de Abril: R$");
	scanf("%f",&t4_p2);
	printf("Digite o valor do produto 3 no periodo de Abril: R$");
	scanf("%f",&t4_p3);
	
	// mes de maio
	printf("Digite o valor do produto 1 no periodo de Maio: R$");
	scanf("%f",&t5_p1);
	printf("Digite o valor do produto 2 no periodo de Maio: R$");
	scanf("%f",&t5_p2);
	printf("Digite o valor do produto 3 no periodo de Maio: R$");
	scanf("%f",&t5_p3);
	
	// calculo
	inf_1 = ((t5_p1-t4_p1)/t4_p1)*100;
	inf_2 = ((t5_p2-t4_p2)/t4_p2)*100;
	inf_3 = ((t5_p3-t4_p3)/t4_p3)*100;
	
	printf("\nDetalhes:\n");
	printf("	N | ABRIL	| MAIO		| INFLACAO\n");
	printf("	1 | R$%.2f	| R$%.2f	| %.1f%%\n",t4_p1,t5_p1,inf_1);
	printf("	2 | R$%.2f	| R$%.2f	| %.1f%%\n",t4_p2,t5_p2,inf_2);
	printf("	3 | R$%.2f	| R$%.2f	| %.1f%%\n",t4_p3,t5_p3,inf_3);
	
	return 0;
}
