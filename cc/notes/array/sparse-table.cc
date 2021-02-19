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

// mmin, max, sum, multiply, gcd
// or any associative function, and immutable input array

template<typename T> class SparseTable {
    //----------------------------------
    T f(T a, T b){
        #warning "change this function and INITIAL_VALUE according to your need"
        return min(a,b);
    }
    const T INITIAL_VALUE = INT_MAX;
    //----------------------------------

    int N, P;
    vector<int> log2;
    vector<vector<T>> dp;

public:
    SparseTable(vector<T> values){
        init(values);
    }

    void init(vector<T> &arr){
        N = arr.size();
        P = log(N) / log(2);
        dp = vector<vector<T>>(P + 1, vector<T>(N));
        for(int i = 0; i < N; i++)
            dp[0][i] = arr[i];
        log2 = vector<int>(N + 1);
        for(int i = 2; i <= N; i++)
            log2[i] = log2[i / 2] + 1;

        for(int i = 1; i <= P; i++){
            for(int j = 0; j + (1 << i) <= N; j++) {
                T left_interval = dp[i-1][j];
                T right_interval = dp[i-1][j + (1 << (i - 1))];
                dp[i][j] = f(left_interval, right_interval);
            }
        }
    }

    T query(int l, int r){
        T res = INITIAL_VALUE;
        for(int p = log2[r - l + 1]; l <= r; p = log2[r - l + 1]){
            res = f(res, dp[p][l]);
            l += (1 << p);
        }
        return res;
    }
};

int32_t main(int argc, char const *argv[]){
    SparseTable<int> s({4, 2, 3, 7, 1, 5, 3, 3, 9, 6, 7, -1, 4});
    cout<<s.query(0, 5);
    return 0;
}
