#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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

#define pii pair<int,int>

int n;
// inline int pair_to_int(int x, int y){
//     return ((x - 1) * n) + y;
// }
vi calc;
int one;

void dfs2(int u, vi &indegree, queue<int> &q, vector<bool> &vis, vvi &g){
    if(vis[u]) return;
    vis[u] = true;
    indegree[u] = g[u].size();
    if(indegree[u] == 1) {
        q.push(u);
        indegree[u] = 0;
    }
    for(int v : g[u]){
        if(vis[v]) continue;
        dfs2(v, indegree, q, vis, g);
    }
}

int dfs(int u, vector<bool> &vis, vvi &g){
    vi indegree(n * n + 1);
    queue<int> q;
    indegree[u] = g[u].size();
    if(indegree[u] == 1) {
        q.push(u);
        indegree[u] = 0;
    }
    vis[u] = true;
    for(int v : g[u]){
        if(vis[v]) continue;
        dfs2(v, indegree, q, vis, g);
    }
    int ans = 0;
    bool include = true;
    while(q.size()){
        int qs = q.size();
        while(qs--){
            int u = q.front(); q.pop();
            ans += include;
            for(int v : g[u]){
                if(--indegree[v] == 1){
                    q.push(v);
                }
            }
        }
        include = not include;
    }
    return ans;
}

int main(){
    fastIO;
    int m;
    cin>>n>>m;

    vvi g(n * n + 1);
    calc = vi(n * n + 1);
    REP(i, m){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int p1 = pair_to_int(x1, y1);
        int p2 = pair_to_int(x2, y2);
        g[p1].pb(p2);
        g[p2].pb(p1);
        calc[p1]++;
        calc[p2]++;
    }
    int ans = 0;
    vector<bool> vis(n * n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int u = pair_to_int(i,j);
            if(vis[u]) continue;
            ans += dfs(u, vis, g);
        }
    }
    cout << ans << endl;
    return 0;
}


/*
map<pii, int> pair_to_int;
vi parent;
int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    parent[a] = b;
}


int32_t main(int argc, char const *argv[]){
    int n, m;
    int cnt = 1;
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pair_to_int[{i,j}] = cnt++;
        }
    }
    parent = vi(n * n + 5, -1);
    for(int i = 1; i <= n * n; i++) parent[i] = i;
    REP(i, m){
        pair<int,int> p1, p2;
        cin>>p1.first>>p1.second>>p2.first>>p2.second;
        int t1 = pair_to_int[p1], t2 = pair_to_int[p2];
        db(t1);
        db(t2);
        Union(t1, t2);
    }
    unordered_set<int> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int id = pair_to_int[{i,j}];
            s.insert(find(id));
        }
    }
    cout << s.size() << endl;
    return 0;
}
*/
