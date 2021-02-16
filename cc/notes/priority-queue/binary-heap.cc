#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryHeapQuickRemovals {
    vector<T> heap;
    map<T, set<int>> mp;

    bool less(int i, int j) { return heap[i] <= heap[j]; }
    int parent(int k){ return (k - 1)/2; }
    int left(int k) { return 2 * k + 1; }
    int right(int k) { return 2 * k + 2; }

    void swim(int k){
        while(k > 0 and less(k, parent(k))){
            swap(k, parent(k));
            k = parent(k);
        }
    }

    void sink(int k){
        int heapsize = heap.size();
        while(true){
            int smallest = left(k);
            if(right(k) < heapsize and less(right(k), left(k))) smallest = right(k);
            if(left(k) >= heapsize or less(k, smallest)) break;

            swap(smallest, k);
            k = smallest;
        }
    }

    void swap(int i, int j){
        T hi = heap[i], hj = heap[j];
        heap[i] = hj;
        heap[j] = hi;
        map_swap(hi, hj, i, j);
    }

    T remove_at(int i){
        int id_of_last_elem = heap.size()-1;
        if(i > id_of_last_elem) return heap[0];

        T removed_data = heap[i];
        swap(i, id_of_last_elem);

        heap.pop_back();
        map_remove(removed_data, id_of_last_elem);

        if(i == id_of_last_elem) return removed_data;

        T elem = heap[i];
        sink(i);
        if(heap[i] == elem) swim(i);
        return removed_data;
    }

    void map_add(T val, int id) { mp[val].insert(id); }
    void map_remove(T val, int id) { mp[val].erase(id); }
    int map_get(T val) { return *(mp[val]).rbegin(); }
    void map_swap(T val1, T val2, int id1, int id2){
        mp[val1].erase(id1);
        mp[val2].erase(id2);

        mp[val1].insert(id2);
        mp[val2].insert(id1);
    }
public:
    BinaryHeapQuickRemovals() {this(1); }
    BinaryHeapQuickRemovals(int sz) { heap.resize(sz); }
    BinaryHeapQuickRemovals(vector<T> &elems){
        int heapsize = elems.size();
        heap.resize(heapsize);
        for (int i = 0; i < heapsize; i++) {
            map_add(elems[i], i);
            heap[i] = elems[i];
        }
        for(int i = max(0, heapsize/2 - 1); i >= 0; i--)
            sink(i);
    }

    int size() { return heap.size(); }
    T top() { return heap[0]; }
    T pop() { return remove_at(0); }
    bool contains(T elem){ return mp[elem].size(); }

    void push(T elem){
        heap.push_back(elem);
        map_add(elem, heap.size()-1);
        swim(heap.size()-1);
    }

    bool remove(T elem){
        if(not contains(elem)) return false;
        int id = map_get(elem);
        remove_at(id);
        return true;
    }

    bool is_min_heap(int k){
        int heapsize = heap.size();
        if(k >= heapsize) return true;

        if(left(k) < heapsize and not less(k, left(k))) return false;
        if(right(k) < heapsize and not less(k, right(k))) return false;

        return is_min_heap(left(k)) and is_min_heap(right(k));
    }
};

int32_t main(int argc, char const *argv[]){
    vector<int> v = {2,3,9,1,5,3};
    BinaryHeapQuickRemovals<int> h(v);
    db(h.is_min_heap(0));
    while(h.size()){
        cout<<h.top()<<endl;
        h.pop();
    }
    throw logic_error("there is no error XD");
    return 0;
}
