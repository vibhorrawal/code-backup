#include<bits/stdc++.h>
using namespace std;

// const bool false = false;
long long int n,m;
bool * grid;

void solve(){
  int row[n];
  int column[m];
  int count;
  //counting max in every row
  for (int i = 0; i < n; i++) {
    count = 0;
    for (int j = 0; j < m; j++) {
      if(!grid[i*n + j]) count++;
    }
    row[i] = count;
  }
  cout<<"row: "; for(int i = 0; i < n ; i++){ cout<<row[i]<<' ';}cout<<endl;
  //counting column
  for (int i = 0; i < n; i++) {
    count = 0;
    for (int j = 0; j < m; j++) {
      if(!grid[i*m + j])
       count++;
    }
    column[i] = count;
  }
  cout<<"col: "; for(int i = 0; i < m ; i++){ cout<<column[i]<<' ';}cout<<endl;
  int min = INT_MAX;
  for (int i = 0; i < n; i++){
    if(row[i] < min)
      min = row[i];
  }

  cout<<min<<endl;
  int ans = min;

  min = INT_MAX;
  for (int i = 0; i < m; i++){
    if(column[i] < min)
      min = column[i];
  }

  cout<<min<<endl;

  cout<<"ans: "<< (ans + min) <<endl;
}
int main(int argc, char const *argv[]){
  int t;
  char ch;
  cin>>t;
  while(t--){
    cin>>n>>m;
    grid = new bool[n*m];
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cin>>ch;
        if(ch == '\n') cin>>ch;
        grid[i*m + j] = (ch == '*') ? 1 : 0;
      }
    }
    cout<<endl;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++)
        cout<<grid[i*m + j];
        cout<<endl;
      }
    solve();
  }
  // cout<<endl;
  // for (int i = 0; i < n; i++){
  //   for (int j = 0; j < m; j++)
  //     cout<<grid[i*n + j];
  //     cout<<endl;
  //   }
  return 0;
}
