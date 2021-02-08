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


// lazy version
// O(ElogE)

class PrimMST {
    struct edge {
        int u, v, w;
        edge(int _u, int _v, int _w){
            u = _u, v = _v, w = _w;
        }

        bool operator< (const edge &e) const {
            return w < e.w;
        }

        bool operator> (const edge &e) const {
            return w > e.w;
        }
    };

    vector<vector<pair<int,int>>> g;
    int n, edge_count, required_edges_for_tree;
    long long mst_cost;
    bool solved = false, _mst_exists = false;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<bool> vis;
    vector<vector<int>> edges_in_mst;

    void setup() {
        n = g.size();
        mst_cost = edge_count = 0;
        required_edges_for_tree = n - 1;
        vis = vector<bool>(n);
        edges_in_mst = vector<vector<int>>(required_edges_for_tree);
    }

    void add_edges(int u) {
        vis[u] = true;
        for(auto it : g[u]){
            int v = it.first, w = it.second;
            if(vis[v]) continue;
            pq.push(edge(u, v, w));
        }
    }
    void solve() {
        if(solved) return;
        setup();
        add_edges(0);

        while(pq.size() and edge_count != required_edges_for_tree) {
            edge e = pq.top(); pq.pop();
            if(vis[e.v]) continue;

            mst_cost += e.w;
            edges_in_mst[edge_count++] = {e.u, e.v, e.w};

            add_edges(e.v);
        }
        _mst_exists = edge_count == required_edges_for_tree;
        solved = true;
    }
public:
    PrimMST(vector<vector<pair<int,int>>> &adj_list): g(adj_list) {}

    bool mst_exists() {
        solve();
        return _mst_exists;
    }

    int get_mst_cost(){
        solve();
        assert(_mst_exists);
        return mst_cost;
    }

    vector<vector<int>> get_edges_in_mst() {
        solve();
        assert(_mst_exists);
        return edges_in_mst;
    }
};


//------------------------------------------------------------------------------

// Eager method for Prim's
// O(E logV)
// O(V ^ 2) space | using adjacency matrix

// in current implementations indexed priority_queue is just a set, hence this is slower on Runtime than priority_queue method above
// but use indexed priority_queue data structure and performance should improve
class EagerPrimMST {
    struct edge {
        int u, v, w;
        edge(int _u, int _v, int _w){ u = _u, v = _v, w = _w; }
        bool operator< (const edge &e) const {
            if(w != e.w) return w < e.w;
            if(u != e.u) return u < e.u;
            return v < e.v;
        }
    };

    const int INF = 1e9 + 5, UNVISITED = 0, VISITING = 1, VISITED = 2;
    int n, edge_count, required_edges_for_tree;
    vector<vector<int>> g, edges_in_mst;
    bool solved = false, _mst_exists = false;
    long long mst_cost = 0;
    set<edge> indexed_pq;
    vector<int> vis;
    void setup() {
        required_edges_for_tree = n - 1;
        edge_count = 0;
        vis = vector<int>(n, UNVISITED);
        edges_in_mst = vector<vector<int>>(required_edges_for_tree);
    }

    void add_edges(int u) {
        vis[u] = VISITED;
        for(int v = 0; v < n; v++){
            if(g[u][v] == INF or vis[v] == VISITED) continue;
            if(vis[v] == UNVISITED) {
                indexed_pq.insert(edge(u, v, g[u][v]));
                vis[v] = VISITING;
            }
            else if(vis[v] == VISITING) {
                auto it = find_if(indexed_pq.begin(), indexed_pq.end(),
                                [&](const edge &e){ return e.v == v; });
                // assert(it != indexed_pq.end());
                if(it->w < g[u][v]) continue;
                indexed_pq.erase(it);
                indexed_pq.insert(edge(u, v, g[u][v]));

            }
            else assert(false);
        }
    }

    void solve() {
        if(solved) return;
        setup();
        add_edges(0);
        while(indexed_pq.size() and edge_count != required_edges_for_tree) {
            auto it = indexed_pq.begin();
            edge e = *it; indexed_pq.erase(it);
            if(vis[e.v] == VISITED) continue;

            edges_in_mst[edge_count++] = {e.u, e.v, e.w};
            mst_cost += e.w;

            add_edges(e.v);
        }
        _mst_exists = edge_count == required_edges_for_tree;
        solved = true;
    }
public:
    EagerPrimMST(vector<vector<int>> &adj_matrix) : g(adj_matrix) {
        n = g.size();
        assert(n == g[0].size()); // square matrix
    }

    EagerPrimMST(vector<vector<pair<int,int>>> &adj_list) {
        n = adj_list.size();
        g = vector<vector<int>> (n, vector<int> (n, INF));
        for (int i = 0; i < n; i++) {
            for(auto edge : adj_list[i]){
                int v = edge.first, w = edge.second;
                g[i][v] = w;
            }
            g[i][i] = 0;
        }
    }

