#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define endl char(10)
#define pb emplace_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

void solve(vector<string> &s, int n, int m){
    const int INF = 1e9 + 5;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    vvi dist(n, vi(m, INF));
    queue<int> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if(s[i][j] == '1') {
            dist[i][j] = 0;
            // q.push({i, j});
            q.push(i);
            q.push(j);
        }
      }
    }
    int cnt = 0;
    while(q.size()){
        // auto it = q.front(); q.pop();
        // int x = it.first, y = it.second;
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int xi = dx[i] + x, yi  = dy[i] + y;
            if(xi < 0 or yi < 0 or xi >= n or yi >= m) continue;
            if(dist[x][y] + 1 >= dist[xi][yi]) continue;
            dist[xi][yi] = dist[x][y] + 1;
            // if(vis[xi][yi]) continue;
            // q.push({xi, yi});
            q.push(xi);
            q.push(yi);
        }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << dist[i][j] << ' ';
      }
      cout << '\n';
    }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  vector<string> s(200);
  T(){
      int n, m;
      cin >> n >> m;
      // vector<vector<char>> s(n, vector<char>(m));
      REP(i, n) cin>>s[i];
      solve(s, n, m);
  }
  return 0;
}
