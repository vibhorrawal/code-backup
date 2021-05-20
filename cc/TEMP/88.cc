#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<pii>> vvp;
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
#ifdef LOCAL
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define db(...) {}
#endif

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

    bool contains_key(K key){
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

    void insert_key(K key, V val){
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

    V update_key(K key, V value){
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

// class MinIndexedPQ {
// public:
//     int NMAX, N, *heap, *index, *keys;
//
//     void swap(int i, int j) {
//         int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
//         index[heap[i]] = i; index[heap[j]] = j;
//     }
//
//     void bubbleUp(int k)    {
//         while(k > 1 && keys[heap[k/2]] > keys[heap[k]])   {
//             swap(k, k/2);
//             k = k/2;
//         }
//     }
//
//     void bubbleDown(int k)  {
//         int j;
//         while(2*k <= N) {
//             j = 2*k;
//             if(j < N && keys[heap[j]] > keys[heap[j+1]])
//                 j++;
//             if(keys[heap[k]] <= keys[heap[j]])
//                 break;
//             swap(k, j);
//             k = j;
//         }
//     }
//
// public:
//     // Create an empty MinIndexedPQ which can contain atmost NMAX elements
//     MinIndexedPQ(int NMAX)  {
//         this->NMAX = NMAX;
//         N = 0;
//         keys = new int[NMAX + 1];
//         heap = new int[NMAX + 1];
//         index = new int[NMAX + 1];
//         for(int i = 0; i <= NMAX; i++)
//             index[i] = -1;
//     }
//
//     ~MinIndexedPQ() {
//         delete [] keys;
//         delete [] heap;
//         delete [] index;
//     }
//
//     // check if the PQ is empty
//     bool isEmpty()  {
//         return N == 0;
//     }
//
//     // check if i is an index on the PQ
//     bool contains(int i)    {
//         return index[i] != -1;
//     }
//
//     // return the number of elements in the PQ
//     int size()  {
//         return N;
//     }
//
//     // associate key with index i; 0 < i < NMAX
//     void insert(int i, int key) {
//         N++;
//         index[i] = N;
//         heap[N] = i;
//         keys[i] = key;
//         bubbleUp(N);
//     }
//
//     // returns the index associated with the minimal key
//     int minIndex()  {
//         return heap[1];
//     }
//
//     // returns the minimal key
//     int minKey()    {
//         return keys[heap[1]];
//     }
//
//     // delete the minimal key and return its associated index
//     // Warning: Don't try to read from this index after calling this function
//     int deleteMin() {
//         int min = heap[1];
//         swap(1, N--);
//         bubbleDown(1);
//         index[min] = -1;
//         heap[N+1] = -1;
//         return min;
//     }
//
//     // returns the key associated with index i
//     int keyOf(int i)    {
//         return keys[i];
//     }
//
//     // change the key associated with index i to the specified value
//     void changeKey(int i, int key)  {
//         keys[i] = key;
//         bubbleUp(index[i]);
//         bubbleDown(index[i]);
//     }
//
//     // decrease the key associated with index i to the specified value
//     void decreaseKey(int i, int key)    {
//         keys[i] = key;
//         bubbleUp(index[i]);
//     }
//
//     // increase the key associated with index i to the specified value
//     void increaseKey(int i, int key)    {
//         keys[i] = key;
//         bubbleDown(index[i]);
//     }
//
//     // delete the key associated with index i
//     void deleteKey(int i)   {
//         int ind = index[i];
//         swap(ind, N--);
//         bubbleUp(ind);
//         bubbleDown(ind);
//         index[i] = -1;
//     }
// };

vector<int> findKthTask(vector<int> tasks, vector<int> k) {
        // MinIndexedPQ hp(1e5);
        BinaryHeap<int,int> hp(1e5);
        vector<int> res;
        for(int i = 0; i < k.size(); i++){
            hp.insert_key(tasks[i], tasks[i]);
            res.push_back(hp.value_of(k[i]));
        }
        return res;
}
int32_t main(int argc, char const *argv[]){
    int n;
    // cin>>n;

    std::vector<int> tasks = {10,12,8,2,4}, k = {1,1,3,1,5};
    auto v = findKthTask(tasks, k);
    db(v);
    return 0;
}
