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
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

void dfs(int u, vi &res, vi &vis, vvi &g){
    if(vis[u]) return;
    vis[u] = true;
    for(int v : g[u]){
        if(not vis[v]) dfs(v, res, vis, g);
    }
    res.pb(u);
}
vi topological(vvi &g){
    vi res;
    vi vis(sz(g));
    for (int i = 1; i < sz(g); i++) {
        if(not vis[i]) dfs(i, res, vis, g);
    }
    reverse(all(res));
    assert(res.size() == g.size()-1);
    return res;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, k;
    cin>>n>>k;
    vvi g(n+1);
    REP(i,k){
        T(){
            int t;
            cin>>t;
            g[i+1].pb(t);
        }
    }
    REP(i,n+1) if(g[i].size()) db(i,g[i]);
    vi v = topological(g);
    db(v);
    vi ans(n+1);
    int parent = 0;
    for(int i = 0; i < sz(v); i++){
        ans[v[i]] = parent;
        parent = v[i];
    }
    for (int i = 1; i < sz(ans); i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
