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

bool is_prime(ll n){
    if(n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n;
    cin>>n;
    REP(i,n){
        ll t;
        cin>>t;
        ll k = sqrt(t);
        if(k * k != t){
            cout << "NO" << endl;
            continue;
        }
        cout << (is_prime(k) ? "YES" : "NO") << endl;
    }
    return 0;
}
