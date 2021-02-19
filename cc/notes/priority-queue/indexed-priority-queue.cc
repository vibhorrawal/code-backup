#include<bits/stdc++.h>
using namespace std;

template<typename K, typename V> class MinIndexedDHeap {
    int sz, N, D;
    vector<int> child, parent, pm /* position map */, im /* inverse map */;
    map<K, int> ki_map;
    map<int,K> map_ki;
    vector<V> values;

    void ki_in_bound_or_throw(int ki) { assert(0 <= ki and ki < N); }
    void is_not_empty_or_throw() { assert(sz > 0); }

    bool contains(int ki){
        ki_in_bound_or_throw(ki);
        return pm[ki] != -1;
    }

    int top_ki() {
        is_not_empty_or_throw();
        return im[0];
    }

    void insert(int ki, V value){
        if(contains(ki)) throw logic_error("index already exists: " + to_string(ki));
        pm[ki] = sz;
        im[sz] = ki;
        values[ki] = value;
        swim(sz++);
    }

    V delete_ki(int ki){
        int i = pm[ki];
        swap(i, --sz);
        sink(i);
        swim(i);
        V val = values[ki];
        pm[ki] = -1;
        im[sz] = -1;
        return val;
    }

    K update(int ki, K value){
        ki_in_bound_or_throw();
        int i = pm[ki];
        K old = values[ki];
        values[ki] = value;
        sink(i);
        swim(i);
        return old;
    }

    void sink(int i){
        for(int j = minchild(i); j != -1; ){
            swap(i, j);
            i = j;
            j = minchild(i);
        }
    }

    void swim(int i){
        while(less_i(i, parent[i])){
            swap(i, parent[i]);
            i = parent[i];
        }
    }

    int minchild(int i){
        int index = -1, from = child[i], to = min(sz, from + D);
        for (int j = from; j < to; j++) if (less_i(j, i)) index = i = j;
        return index;
    }

    void swap(int i, int j) {
        pm[im[j]] = i;
        pm[im[i]] = j;
        int tmp = im[i];
        im[i] = im[j];
        im[j] = tmp;
     }

     bool less_i(int i, int j){
         return values[im[i]] < values[im[j]];
     }

     bool less(V a, V b){
         return a < b;
     }

     bool is_min_heap(int i){
         int from = child[i], to = min(sz, from + D);
         for (int j = from; j < to; j++) {
             if (!less_i(i, j)) return false;
             if (!is_min_heap(j)) return false;
         }
         return true;
     }
public:
    MinIndexedDHeap(int degree, int maxsize){
        assert(maxsize > 0 and degree > 0);
        sz = 0;
        D = max(2, degree);
        N = max(D + 1, maxsize);

        im = vector<int>(N, -1);
        pm = vector<int>(N, -1);

        child = vector<int>(N);
        parent = vector<int>(N);
        values = vector<V>(N);

        for (int i = 0; i < N; i++) {
            parent[i] = (i - 1) / D;
            child[i] = i * D + 1;
        }
    }

    int size(){ return sz; }

    bool contains(K key){
        if(ki_map.count(key) == 0) return false;
        return contains(ki_map(key));
    }

    K top_key(){
        return map_ki[top_ki()];
    }

    V top_value(){
        is_not_empty_or_throw();
        return values[im[0]];
    }

    void pop() { delete_ki(top_ki()); }

    void insert(K key, V val){
        assert(ki_map.count(key) == 0);
        int ki_cnt = ki_map.size();
        ki_map[key] = ki_cnt;
        map_ki[ki_cnt] = key;

        insert(ki_map[key], val);
    }

    V value_of(K key){
        assert(ki_map.count(key));
        return values[ki_map[key]];
    }

    V delete_key(K key){
        assert(ki_map.count(key));
        return delete_ki(ki_map[key]);
    }

    V update(K key, V value){
        assert(ki_map.count(key));
        return update(ki_map[key], value);
    }

    void increase(K key, V value){
        assert(ki_map.count(key));
        int ki = ki_map[key];
        if(less(values[ki], value)){
            values[ki] = value;
            sink(pm[ki]);
        }
    }

    void decrease(K key, V value){
        assert(ki_map.count(key));
        int ki = ki_map[key];
        if(less(value, values[ki])){
            values[ki] = value;
            swim(pm[ki]);
        }
    }

    bool is_min_heap(){ return is_min_heap(0); }
};

template<typename K, typename V> class BinaryHeap : public MinIndexedDHeap<K, V> {
public:
    BinaryHeap(int maxsize) : MinIndexedDHeap<K,V>(2, maxsize) {}
};

int32_t main(int argc, char const *argv[]){
    BinaryHeap<string,int> bh(1e3);
    bh.insert("vijay", 2);
    bh.insert("ajaj", 3);
    bh.insert("uday", 1);
    bh.insert("raj", 12);
    for (int i = 0; i < 1e2; i++) {
        bh.insert(to_string(i), rand());
        assert(bh.is_min_heap());
        if(i % 2 and i) bh.pop();
    }
    while(bh.size()){
        // cout << bh.top_key() << endl;
        bh.pop();
        assert(bh.is_min_heap());

    }
    return 0;
}
