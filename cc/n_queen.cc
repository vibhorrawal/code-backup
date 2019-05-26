#define N 8
#include <bits/stdc++.h>
using namespace std;
int counter = 0;
void displaySolution(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool solveNQ(int board[N][N], int col);

int main(int argc, char const *argv[])
{
	// scanf("%d", &N);
	int board[N][N] = {0};
	solveNQ(board,0); //printf("There does not exist a solution for board of size %d\n", N);
	// displaySolution(board);
	printf("Total number of solutions: %d\n", counter);
	return 0;
}

void displaySolution(int board[N][N]){
	for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %c ", board[i][j]?'X':'-'); 
        printf("\n"); 
    }
    printf("\n\n\n"); 
}

bool isSafe(int board[N][N], int row, int col){
	// check row on left side
	for (int i = 0; i < col; ++i)
		if(board[row][i])
			return false;

	// diagonal check on upper left side
	for (int i=row,j=col; i>=0 && j>=0 ; i--,j--)
		if(board[i][j])
			return false;

	// 	diagonal check on lower left side
	for (int i=row,j=col ; i<N && j>=0 ; i++,j--)
		if(board[i][j])
			return false;

	return true;					
}

bool solveNQ(int board[N][N], int col){
	if(col >= N){
		displaySolution(board); 
		counter++;
		return false;
	}

	for (int i = 0; i < N; ++i)
	{
		if(isSafe(board,i,col))
		{
			board[i][col] = 1;

			if(solveNQ(board, col+1))
				return true;

			board[i][col] = 0;
		}
	}

	return false;
}