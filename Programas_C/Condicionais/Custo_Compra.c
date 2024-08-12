#include <stdio.h>
#include <stdlib.h>

// custo compra

int main()
{
	int q_p1, q_p2, q_p3; // quantidade dos produtos
	float p_p1, p_p2, p_p3; // valor unitario
	float qv1, qv2, qv3; // valor total
	
	printf("Digite quantos quilos de cafe comprados: ");
	scanf("%d",&q_p1);
	printf("Digite o valor unitario do(a) cafe: ");
	scanf("%f",&p_p1);
	
	printf("Digite quantos litros de leite comprados: ");
	scanf("%d",&q_p2);
	printf("Digite o valor unitario do(a) leite: ");
	scanf("%f",&p_p2);
	
	printf("Digite quantos quilos de banana comprados: ");
	scanf("%d",&q_p3);
	printf("Digite o valor unitario do(a) banana: ");
	scanf("%f",&p_p3);
	
	qv1 = (q_p1 * p_p1);
	qv2 = (q_p2 * p_p2);
	qv3 = (q_p3 * p_p3);
	
	printf("\nDetalhes:\n");
	printf("Produto	| QTD	| UNIT		| TOTAL\n");
	printf("Cafe	| %d	| R$%.2f	| R$%.2f\n",q_p1,p_p1,qv1);
	printf("Leite	| %d	| R$%.2f	| R$%.2f\n",q_p2,p_p2,qv2);
	printf("Banana	| %d	| R$%.2f	| R$%.2f\n",q_p3,p_p3,qv3);
	printf("\nValor total gasto: R$%.2f",qv1+qv2+qv3);
	
	return 0;
}
