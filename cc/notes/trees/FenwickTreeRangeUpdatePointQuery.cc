#include<bits/stdc++.h>
using namespace std;

template<typename T> class FenwickTreeRangeUpdatePointQuery {
    int N;
    vector<T> original_tree, current_tree;

    int lsb(int i) { return i & -i; }

    void add(int i, T val){
        i++;
        while(i < N){
            current_tree[i] += val;
            i += lsb(i);
        }
    }

    T prefix_sum(int i, vector<T> &tree){
        i++;
        T sum = 0;
        while(i != 0){
            sum += tree[i];
            i &= ~lsb(i); // i -= lsb(i);
        }
        return sum;
    }
public:
    FenwickTreeRangeUpdatePointQuery(vector<T> &arr){
        N = arr.size() + 1;
        original_tree.resize(N);
        for (int i = 0; i < N - 1; i++)
            original_tree[i + 1] = arr[i];

        for(int i = 1; i < N; i++){
            int parent = i + lsb(i);
            if(parent < N) original_tree[parent] += original_tree[i];
        }
        current_tree = original_tree;
    }

    void update_range(int l, int r, T val){ // update: [l, r] with +val
        add(l, +val);
        add(r + 1, -val);
    }

    T get(int i){
        return prefix_sum(i, current_tree) - prefix_sum(i - 1, original_tree);
    }
};

int32_t main(int argc, char const *argv[]){
    vector<int> v = {+1, -2, 3, -4, 5, -6};
    FenwickTreeRangeUpdatePointQuery<int> ft(v);

    ft.update_range(0, 3, 10);
    cout << ft.get(0) << endl;
    cout << ft.get(3) << endl;
    cout << ft.get(4) << endl;

    ft.update_range(2, 5, -20);
    cout << ft.get(2) << endl;
    cout << ft.get(3) << endl;
    cout << ft.get(4) << endl;
    return 0;
}
