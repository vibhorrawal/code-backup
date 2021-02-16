// 1. sort edges wrt weights
// 2. take the edge, and if u and v are both in the graph (creates a cycle) then skip them
// 3. add u-> v edge in graph untill size of tree is n

class KruskalSolver {
    class DSU {
        int n, numer_of_components;
        vector<int> parent, sz;
    public:
        DSU(int size){
            n = size;
            parent = vector<int>(n);
            sz = vector<int>(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int p){
            int root = p;
            while(root != parent[root]) root = parent[root];
            while(p != root){
                int nxt = parent[p];
                parent[p] = root;
                p = nxt;
            }
            return root;
        }

        bool connected(int a, int b) { return find(a) == find(b); }
        int component_size(int i) { return sz[find(i)]; }
        int size() { return n; }
        int get_number_of_components() { return numer_of_components; }

        bool unify(int a, int b) {
            if(connected(a, b)) return false;

            int root1 = find(a), root2 = find(b);
            if(sz[root1] < sz[root2]){
                sz[root2] += sz[root1];
                parent[root1] = root2;
            }
            else{
                sz[root1] += sz[root2];
                parent[root2] = root1;
            }
            numer_of_components--;
            return true;
        }

    };

    vector<vector<int>> edges, mst; // u,v,w
    int n;
    long long mst_cost;

public:
    KruskalSolver(vector<vector<int>> &edge_list, int sz) {
        edges = edge_list;
        assert(edges[0].size() == 3);
        n = sz;
        mst_cost = 0;
    }

    long long get_mst_cost() {
        if(mst_cost) return mst_cost;

        // can use priority queue to bring O(ElogE) to O(VlogE)
        sort(edges.begin(), edges.end(),
            [](const vector<int> &a, const vector<int> &b){ return a[2] < b[2]; });

        DSU dsu(n);

        for(vector<int> edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(dsu.connected(u, v)) continue;

            dsu.unify(u, v);
            mst_cost += w;
            mst.push_back(edge);

            if(dsu.component_size(u) == n) break;
        }
        assert(dsu.component_size(0) == n);
        return mst_cost;
    }

    vector<vector<int>> get_mst_edge_list(){
        if(mst.empty()) get_mst_cost();
        return mst;
    }
};
