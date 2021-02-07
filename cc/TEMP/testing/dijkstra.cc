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

const int INF = 1e9 + 5;

/* small
real	0m1.670s
user	0m1.663s
sys	0m0.004s
*/

/* large
real	0m2.290s
user	0m2.225s
sys	0m0.065s
*/
vector<int> dijkstra1(vector<vector<pair<int,int>>> g, int src, int n){
    vector<int> dist(n, INF);
    vector<int> parent(n, -1); // to reconstruct path
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(pq.size()){
        auto it = pq.top(); pq.pop();
        int w = it.first, u = it.second;
        if(dist[u] < w) continue;
        for(auto p : g[u]){
            int v = p.first, wt = p.second;
            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[u], v});
                parent[v] = u;
            }
        }
    }
    return dist;
}

// Eager dijkstra
/* small
real	0m1.607s
user	0m1.602s
sys	0m0.005s
*/

/* large
real	0m2.314s
user	0m2.270s
sys	0m0.045s

*/
vector<int> dijkstra2(vector<vector<pair<int,int>>> g, int src, int n){
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    set<pair<int,int>> s;
    dist[src] = 0;
    s.insert({dist[src], src});

    while(s.size()){
        auto it = s.begin();
        int w = it->first, u = it->second;
        s.erase(it);
        if(dist[u] < w) continue;
        for(auto p : g[u]){
            int v = p.first, wt = p.second;
            if(dist[u] + wt < dist[v]) {
                auto it = s.find({dist[v], v});
                if(it != s.end()) s.erase(it);

                dist[v] = dist[u] + wt;
                s.insert({dist[u], v});
                parent[v] = u;
            }
        }
    }
    return dist;
}

int networkDelayTime(vector<vector<int>>& t, int n, int k) {
    // db(n);
    vector<vector<pair<int,int>>> g(n);
    for(auto it : t){
        assert(0 <= it[0]);
        assert(it[0] < n);
        g[it[0]].push_back({it[1], it[2]});
        // db(it);
    }

    vector<int> d = dijkstra1(g, k, n);
    for(int i : d) if(i == INF) return -1;
    return *max_element(d.begin(), d.end());
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        int n, k, m;
        cin>>n>>k>>m;
        vvi t(m);
        REP(i, m){
            int u, v, w;
            cin>>u>>v>>w;
            t[i] = {u,v,w};
        }
        cout << networkDelayTime(t, n, k) << endl;
    }
    return 0;
}
