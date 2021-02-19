#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<pii>> vvp;
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

void dfs(int u, vi &vis, vi &res, vvi &g){
    if(vis[u]) return;
    vis[u] = true;
    for(int v : g[u]){
        if(not vis[v]) dfs(v, vis, res, g);
    }
    res.pb(u);
}
vi topsort(vvi &g){
    vi res, vis(sz(g));
    for (int i = 0; i < sz(g); i++) {
        if(not vis[i]) dfs(i, vis, res, g);
    }
    reverse(all(res));
    return res;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    while(true){
        int n, m;
        cin>>n>>m;
        if(m+n == 0) break;
        vvi g(n);
        REP(i,m){
            int a, b;
            cin>>a>>b;
            g[a-1].pb(b-1);
        }
        vi v = topsort(g);
        for (int i = 0; i < n; i++) {
            cout<<v[i]+1<<' ';
        }
        cout << endl;
    }
    return 0;
}
