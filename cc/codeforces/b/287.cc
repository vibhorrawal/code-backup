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

ll sigma(ll n){
    if(n < 1) return 0;
    return n * (n + 1)/2;
}

bool f(ll m, ll k, ll n){
    ll res = sigma(k) - sigma(k-m);
    return res >= n;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    ll n, k;
    cin>>n>>k;
    // #warning "n for 1"
    db(n);
    n--, k--;
    if(n > k * (k + 1) / 2){
        cout << "-1" << endl;
        return 0;
    }
    ll l = 0, r = n, ans = n;
    while(l <= r){
        ll m = l + (r - l)/2;
        if(f(m, k, n)){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans << endl;
    return 0;
}
