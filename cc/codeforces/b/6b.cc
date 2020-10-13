#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

void fun(){
  int n, m;
  cin>>n>>m;
  char pres; cin>>pres;
  vector<vector<char>> room(n, vector<char>(m));
  REP(i,n) REP(j,m) cin>>room[i][j];
  set<char> deputy;
  int x[] = {0,0,-1,1};
  int y[] = {1,-1,0,0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for(int k = 0; k < 4; k++){
        int xi = i + x[k];
        int yi = j + y[k];
        if(xi < 0 || xi >= n || yi < 0 || yi >= m) continue;
        if(room[i][j] == pres && room[xi][yi] != '.' && room[xi][yi] != pres)
          deputy.insert(room[xi][yi]);
      }
    }
  }
  cout << deputy.size() << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  fun();
  return 0;
}
