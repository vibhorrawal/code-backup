#include<bits/stdc++.h>
using namespace std;

template<typename T> class FenwickTreeRangeQueryPointUpdate {
    int N;
    vector<T> tree;

    int lsb(int i) { return i & -i; }

    T prefix_sum(int i){
        T sum = 0;
        i++;
        while(i != 0){
            sum += tree[i];
            i &= ~lsb(i); // Equivalently, i -= lsb(i);
        }
        return sum;
    }

public:
    FenwickTreeRangeQueryPointUpdate(int sz) { tree.resize(N = sz + 1); }
    FenwickTreeRangeQueryPointUpdate(vector<T> &arr){
        N = arr.size() + 1;
        tree.resize(N);
        for (int i = 0; i < arr.size(); i++)
            tree[i + 1] = arr[i];
        for (int i = 1; i < N; i++) {
            int parent = i + lsb(i);
            if(parent < N) tree[parent] += tree[i];
        }
    }

    T sum(int l, int r){ return prefix_sum(r) - prefix_sum(l-1); } // sum: [l, r]
    T get(int i) { return sum(i, i); }

    void add(int i, T val){
        i++;
        while(i < N){
            tree[i] += val;
            i += lsb(i);
        }
    }

    void set(int i, T val){
        add(i, val - sum(i, i));
    }
};

int32_t main(int argc, char const *argv[]){
    vector<int> v = {1,2,2,4};
    FenwickTreeRangeQueryPointUpdate<int> ft(v);

    cout<< ft.sum(0,3) << endl;
    ft.add(3,1);
    cout<< ft.sum(0,3) << endl;

    cout << ft.sum(0,0) << endl;
    ft.set(3, 0);
    cout <<ft.get(3) << endl;
    return 0;
}
