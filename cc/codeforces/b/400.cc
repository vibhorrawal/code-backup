#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,m;
  cin>>n>>m;
  vector<vector<char>> matrix(n,vector<char>(m));
  REP(i,n) REP(j,m) cin>>matrix[i][j];
  set<int> moves;
  for(int i = 0; i < n; i++){
    int count = 0, j;
    for(j = 0; j < m; j++){
      if(matrix[i][j] == 'G')
        break;
    }
    int start = j;
    for(j;j < m; j++){
      if(matrix[i][j] == 'S')
        break;
    }
    db(start);db(j);db(m);
    count = j - start + 1;
    if(j == m){
      cout << "-1" << endl;
      exit(0);
    }
    moves.insert(count);
  }
  cout << moves.size() << endl;
  return 0;
}
