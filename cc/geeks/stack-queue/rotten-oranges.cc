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
// 0 empty
// 1 fresh orange
 // 2 rotten
int timeToRot(vvi &v, int r, int c){
  int t = 0;
  queue<pair<int, int>> q;
  int dx[] = {0,0,1,-1};
  int dy[] = {-1,1,0,0};
  REP(i,r) REP(j,c) if(v[i][j] == 2) q.push({i,j});

  while (!q.empty()) {
    int qsize = q.size();
    while(qsize--){
      auto it = q.front();
      q.pop();
      REP(i,4){
        int x = dx[i] + it.first;
        int y = dy[i] + it.second;
        if(x < 0 || x >= r || y < 0 || y >= c) continue;
        if(v[x][y] == 1){
          v[x][y] = 2;
          q.push({x,y});
        }
      }
    }
    t++;
  }
  REP(i,r) REP(j,c) if(v[i][j] == 1) return -1;
  return t-1;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int r, c;
    cin >> r >> c;
    vvi v(r, vi (c));
    REP(i,r) REP(j,c) cin >> v[i][j];
    cout << timeToRot(v,r,c) << endl;
  }
  return 0;
}
