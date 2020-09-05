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

struct point {
  int x;
  int y;

  point(int i, int j){
    x = i, y = j;
  }
};
// 1 - src
// 2 - dest
// 3 - valid
// 0 - invalid
bool is_path(vector<vector<int>> &v){
  int n = v.size();
  //find src and dst
  point src(-1,-1),dst(-1,-1);
  REP(i,n){
    REP(j,n){
      if(v[i][j] == 1)
        src.x = i, src.y = j;

      if(v[i][j] == 2)
        dst.x = i, dst.y = j;
    }
  }
  if(src.x == -1 || dst.y == -1)
    return false;

  // bfs for soln
  queue<point> q;
  q.push(src);

  auto isValid = [&](int x, int y){
    if(x >= n || x < 0 || y >= n || y < 0)
      return false;
    return (bool) v[x][y];
  };

  int x[] = {0,0,1,-1};
  int y[] = {-1,1,0,0};
  while(!q.empty()){
    auto p = q.front();
    q.pop();

    if(p.x == dst.x && p.y == dst.y) return true;

    REP(i,4){
      int xi = p.x + x[i];
      int yi = p.y + y[i];
      if(isValid(xi, yi)){
        q.push({xi, yi});
        v[xi][yi] = false;
      }
    }
  }
  return false;
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    REP(i,n) REP(j,n) cin >> v[i][j];
    cout << is_path(v) << endl;
  }
  return 0;
}
