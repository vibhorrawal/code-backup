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

vector<vector<ll>> memo(101, vector<ll> (101, -1));

ll ncr(ll n, ll r){
    if(r == 0 or r == n) return 1;
    if(n == 1) return 1;
    if(memo[n][r] != -1) return memo[n][r];
    return memo[n][r] = ncr(n-1, r) + ncr(n-1, r-1);
}
int main(){
    fastIO;
    ll n, m;
    while(cin>>n>>m){
        if(n == 0) break;
        cout << n <<" things taken " << m << " at a time is " << ncr(n,m) << " exactly." << endl;
    }
    return 0;
}

/*
ll ncr(ll n, ll r){
    ll res = 1;
    for (int i = n - r + 1; i <= n; i++) {
        res *= i;
        db(res);
    }
    for (int i = 1; i <= r; i++) {
        res /= i;
        db(res);
    }
    return res;
}
vector<vector<ll>> dp(101, vector<ll> (101));
void gen(){
    const int M = 101;
    for (ll n = 1; n < M; n++) {
        for (ll r = 0; r <= n; r++) {
            if(r == 0) dp[n][r] = 1;
            else if(r == n) dp[n][r] = 1;
            else dp[n][r] = dp[n-1][r] + dp[n-1][r-1];
        }
    }
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    gen();
    ll n, m;
    while(cin>>n>>m){
        if(n == 0) break;
        cout << n <<" things taken " << m << " at a time is " << dp[n][m] << " exactly." << endl;
    }
    return 0;
}
*/
