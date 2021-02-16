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
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

const int INF = 1e9 + 5;
int n, m;

void display(vvi &dist){
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            if(dist[ii][jj] != INF) cout<<dist[ii][jj]<<' ';
            else cout<<"X ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

inline bool inside(int i, int j){
    return 0 <= i and i < n and 0 <= j and j < m;
}

void solve(){
    cin>>n>>m;
    vector<vector<char>> b(n, vector<char>(m));
    REP(i,n) read(b[i]);
    queue<int> x,y;
    pii S = {-1,-1}, E = {-1,-1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(b[i][j] == 'S') S.first = i, S.second = j;
            if(b[i][j] == 'F') E.first = i, E.second = j;
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[S.first][S.second] = 0;
    x.push(S.first);
    y.push(S.second);
    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};
    while(x.size()){
        int i = x.front(); x.pop();
        int j = y.front(); y.pop();
        if(i == E.first and j == E.second){
            cout << dist[i][j] << endl;
            return;
        }
        db(i,j);
        for (int k = 0; k < 8; k++) {
            db(k);
            for (int cnt = 1; ; cnt++) {
                int dx = dr[k] * cnt + i, dy = dc[k] * cnt + j;
                db(dx,dy);
                if(not inside(dx,dy) or b[dx][dy] == 'X') break;
                // print(dx,dy,n,m);
                if(dist[dx][dy] > dist[i][j] + 1){
                    // db(dx,dy);
                    dist[dx][dy] = 1 + dist[i][j];
                    // display(dist);
                    x.push(dx);
                    y.push(dy);
                }
                else if(dist[dx][dy] == dist[i][j] + 1) continue;
                // else if(dist[dx][dy] == dist[i][j]) continue;
                else break;
            }
        }
    }
    cout << "-1" << endl;
}

/*
void print(int r, int c, int n, int m){
    // return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == r and j == c) cout<<" * ";
            else cout << " - " ;
        }
        cout<<endl;
    }
    cout << "\n" << endl;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> b(n, vector<char>(m));
    REP(i,n) read(b[i]);
    queue<int> x,y;
    pii S = {-1,-1}, E = {-1,-1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(b[i][j] == 'S') S.first = i, S.second = j;
            if(b[i][j] == 'F') E.first = i, E.second = j;
        }
    }
    assert(S.first != -1 and E.first != -1);
    x.push(S.first);
    y.push(S.second);
    vector<vector<int>> vis(n, vector<int>(m));
    vis[S.first][S.second] = 1;
    // print(S.first, S.second, n, m);
    int steps = 1;
    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};
    while(sz(x)){
        int qs = sz(x);
        vi vx,vy;

        while(qs--){
            int r = x.front(); x.pop();
            int c = y.front(); y.pop();
            // if(vis[r][c]) continue;
            // vis[r][c] = 1;
            // cout << "consider" << endl;
            // print(r,c,n,m);
            // cout << "------------------------------" << endl;
            for(int k = 0; k < 8; k++){
                for (int cnt = 1; ; cnt++) {
                    int rr = r + dr[k] * cnt, cc = c + dc[k] * cnt;
                    if(rr < 0 or rr >= n or cc < 0 or cc >= m) break;
                    if(b[rr][cc] == 'X') break;
                    // db(rr,cc,steps);
                    if(rr == E.first and cc == E.second) {
                        cout << steps << endl;
                        return;
                    }

                    // if(vis[rr][cc]) break;
                    if(vis[rr][cc] and vis[rr][cc] < steps)
                        break;

                    if(vis[rr][cc] == steps) continue;
                    // print(rr,cc,n,m);

                    x.push(rr);
                    y.push(cc);
                    vis[rr][cc] = steps;
                    // vx.pb(rr);
                    // vy.pb(cc);
                }

            }

        }
        // for(int i = 0; i < vx.size(); i++) vis[vx[i]][vy[i]] = true;

        steps++;
        db(steps);
    }
    cout << "-1" << endl;
}
*/
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        solve();
    }
    return 0;
}
