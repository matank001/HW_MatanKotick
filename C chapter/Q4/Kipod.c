#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define HEIGHT 3
#define WIDTH 4
#define FILE_NAME "grid.txt"

int calculate_min_path(int path[HEIGHT][WIDTH], int x, int y);
int min_num(int num1, int num2);
void file_to_arr(FILE* f_read, int arr[HEIGHT][WIDTH]);

int dict[HEIGHT][WIDTH]; //used by calculate_min_path

void main(){

	//set dictionary
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++){
			dict[i][j] = -1;
		}
	}

	int path[HEIGHT][WIDTH] = { 0 };
	int x = 0;
	int y = 0;
	
	FILE* f;
	f = fopen(FILE_NAME, "r");
	file_to_arr(f, path);
	fclose(f);

	printf("Min weight: %d\n", calculate_min_path(path, 0, 0) - path[0][0]);
	system("PAUSE");
}

int calculate_min_path(int path[HEIGHT][WIDTH], int y, int x){
	if (x == WIDTH - 1 && y == HEIGHT - 1){
		return 0;
	}
	if (dict[y][x] != -1){
		return dict[y][x];
	}

	int curr = path[y][x];

	if (x == WIDTH - 1){
		return curr + calculate_min_path(path, y + 1, x);
	}
	if (y == HEIGHT - 1){
		return curr + calculate_min_path(path, y, x + 1);
	}

	int right = calculate_min_path(path, y, x + 1);
	dict[y][x + 1] = right;

	int down = calculate_min_path(path,  y + 1, x);
	dict[y + 1][x] = down;

	return curr + min(right,down);
}

int min_num(int num1, int num2){
	return (num1 < num2) ? num1 : num2;
}

void file_to_arr(FILE* f_read, int arr[HEIGHT][WIDTH]){
	char buffer[256];
	int c;

	int buf_cnt = 0;

	int x_cnt = 0;
	int y_cnt = 0;

	if (f_read){
		while ((c = getc(f_read)) != EOF){
			if (c == ' '){
				buffer[buf_cnt] = 0;
				buf_cnt = 0;
				arr[y_cnt][x_cnt] = atoi(buffer);
				x_cnt += 1;
			}
			else if (c == '\n'){
				buffer[buf_cnt] = 0;
				buf_cnt = 0;
				arr[y_cnt][x_cnt] = atoi(buffer);
				x_cnt = 0;
				y_cnt += 1;
			}
			else{
				buffer[buf_cnt] = c;
				buf_cnt++;
			}
		}
	}
}