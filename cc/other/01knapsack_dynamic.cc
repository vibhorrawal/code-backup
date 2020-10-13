#include<iostream>
using namespace std;

int max_value(int v[], int w[], int n, int W){
  int table[n+1][W+1];
  for (int i = 0; i <= W ; i++) {
    table[0][i] = 0; // first row is zero as with taking zero elememts value is 0
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= W; j++) {
      if(w[i] > j) // weight is more than permitted
        table[i][j] = table[i-1][j];
      else
        table[i][j] = max(table[i-1][j], table[i-1][j-w[i]] + v[i]);
    }
  }

  // cout<<"Table:\n";
  // for (int i = 0; i < n+1; i++) {
  //   for (int j = 0; j < W+1; j++) {
  //     cout<<table[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  return table[n][W];
}
int main(int argc, char const *argv[]){
  int v[] = {5,10,3,2,3};
  int w[] = {4,8,3,5,2};
  int W = 10;
  int n = sizeof(v)/sizeof(v[0]);
  cout<<"Max possible value is "<<max_value(v,w,n,W);
  return 0;
}
