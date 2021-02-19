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

ll cnt(ll b, ll a){
    ll res = 0;
    a *= 2;
    while(a < b){
        a *= 2;
        res++;
    }
    return res;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        int n;
        cin>>n;
        vi a(n);
        read(a);
        ll ans = 0;
        for(int i = 0; i < n-1; i++){
            if(a[i] > a[i+1]){
                ans += cnt(a[i], a[i+1]);
            }
            else ans += cnt(a[i+1], a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
