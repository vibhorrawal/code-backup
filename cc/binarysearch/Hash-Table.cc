class HashTable {
    unordered_map<int, int> mp;
    public:
    HashTable() {

    }

    void put(int key, int val) {
        mp[key] = val;
    }

    int get(int key) {
        if(mp.count(key))
            return mp[key];
        else return -1;
    }

    void remove(int key) {
        mp.erase(key);
    }
};


// HashTable implementation
class HashTable {
    hash<long> hs;
    vector<list<pair<int,int>>> v;
    const int SIZE = 1e4;
    public:
    HashTable() {
        v = vector<list<pair<int,int>>>(SIZE);
    }

    void put(int key, int val) {
        int id = hs(key) % SIZE;
        for(auto it = v[id].begin(); it != v[id].end(); it++){
            if(it->first == key){
                it->second = val;
                return;
            }
        }
        v[id].push_back({key, val});
    }

    int get(int key) {
        int id = hs(key) % SIZE;
        for(auto it = v[id].begin(); it != v[id].end(); it++){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int id = hs(key) % SIZE;
        for(auto it = v[id].begin(); it != v[id].end(); it++){
            if(it->first == key){
                v[id].erase(it);
                return;
            }
        }
    }
};
