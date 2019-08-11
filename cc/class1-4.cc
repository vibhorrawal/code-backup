#include<iostream>
using namespace std;
const int N = 4;
void display(int board[N][N]);
bool solve(int board[N][N], int col);
bool check(int board[N][N], int row, int col);
int main(int argc, char const *argv[]){
  int board[N][N] = {0};
  solve(board,0);
  display(board);
  return 0;
}
void display(int board[N][N]){
  for (int i = 0; i < N ; i++) {
    for (int j = 0; j < N ; j++) {
      if(board[i][j])
      cout<<"Queen at ("<<i+1<<", "<<j+1<<")"<<endl;
    }
  }cout<<endl;
}
bool solve(int board[N][N], int col){
  if(col >= N)
    return true;
  for (int i = 0; i < N; i++) {
    if(!check(board,i,col))
    {
      board[i][col] = 1;

      if(solve(board, col+1))
        return true;

      board[i][col] = 0;
    }
  }
  return false;
}

bool check(int board[N][N], int row, int col){
  bool flag = false;
  // for (int i = 0; i <= row; i++) {
  //   if(board[i][col])
  //     flag = true;
  // }
  for (int j = 0; j <= col; j++) {
    if(board[row][j])
      flag = true;
  }
  int i = row, j = col;
  while(i>=0 && j>=0){
    if(board[i][j]){
      flag = true;
      break;
    }
    i--,j--;
  }
  i = row, j = col;
  while(i >= 0 && j < N){
    if(board[i][j]){
      flag = true;
      break;
    }
    i--,j++;
  }
  return flag;
}
