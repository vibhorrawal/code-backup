// My Favourite Data Structure :3

class DSU {
    int n, number_of_components;
    vector<int> parent, sz;
public:
    DSU(int size){
        n = size;
        number_of_components = n;
        parent = vector<int>(n);
        sz = vector<int>(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    bool connected(int a, int b) { return find(a) == find(b); }
    int component_size(int i) { return sz[find(i)]; }
    int size() { return n; }
    int get_number_of_components() { return number_of_components; }

    // int find(int i){
    //     if(i == parent[i]) return i;
    //     return parent[i] = find(parent[i]);
    // }
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
        number_of_components--;
        return true;
    }
};

int32_t main(int argc, char const *argv[]){
    fastIO;

    return 0;
}
