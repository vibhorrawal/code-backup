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
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)


vi res(100);
// set<int> s;
void generate(vi &a, int l, int r, int depth){
    if(l > r) return;
    if(l == r){
        res[l] = depth;
        return;
    }
    int id = max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
    res[id] = depth;
    generate(a, l, id - 1, depth + 1);
    generate(a, id + 1, r, depth + 1);
}

void solve(){
    // s.clear();
    int n;
    cin>>n;
    vi a(n);
    read(a);
    assert(a.size());
    for (int i = 0; i < n; i++) res[i] = 0;

    // MaxSparseTable st(a);
    // db(a);
    // db(st.query_max_index(0, n-1));
    generate(a, 0, n-1, 0);

    for (int i = 0; i < n; i++) {
        cout<<res[i]<<' ';
    }
    cout << endl;
}
int32_t main(int argc, char const *argv[]){
    T(){
        solve();
    }
    return 0;
}
