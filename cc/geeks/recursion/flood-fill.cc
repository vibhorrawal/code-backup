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

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m, color;
void flood_fill(vvi &v, int x, int y, int k){
  v[x][y] = k;
  REP(i,4){
    int xi = x + dx[i];
    int yi = y + dy[i];
    if(xi < 0 || xi >= n || yi < 0 || yi >= m)
      continue;

    if(v[xi][yi] == color)
      flood_fill(v,xi,yi,k);
  }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    cin >> n >> m;
    vvi v(n, vi(m));
    REP(i,n) REP(j,m) cin >> v[i][j];
    int x, y, k;
    cin >> x >> y >> k;
    color = v[x][y];
    flood_fill(v,x, y, k);
    REP(i,n) {
      REP(j,m){
        cout << v[i][j] << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
