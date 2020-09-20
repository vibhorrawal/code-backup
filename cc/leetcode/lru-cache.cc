// get and put in O(1) time
class LRUCache {
    int cap;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        int value = mp[key]->second;
        replace_key(key, value);
        return value;
    }
    void insert(int key, int value){
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
    void replace_key(int key, int value){
        auto it = mp[key];
        cache.erase(it);
        insert(key, value);
    }
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
            replace_key(key, value);
        else
            insert(key, value);
        if(cache.size() > cap){
            auto it = cache.rbegin();
            int key = it->first;
            cache.erase(mp[key]);
            mp.erase(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
