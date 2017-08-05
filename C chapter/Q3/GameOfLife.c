#include <stdio.h>

#define SIZE 100

typedef struct Cell{
	int curr_state; //is alive now
	int next_state; //is alive next generation
}Cell;

void print_board(Cell brd[SIZE][SIZE]); //visual print
void kill_all_cells(Cell brd[SIZE][SIZE]); //set board
int count_close_cells(Cell brd[SIZE][SIZE], int x, int y); //count neighbors

void game_loop(Cell brd[SIZE][SIZE]){
	int n_size;
	while (1 == 1){
		for (int i = 0; i < SIZE; i++){
			for (int j = 0; j < SIZE; j++){
				//THE RULES
				n_size = count_close_cells(brd, i, j);

				if (n_size < 2){
					brd[i][j].next_state = 0;
				}
				if (brd[i][j].curr_state == 1 && (n_size == 2 || n_size == 3)){
					brd[i][j].next_state = 1;
				}
				if (brd[i][j].curr_state == 1 && n_size > 3){
					brd[i][j].next_state = 0;
				}
				if (brd[i][j].curr_state == 0 && n_size == 3){
					brd[i][j].next_state = 1;
				}
			}
		}

		//next generation:
		for (int i = 0; i < SIZE; i++){
			for (int j = 0; j < SIZE; j++){
				brd[i][j].curr_state = brd[i][j].next_state;
			}
		}

		print_board(brd);
	}
}

void main(){

	//use this command for fullscreen cmd on windows 8
	//system("mode 800");

	Cell k[SIZE][SIZE]; //The board

	kill_all_cells(k);

	//generate cube
	for (int i = 30; i < 80; i++){
		for (int j = 30; j < 80; j++){
			k[i][j].curr_state = 1;
		}
	}
	
	//generate cube
	for (int i = 10; i < 30; i++){
		for (int j = 10; j < 30; j++){
			k[i][j].curr_state = 1;
		}
	}

	print_board(k);
	game_loop(k);
	system("PAUSE");
}

void print_board(Cell brd[SIZE][SIZE]){
	for (int i = 0; i < SIZE; i++){
		printf("-");
	}
	printf("\n\n");

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if (brd[i][j].curr_state == 1){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}

	for (int i = 0; i < SIZE; i++){
		printf("-");
	}
	printf("\n\n");
}


int count_close_cells(Cell brd[SIZE][SIZE], int x, int y){
	int sum = 0;
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			if (!(i == 0 && j == 0) && (x + i != -1) && (y + j != -1) && (x + i != SIZE) && (y + j != SIZE)){
				sum += brd[x + i][y + j].curr_state;
			}
		}
	}
	return sum;
}

void kill_all_cells(Cell brd[SIZE][SIZE]){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			brd[i][j].curr_state = 0;
			brd[i][j].next_state = 0;
		}
	}
}