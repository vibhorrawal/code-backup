#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define pb emplace_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

// Binary Indexed Tree or Fenwick Tree
template<typename T>
class BIT {
    vector<T> tree, inp_array;
    int get_parent(int idx){ return idx - (idx & -idx); }
    int get_next(int idx){ return idx + (idx & -idx); }
    int get_tree_index(int idx) { return idx + 1; }

  public:
    BIT() { }
    BIT(vector<T> &inp) { create_tree(inp); }

    void increase(int idx, T val){
        idx = get_tree_index(idx);
        while(idx < (int) tree.size()){
          tree[idx] += val;
          idx = get_next(idx);
        }
    }

    void update(int idx, T val) {
        val -= inp_array[idx];
        inp_array[idx] += val;
        increase(idx, val);
    }

    void create_tree(const vector<T> &inp){
        inp_array = inp;
        tree.resize(inp.size() + 1);
        fill(tree.begin(), tree.end(), 0);
        for(int i = 0; i < (int) inp.size(); i++)
            increase(i, inp_array[i]);
    }

    T get_sum(int idx){
        idx = get_tree_index(idx);
        T res = 0;
        while(idx > 0){
            res += tree[idx];
            idx = get_parent(idx);
        }
        return res;
    }

    T get_sum(int l, int r){ return get_sum(r) - get_sum(l-1); }
    T operator[](int idx){ return tree[idx-1]; }
    void print(){ for(T t : tree) cout<<t<<' '; cout<<endl; }
};

int32_t main(int argc, char const *argv[]){
  fastIO;
  vector<int> v = {3,5,-1,6};
  BIT<int> bt (v);
  db(bt.get_sum(2));
  bt.print();
  return 0;
}
