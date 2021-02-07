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

const int mod = 1e9 + 7;
ll binpow(ll a, ll b, ll M = mod){
    a %= M;
    ll res = 1;
    while(b){
        if(b & 1) res = ((__int128) res * a) % M;
        a = ((__int128) a * a) % M;
        b >>= 1;
    }
    return res;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    const int M = 1e9 + 5;
    T(){
        ll a, b, n;
        cin >> a >> b >> n;
        // GCD(AN+BN, A-B) = GCD(A-B, (AN+BN)%(A-B))
        if(a == b){
            cout << (binpow(a, n) + binpow(b, n)) % M << endl;
        }
        else{
            ll d = (binpow(a, n, a - b) + binpow(b, n, a - b)) % (a - b);
            cout << __gcd(d, (a - b)) % M << endl;
        }
    }
    return 0;
}
