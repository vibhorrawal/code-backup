// n_queen
#include <bits/stdc++.h>
using namespace std;

void displaySolution(int N, int** board);
bool isSafe(int N, int** board, int row, int col);
bool solveNQ(int N, int** board, int col);

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int** board = new int*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new int [N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board[i][j] = 0;
	if(!solveNQ(N,board,0)) printf("There does not exist a solution for board of size %d\n", N);
	displaySolution(N,board);
	return 0;
}

void displaySolution(int N, int** board){
	for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %c ", board[i][j]?'X':'-'); 
        printf("\n"); 
    } 
}

bool isSafe(int N, int** board, int row, int col){
	// check row on left side
	for (int i = 0; i < col; ++i)
		if(board[row][i])
			return false;

	// diagonal check on upper left side
	for (int i=row,j=col; i>=0 && j>=0 ; i--,j--)
		if(board[i][j])
			return false;

	// 	diagonal check on ower left side
	for (int i=row,j=col ; i<N && j>=0 ; i++,j--)
		if(board[i][j])
			return false;

	return true;					
}

bool solveNQ(int N, int** board, int col){
	if(col >= N) 
		return true;

	for (int i = 0; i < N; ++i)
	{
		if(isSafe(N,board,i,col))
		{
			board[i][col] = 1;

			if(solveNQ(N,board, col+1))
				return true;

			board[i][col] = 0;
		}
	}

	return false;
}