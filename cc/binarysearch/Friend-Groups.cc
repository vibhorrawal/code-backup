// O(N) space time
vector<int> p;

// naive union find
int find(int i){
    if(p[i] == -1) 
        return i;
    return find(p[i]);
}
void Union(int x, int y){
    int px = find(x), py = find(y);
    if(px == py)
        return;
    p[py] = px;
}
int solve(vector<vector<int>>& friends) {
    vector<int> head(251,-1);
    p = head;
    for(int i = 0; i < friends.size(); i++){
        for(int v : friends[i]) Union(i,v);
    }
    set<int> s;
    for(auto u : friends){
        for(int v : u)
            s.insert(find(v));
    }
    return s.size();
}

// cleaner
class DSU {
    vector<int> parent, size;
public:
    int components;
    DSU(int n) {
        components = n;
        parent = vector<int>(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        size = vector<int>(n, 1);
    }
    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    bool unify(int a, int b) {
        if(connected(a, b)) return false;
        a = find(a);
        b = find(b);

        if(size[a] > size[b]) {
            parent[b] = a;
            size[a] += size[b];
        } else {
            parent[a] = b;
            size[b] += size[a];
        }
        components--;
        return true;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int solve(vector<vector<int>>& friends) {
    int n = friends.size();
    DSU dsu = DSU(n);
    for(int i = 0; i < friends.size(); i++) {
        for(int f : friends[i]) {
            dsu.unify(i, f);
        }
    }
    return dsu.components;
}