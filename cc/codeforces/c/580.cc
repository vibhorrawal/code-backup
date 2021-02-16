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

ll ans;
vi cat;

// mg is globally m
void dfs(int u, int p, int m, vvi &g, int mg){
    if(cat[u]) m--;
    else m = mg;
    if(m < 0) return;
    db(u, m);
    bool is_leaf = true;
    for(int v : g[u]){
        if(v == p) continue;
        is_leaf = false;
        dfs(v, u, m, g, mg);
    }
    if(is_leaf) ans++;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, m;
    cin>>n>>m;
    cat = vi(n);
    read(cat);
    vvi g(n);
    REP(i,n-1){
        int u, v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    ans = 0;
    dfs(0,-1, m, g, m);
    cout << ans << endl;
    return 0;
}
