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

class MaxSparseTable {
    int N, P; // P is max power of 2 needed
    vector<int> log2;
    vector<vector<int>> dp;
    vector<vector<int>> it;

public:
    MaxSparseTable(vector<int> &values){
        N = values.size();
        P = (int)(log(N) / log(2));
        dp = vector<vector<int>>(P + 1, vector<int>(N));
        it = vector<vector<int>>(P + 1, vector<int>(N));
        log2 = vector<int>(N + 1);

        for (int i = 0; i < N; i++) {
            dp[0][i] = values[i];
            it[0][i] = i;
        }

        for (int i = 2; i <= N; i++) {
            log2[i] = log2[i / 2] + 1;
        }

        for (int p = 1; p <= P; p++) {
            for (int i = 0; i + (1<<p) <= N; i++) {
                int left_interval = dp[p-1][i];
                int right_interval = dp[p-1][i + (1 << (p - 1))];
                dp[p][i] = max(left_interval, right_interval);

                if(left_interval > right_interval){
                    it[p][i] = it[p-1][i];
                }
                else {
                    it[p][i] = it[p-1][i + (1 << (p - 1))];
                }
            }
        }
    }

    // O(1) as min has no issue with overlapping, but this is not the case with sum, multiply
    int query_max(int l, int r){
        int len = r - l + 1;
        int p = log2[len];
        int k = 1 << p;
        return max(dp[p][l], dp[p][r - k + 1]);
    }

    int query_max_index(int l, int r){
        assert(l <= r);
        assert(0 <= l and l < N);
        assert(0 <= r and r < N);

        int len = r - l + 1;
        int p = log2[len];
        int k = 1 << p;
        int left_interval = dp[p][l];
        int right_interval = dp[p][r - k + 1];
        if(left_interval > right_interval) return it[p][l];
        return it[p][r - k + 1];
    }

    int size(){ return N; }
};

vi res(100);
set<int> s;
void generate(MaxSparseTable &st, int l, int r, int depth){
    if(l > r) return;
    if(l == r){
        res[l] = depth;
        return;
    }
    int id = st.query_max_index(l, r);
    assert(0 <= id and id < st.size());
    assert(s.count(id) == 0);
    s.insert(id);
    res[id] = depth;
    generate(st, l, id - 1, depth + 1);
    generate(st, id + 1, r, depth + 1);
}

void solve(){
    s.clear();
    int n;
    cin>>n;
    vi a(n);
    read(a);
    assert(a.size());
    for (int i = 0; i < n; i++) res[i] = 0;

    MaxSparseTable st(a);
    // db(a);
    // db(st.query_max_index(0, n-1));
    generate(st, 0, n-1, 0);

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
