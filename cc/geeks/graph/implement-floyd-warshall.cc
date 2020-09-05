#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
const int INF = 1e7;
void clr(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void floyd(vector<vector<int>> &grid){
  int v = grid.size();

  for (int k = 0; k < v; k++) {
    for (int i = 0; i < v; i++) {
      for (int j = 0; j < v; j++) {
        if(grid[i][k] + grid[k][j] < grid[i][j])
          grid[i][j] = grid[i][k] + grid[k][j];
      }
    }
  }
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int v;
    cin >> v;
    string t;
    vector<vector<int>> grid(v, vector<int> (v));
    REP(i, v) REP(j, v){
      cin >> t;
      if(t == "INF")
        grid[i][j] = INF;
      else
        grid[i][j] = stoi(t);
    }
    floyd(grid);
    REP(i,v){
      REP(j,v){
        if(grid[i][j] == INF)
          cout << "INF" << ' ';
        else
          cout << grid[i][j] << ' ';
      }
      cout<<endl;
    }

  }
  return 0;
}
