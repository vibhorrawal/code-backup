// worst case O(N) [when hash function isn't able to distribute]
class Set {
    vector<vector<int>> v;
    int sz = 1e3;
    public:
    Set() {
        v.resize(sz);
    }
    long hash(long n){
        return n * n + (n + 101);
    }
    void add(int val) {
        for(int it : v[hash(val) % sz])
            if(it == val) return;
        v[hash(val) % sz].push_back(val);
    }

    bool exists(int val) {
        for(int it : v[hash(val) % sz])
            if(it == val) return true;
        return false;
    }

    void remove(int val) {
        for(int &it : v[hash(val) % sz])
            if(it == val) it = INT_MIN;
    }
};

// cleaner
class CustomSet {
    int S = 1e4;
    vector<list<int>> v;
    hash<int> hs;
    public:
    CustomSet() {
        v.resize(S);
    }

    void add(int val) {
        if(exists(val))
            return;
        int id = hs(val) % S;
        v[id].push_back(val);
    }

    bool exists(int val) {
        int id = hs(val) % S;
        for(int x : v[id]) {
            if(x == val)
                return true;
        }
        return false;
    }

    void remove(int val) {
        int id = hs(val) % S;
        for(auto it = v[id].begin(); it != v[id].end(); it++){
            if(*it == val){
                v[id].erase(it);
                return;
            }
        }
    }
};
