#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// exercicio funcoes

const int qtd = 3; // quantidade de provas
float nota_provas[qtd];
float nota_temp[qtd];

float calcula_media(float nota, int max)
{
	float res = (nota/max);
	return res;
}

void registra_prova()
{
	for(int i=0;i<qtd;i++){
		float nota;
		printf("Digite a nota da prova %d: ",i+1);
		scanf("%f",&nota);
		nota_provas[i] = nota;
	}
}

void cria_temp_nota()
{
	for(int i=0;i<qtd;i++){
		nota_temp[i] = nota_provas[i];
	}
} 

void organizar_notas()
{
	for(int i=0; i<qtd; i++)
    {
        for(int j=i+1; j<qtd; j++) { if(nota_provas[i]>nota_provas[j])
            {
                float temp = nota_provas[i];
                nota_provas[i] = nota_provas[j];
                nota_provas[j] = temp;
            }
        }
    }
}

float get_nota(int tipo)
{
	float val=0;
	switch(tipo){
		case 1: // pega notas primeiras
			for(int i=(qtd-1);i>(qtd-3);i--){
		    	val = val + nota_provas[i];
			}
			break;
		case 2: // total
			for(int i=0;i<qtd;i++){
				val = val + nota_provas[i];
			}
			break;
		case 3: // parcial
			val = nota_provas[0] + nota_provas[qtd-1];
			break;
	}
	return val;
}

void cria_tabela()
{	
	printf("\nTabela das notas da prova:\n");
	for(int i=0;i<qtd;i++){
		printf(" %.1f",nota_provas[i]);
		if(i!=qtd-1){
			printf(" -");	
		}
	}
	/*
	for(int i=qtd-1;i>=0;i--){
		printf(" %.1f",nota_provas[i]);
		if(i!=0){
			printf(" -");	
		}
	}
	printf("\n*valores decrescentes\n");
	*/
}

int main()
{	
	registra_prova();
	cria_temp_nota();
	organizar_notas();
	
	// soma notas
	float med = get_nota(2); // soma de todas notas
	float par = get_nota(1); // soma das primeiras 2 notas
	float anb = get_nota(3); // soma da primeira e ultima
	
	// calcula media
	float media_total = calcula_media(med,qtd);
	float media_alta = calcula_media(par,2);
	float media_parcial = calcula_media(anb,2);
	
	// imprime media
	printf("\nMedia total: %.2f\nMedia das 2 melhores: %.2f\nMedia da maior com menor: %.2f\n",media_total,media_alta,media_parcial);
	
	// imprime tabela de notas
	cria_tabela();
	
	return 0;
}
