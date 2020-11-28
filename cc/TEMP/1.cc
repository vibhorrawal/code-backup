 
#include <bits/stdc++.h>
using namespace std;

void displaySolution(int board[50][50],int n){
	for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
            printf(" %c ", board[i][j]?'X':'-'); 
        printf("\n"); 
    }
    printf("\n\n\n"); 
}

bool isSafe(int board[50][50], int row, int col, int n){
	// check row on left side
	for (int i = 0; i < col; ++i)
		if(board[row][i])
			return false;

	// diagonal check on upper left side
	for (int i=row,j=col; i>=0 && j>=0 ; i--,j--)
		if(board[i][j])
			return false;

	// 	diagonal check on ower left side
	for (int i=row,j=col ; i<n && j>=0 ; i++,j--)
		if(board[i][j])
			return false;

	return true;					
}

bool solveNQ(int board[50][50], int col, int n){
	if(col >= n) 
		return true;

	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if(isSafe(board,i,col,n))
		{
			board[i][col] = 1;

			if(solveNQ(board, col+1,n))
				flag = true;

			if(!flag)
				board[i][col] = 0;
		}
		if(flag) displaySolution(board,n);
				
	}
	if(!flag) 
		return false;
}

int main(int argc, char const *argv[])
{
	int n; 
	scanf("%d", &n); printf("\n\n");
	int board[50][50] = {0};
	if(!solveNQ(board,0,n)) printf("There does not exist a solution for board of size %d\n", n);
	displaySolution(board,n);
	return 0;
}
