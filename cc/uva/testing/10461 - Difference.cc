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
#ifdef LOCAL
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define db(...) {}
#endif

vi bfs(int u, vvi &g){
    queue<int> q;
    vi vis(sz(g));
    q.push(u);
    while(sz(q)){
        u = q.front(); q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int v : g[u]){
            if(not vis[v]) q.push(v);
        }
    }
    return vis;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    int tcs = 1;
    while(1){
        int v, e;
        cin>>v>>e;
        if(v == 0 and e == 0) break;
        vi cost(v);
        read(cost);
        vvi g(v), tr(v);
        REP(i,e){
            int a, b;
            cin>>a>>b;
            a--, b--;
            g[a].pb(b);
            tr[b].pb(a);
        }

        cout << "Case #"<<tcs++ << ":"<< endl;
        T(){
            int x;
            cin>>x; x--;
            vi vis_to_child = bfs(x, g), vis_to_parent = bfs(x, tr);
            ll total = 0, child_time = 0;
            for (int i = 0; i < v; i++) {
                if(vis_to_child[i]) child_time += cost[i];
            }
            total = accumulate(all(cost), 0ll) - child_time;

            for (int i = 0; i < v; i++) {
                if(i != x and vis_to_parent[i]) total -= cost[i];
            }
            cout<< total << endl;
        }
        cout<<endl;
    }
    return 0;
}
