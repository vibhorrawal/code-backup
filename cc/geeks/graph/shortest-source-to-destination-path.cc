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

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
struct pi{
  int x;
  int y;
  int dist;
};

int shortest(vector<vector<int>> &v, int X, int Y){
  int n = v.size();
  int m = v[0].size();

  queue<pi> q;
  if(!v[0][0] || !v[X][Y])
    return -1;

  q.push({0,0,0});
  while(!q.empty()){
    auto t = q.front();
    q.pop();

    if(t.x == X && t.y == Y)
      return t.dist;

    if(t.x < n-1 && v[t.x+1][t.y]) q.push({t.x+1, t.y, t.dist + 1}), v[t.x+1][t.y]=0;
    if(t.y < m-1 && v[t.x][t.y+1]) q.push({t.x, t.y+1, t.dist + 1}), v[t.x][t.y+1]=0;
    if(t.y > 0 && v[t.x][t.y-1]) q.push({t.x, t.y-1, t.dist + 1}), v[t.x][t.y-1]=0;
    if(t.x > 0 && v[t.x-1][t.y]) q.push({t.x-1, t.y, t.dist + 1}), v[t.x-1][t.y]=0;
  }
  return -1;
}

int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    REP(i,n) REP(j,m) cin>>v[i][j];
    int x,y;
    cin>> x >> y;
    cout << shortest(v, x, y) << endl;
  }
  return 0;
}
