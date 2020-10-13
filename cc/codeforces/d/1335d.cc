#include<bits/stdc++.h>
using namespace std;

int sudoku[9][9];
int main(int argc, char const *argv[]){
  int t;
  cin>>t;
  while(t--){
    char l;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cin>>l;
        sudoku[i][j] = l - '0';
      }
    }
    l = sudoku[0][0];
    sudoku[0][0] = sudoku[1][3];
    sudoku[1][3] = sudoku[3][6];
    sudoku[2][6] = sudoku[3][1];
    sudoku[3][1] = sudoku[4][4];
    sudoku[4][4] = sudoku[5][7];
    sudoku[5][7] = sudoku[6][2];
    sudoku[6][2] = sudoku[7][5];
    sudoku[7][5] = sudoku[8][8];
    sudoku[8][8] = l;

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        // cin>>l;
        cout<<sudoku[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
