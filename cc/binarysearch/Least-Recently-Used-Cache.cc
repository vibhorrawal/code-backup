// each method is O(1) time
class LRUCache {
    list<pair<int,int>> cache;
    map<int,list<pair<int,int>>::iterator> mp;
    int cap;
    
    void removeKey(int key){
        if(not mp.count(key)) 
            return;
        auto it = mp[key];
        cache.erase(it);
        mp.erase(key);
    }
    void insert(int key, int val){
        removeKey(key);
        cache.push_front({key,val});
        mp[key] = cache.begin();
    }
    public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(not mp.count(key))
            return -1;
        int val = mp[key]->second;
        insert(key,val);
        return val;
    }

    void set(int key, int val) {
        insert(key,val);
        if(mp.size() > cap){
            auto it = (--cache.end());
            int key = it->first;
            cache.erase(it);
            mp.erase(key);
        }
    }
};

// tried cleaner, but question changed a bit, TC did not change, hence commented code
class LRUCache {
    list<int> keys;
    unordered_map<int, list<int>::iterator> keyMap;
    unordered_map<int,int> dict;
    int max = 0;

    void remove(int key) {
        dict.erase(key);
        auto it = keyMap[key];
        keyMap.erase(key);
        keys.erase(it);
    }

    void insert(int key, int val) {
        if(dict.size() >= max) {
            auto last = keys.back();
            remove(last);
        }

        dict[key] = val;
        keys.push_front(key);
        keyMap[key] = keys.begin();
    }

    public:
    LRUCache(int capacity) {
        max = capacity;
    }   

    int get(int key) {
        if(!keyMap.count(key)) {
            // insert(key, -1);
            return -1;
        }
        int val = dict[key];
        // remove(key);
        // insert(key, val);
        return val;
    }

    void set(int key, int val) {
        if(keyMap.count(key)) {
            remove(key);
        }
        insert(key, val);
    }
};
