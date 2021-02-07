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
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

void print(vector<vector<char>> &v){
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

struct P {
    int first, second, third;
};

int32_t main(int argc, char const *argv[]){
    fastIO;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<char>> v(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>v[i][j];
        }
    }
    // print(v);
    vector<vector<int>> vis(n, vector<int> (m));
    priority_queue<vector<int>> pq;
    REP(i, k){
        int r, c, d;
        cin>>r>>c>>d;
        pq.push({d-1, r-1, c-1});
        v[r-1][c-1] = '*';
    }
    while(pq.size()){
        auto it = pq.top(); pq.pop();
        int d = it[0], r = it[1], c = it[2];
        if(vis[r][c]) continue;
        if(d < 0) continue;
        vis[r][c] = true;
        v[r][c] = '*';
        for(int i = 0; i < 4; i++){
            int x = r + dx[i], y = c + dy[i];
            if(x < 0 or x >= n or y < 0 or y >= m) continue;
            if(v[x][y] == '#') continue;
            if(vis[x][y]) continue;
            pq.push({d-1, x, y});
            v[x][y] = '*';
        }
    }
    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(v[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if(v[i][j] == 'E'){
                ex = i;
                ey = j;
            }
        }
    }
    if(sx == -1 or ex == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    queue<int> x, y;
    x.push(sx);
    y.push(sy);
    int ans = 0;
    vector<vector<bool>> visi(n, vector<bool> (m));
    while(x.size()){
        int sz = x.size();
        while(sz--){
            int r = x.front(); x.pop();
            int c = y.front(); y.pop();
            if(r == ex and c == ey){
                cout << ans;
                return 0;
            }
            if(visi[r][c]) continue;
            visi[r][c] = true;
            for(int i = 0; i < 4; i++){
                int ri = r + dx[i], ci = c + dy[i];
                if(ri < 0 or ci < 0 or ri >= n or ci >= m) continue;
                if(v[ri][ci] == '#' or v[ri][ci] == '*') continue;
                if(visi[ri][ci]) continue;
                x.push(ri);
                y.push(ci);
            }
        }
        ans++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
