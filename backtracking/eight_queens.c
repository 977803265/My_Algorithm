/*
 * eight queens implementations using backtracking strategy
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool configure_helper(int** board, int size,int  row);
bool will_attack(int** board, int size, int row, int col);
void 
configure(int** board, int size) {
	int row = 0;
	configure_helper(board, size, row);
}

bool 
configure_helper(int** board, int size, int  row) {
	int col;

	if (row >= size) {
		return true;
	}

	for (col = 0; col < size; col++) {
		if (!will_attack(board, size, row, col)) {
			board[row][col] = 1;
			if (configure_helper(board, size, row+1)) {
				return true;
			}
			board[row][col] = 0;
		}
	}

	return false;
}

bool 
will_attack(int** board, int size, int row, int col) {
	int i, j;
	
	// check up vertical line
	for (i = row; i >= 0; i--) {
		if (board[i][col] != 0) {
			return true;
		}
	}
	// check up left diag line
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] != 0) {
			return true;
		}
	}

	// check up right diag line
	for (i = row, j = col; i >=0 && j < size; i--, j++) {
		if (board[i][j] != 0) {
			return true;
		}
	}
	return false;
}
void
print_maze(int** board, int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("  %d", board[i][j]);
		}
		printf("\n");
	}
}
int main() {
	const int size = 4;
	int i, j;
	int** board = (int**)malloc(sizeof(int*) * size);

	for (i = 0; i < size; i++) {
		board[i] = (int*)malloc(sizeof(int) * size);
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	}
	configure(board, size);
	print_maze(board, size);
	return 0;
}
