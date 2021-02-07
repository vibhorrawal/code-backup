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
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

ll ncr(ll n, ll r){
    db(n);
    db(r);
    ll res = 1, div = 1;
    for(int i = n - r + 1, j = 1; i <= n; i++, j++) {
        res = (res * i) / j;
        div *= j;
    }
    db(res);
    return res;
}
int32_t main(int argc, char const *argv[]){
    int n, m, t;
    cin >> n >> m >> t;
    ll ans = 0;
    for(int c = 1; c <= t - 4; c++){
        ans += ncr(m, c) * ncr(n, t - c);
    }
    cout << ans << endl;
    return 0;
}
