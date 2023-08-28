#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* 
    - Modulo de Bibliotecas -
  Tipos inclusos:
> ADS_SORT = organiza vetor numeral em ordem decrescente
> ADS_
*/
#define prefix ADS

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
// --- main --- 
int main()
{
  // intro
  puts("Biblioteca ADSLib Inicializada");
  // chamada
  
  // retorno
  return 0;
}
