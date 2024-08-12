#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// calculadora

// VARIAVEIS

const int max = 50;
const char line = '/';

float aa,bb;
int op;

// DEFINE OPERADORES

char tipos[7][16] = {"Adicao","Subtracao","Multiplicacao","Divisao","Potenciacao","Radiciacao","Func. Inversa"};

// CRIA LINHA

void crline(char c, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%c",c);
	}
	printf("\n");
}

// TIPOS DE OPERACAO

float soma(float a, float b)
{
	return (a+b);
}

float sub(float a, float b)
{
	return (a-b);
}

float mult(float a, float b)
{
	return (a*b);
}

float div(float a, float b)
{
	return (a/b);
}

float rad(float a)
{
	return (sqrt(a));
}

float revf(float a)
{
	return (1/a);
}

// FUNCAO INICIAL

void operacao()
{
	float res;
	int isSimple=0,isMid=0;
	switch(op)
	{
		case 1:
			res = soma(aa,bb);
			isSimple = 1;
			break;
		case 2:
			res = sub(aa,bb);
			isSimple = 1;
			break;
		case 3:
			res = mult(aa,bb);
			isSimple = 1;
			break;
		case 4:
			res = div(aa,bb);
			isMid = 1;
			break;
		case 5:
			res = pow(aa,bb);
			isSimple = 1;
			break;
		case 6:
			res = rad(aa);
			isMid = 1;
			break;
		case 7:
			res = revf(aa);
			break;
	}
	if(isSimple){
		printf("O resultado eh: %.1f",res);
	}
	else if(isMid){
		printf("O resultado eh: %.4f",res);
	}
	else{
		printf("O resultado eh: %.12f",res);
	}
}

void escolha()
{
	//crline(line,max);
	printf("Escolha o tipo de operacao:\n");
	for(int i=0;i<7;i++)
	{
		printf("[%d] - %s\n",i+1,tipos[i]);
	}
	printf("\nTipo de operacao: ");
	scanf("%d",&op);
}

void entrada()
{
	if(op == 6 || op == 7){
		printf("\nDigite o valor A: ");
		scanf("%f",&aa);
		printf("\n");
	}
	else
	{
		printf("\nDigite o valor A: ");
		scanf("%f",&aa);
		printf("Digite o valor B: ");
		scanf("%f",&bb);
		printf("\n");
	}
}

void intro()
{
	crline(line,max);
	printf("	Calculadora\n");
	crline(line,max);
}

int main()
{
	intro();
	escolha();
	entrada();
	operacao();
	return 0;
}