    int get_mst_cost() {
        solve();
        return mst_cost;
    }

    vector<vector<int>> get_edges_in_mst() {
        solve();
        return edges_in_mst;
    }
};

class EagerPrimListMST {
    struct edge {
        int u, v, w;
        edge(int _u, int _v, int _w){ u = _u, v = _v, w = _w; }
        bool operator< (const edge &e) const {
            if(w != e.w) return w < e.w;
            if(u != e.u) return u < e.u;
            return v < e.v;
        }
    };

    const int INF = 1e9 + 5, UNVISITED = 0, VISITING = 1, VISITED = 2;
    int n, edge_count, required_edges_for_tree;
    vector<vector<int>> edges_in_mst;
    vector<vector<pair<int,int>>> g;
    bool solved = false, _mst_exists = false;
    long long mst_cost = 0;
    set<edge> indexed_pq;
    vector<int> vis;
    void setup() {
        required_edges_for_tree = n - 1;
        edge_count = 0;
        vis = vector<int>(n, UNVISITED);
        edges_in_mst = vector<vector<int>>(required_edges_for_tree);
    }

    void add_edges(int u) {
        vis[u] = VISITED;
        for(auto e : g[u]){
            int v = e.first, w = e.second;
            if(vis[v] == VISITED) continue;
            if(vis[v] == UNVISITED) {
                indexed_pq.insert(edge(u, v, w));
                vis[v] = VISITING;
            }
            else if(vis[v] == VISITING) {
                auto it = find_if(indexed_pq.begin(), indexed_pq.end(),
                                [&](const edge &e){ return e.v == v; });
                // assert(it != indexed_pq.end());
                if(it->w < w) continue;
                indexed_pq.erase(it);
                indexed_pq.insert(edge(u, v, w));

            }
            else assert(false);
        }
    }

    void solve() {
        if(solved) return;
        setup();
        add_edges(0);
        while(indexed_pq.size() and edge_count != required_edges_for_tree) {
            auto it = indexed_pq.begin();
            edge e = *it; indexed_pq.erase(it);
            if(vis[e.v] == VISITED) continue;

            edges_in_mst[edge_count++] = {e.u, e.v, e.w};
            mst_cost += e.w;

            add_edges(e.v);
        }
        _mst_exists = edge_count == required_edges_for_tree;
        solved = true;
    }
public:
    // EagerPrimMST(vector<vector<int>> &adj_matrix) : g(adj_matrix) {
    //     n = g.size();
    //     assert(n == g[0].size()); // square matrix
    // }

    EagerPrimListMST(vector<vector<pair<int,int>>> &adj_list) {
        n = adj_list.size();
        g = adj_list;
        // g = vector<vector<int>> (n, vector<int> (n, INF));
        // for (int i = 0; i < n; i++) {
        //     for(auto edge : adj_list[i]){
        //         int v = edge.first, w = edge.second;
        //         g[i][v] = w;
        //     }
        //     g[i][i] = 0;
        // }
    }

    int get_mst_cost() {
        solve();
        return mst_cost;
    }

    vector<vector<int>> get_edges_in_mst() {
        solve();
        return edges_in_mst;
    }
};

void addUndirectedEdge(vector<vector<pair<int,int>>> &g, int u, int v, int w){
    g[u].push_back({v, w});
    g[v].push_back({u, w});
}
int32_t main(int argc, char const *argv[]){
    vector<vector<pair<int,int>>> g(10);
    addUndirectedEdge(g, 0, 1, 5);
    addUndirectedEdge(g, 1, 2, 4);
    addUndirectedEdge(g, 2, 9, 2);
    addUndirectedEdge(g, 0, 4, 1);
    addUndirectedEdge(g, 0, 3, 4);
    addUndirectedEdge(g, 1, 3, 2);
    addUndirectedEdge(g, 2, 7, 4);
    addUndirectedEdge(g, 2, 8, 1);
    addUndirectedEdge(g, 9, 8, 0);
    addUndirectedEdge(g, 4, 5, 1);
    addUndirectedEdge(g, 5, 6, 7);
    addUndirectedEdge(g, 6, 8, 4);
    addUndirectedEdge(g, 4, 3, 2);
    addUndirectedEdge(g, 5, 3, 5);
    addUndirectedEdge(g, 3, 6, 11);
    addUndirectedEdge(g, 6, 7, 1);
    addUndirectedEdge(g, 3, 7, 2);
    addUndirectedEdge(g, 7, 8, 6);

    PrimMST solver(g);
    cout << solver.get_mst_cost() << endl;
    for(auto v : solver.get_edges_in_mst()) db(v);

    EagerPrimMST mst(g);
    assert(mst.get_mst_cost() == solver.get_mst_cost());
    db(1);
    for(auto v : mst.get_edges_in_mst()) db(v);

    return 0;
}
