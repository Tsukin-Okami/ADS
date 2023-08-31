#include <stdio.h>
#include <stdlib.h>

// Matriz Transposta

#define GRID_XSIZE 4 // Define o tamanho vertical da matriz
#define GRID_YSIZE 3 // Define o tamanho horizontal da matriz

/*	 _ _ _ _ Y
	  |L L L L
3x4	|L L L L
	  |L L L L
  	X
*/

void TranspostarMatriz(const float matriz[][GRID_YSIZE], float matriz_transposta[][GRID_XSIZE]) {
	for (int x=0; x<GRID_XSIZE; x++) {
		for (int y=0; y<GRID_YSIZE; y++) {
			matriz_transposta[y][x] = matriz[x][y];
		}
	}
}

int main()
{
	float mtx[GRID_XSIZE][GRID_YSIZE]; // Matriz padrão
	float mtx_tsp[GRID_YSIZE][GRID_XSIZE]; // Matriz transposta
	
	for (int x=0; x<GRID_XSIZE; x++) {
		for (int y=0; y<GRID_YSIZE; y++) {
			printf("Digite o valor da linha[%d] e da coluna[%d]: ", x+1, y+1);
			scanf("%f", &mtx[x][y]);
		}
	}
	
	TranspostarMatriz(mtx,mtx_tsp);
	
	printf("\nMatrix Padrao:\n");
	
	for (int x=0; x<GRID_XSIZE; x++) {
        for (int y=0; y<GRID_YSIZE; y++) {
            printf("| %.1f\t", mtx[x][y]);
        }
        putchar('\n');
    }
    
	printf("\nMatriz Transposta:\n");
	
	for (int x=0; x<GRID_YSIZE; x++) {
		for (int y=0; y<GRID_XSIZE; y++) {
            printf("| %.1f\t", mtx_tsp[x][y]);
        }
        putchar('\n');
    }
	
	return 0;
}
