#include <stdlib.h>
#include <stdio.h>

// PLAYER ZONE
#define WIDTH 5
#define HEIGHT 5 

// MAP ZONE
#define MW 21 // Largura
#define MH 9 // Altura

#define MAXMATERIALS 10
#define CL '/'

// player position
int plr_pos[2] = {2,2};

/*    
	STONE-0 | GRASS-1 | POINTS-2 | VOID-3 | PLAYER-4
	
*/
const char mat[MAXMATERIALS] = {'.','~','*','#','+'};

const int map[MH][MW] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0 },
	{ 0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,1,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0 },
};

char matrix[HEIGHT][WIDTH];

// auxiliary functions

void clear()
{
	system("cls");
}

void line()
{
	for(int i=0;i<30;i++){
		putchar(CL);
	}
	putchar('\n');
}

void reset()
{
	for(int x=0;x<HEIGHT;x++){
		for(int y=0;y<WIDTH;y++){
			if(map[x][y] < 0 || map[x][y] > MAXMATERIALS ){
				matrix[x][y] = mat[3];
			}
			else{
				matrix[x][y] = mat[map[x][y]];
			}
		}
	}
	matrix[plr_pos[0]][plr_pos[1]] = mat[4];
}

// controls

void up()
{
	plr_pos[0]++;
	int x = plr_pos[0]-2, y = plr_pos[1]-2;
	for(x;x<)
}

void down()
{
	
}

void left()
{
	
}

void right()
{
	
}

// main

void window()
{
	for(int x=0;x<HEIGHT;x++){
		for(int y=0;y<WIDTH;y++){
			putchar(matrix[x][y]);
		}
		putchar('\n');
	}
	char key;
	scanf(" %c",&key);
	clear();
	switch(key){
		case 'w':
			up();
			break;
		case 's':
			down();
			break;
		case 'a':
			left();
			break;
		case 'd':
			right();
			break;
		default:
			puts("\nERROR\n");
			return;
			break;
	}
	window();
}

int main()
{
	int n;
	line();
	printf("\n\tWelcome to Survivor!\n\nPress 1 to start!\n");
	line();
	scanf("%d",&n);
	
	if(n==1){
		clear();
		reset();
		window();
	}
	
	return 0;
}
