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
    vi res;
    vector<pii> a(n);
    ll lsum = 0, rsum = 0;
    REP(i, n){
        int t;
        cin>>t;
        a[i].first = t;
        a[i].second = i+1;
        lsum += t;
    }
    sort(all(a));

    res.pb(a.back().second);
    for(int i = n-1; i >= 1; i--){
        lsum -= a[i].first;
        rsum += a[i].first;
        if(lsum >= a[i].first) res.pb(a[i-1].second);
    }

    sort(all(res));
    cout<<res.size()<<endl;
    cout<<to_string(res);
    cout<<endl;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        solve();
    }
    return 0;
}
