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

void solve(){
    int n;
    cin>>n;
    unordered_map<int,int> cnt;
    REP(i,n){
        int t;
        cin>>t;
        cnt[t]++;
    }
    vi v;
    for(auto [i,c] : cnt) v.pb(c);
    sort(all(v));
    ll res = INT_MAX, ans = 0;
    vi v2 = v;
    v2.resize(unique(v2.begin(), v2.end()) - v2.begin());
    for(int d : v2){
        ans = 0;
        for(int i = 0; i < v.size(); i++) {
            if(d > v[i]) ans += v[i];
            else ans += v[i] - d;
        }
        res = min(ans, res);
    }
    cout << res << endl;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        solve();
    }
    return 0;
}
