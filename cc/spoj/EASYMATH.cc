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


ll lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}

ll find(int n, vector<ll> &ai){
    if(n < 2) return 0;
    int k = ai.size();
    ll res = 0;
    for (int bit = 0; bit < (1<<k); bit++) {
        ll cnt = 1, sign = 1;
        for (int i = 0; i < k; i++) {
            if((bit>>i) & 1){
                    sign *= -1;
                    cnt = lcm(cnt, ai[i]);
            }
        }
        res += sign * n / cnt;
    }
    return res;
}

ll go(int pos, ll cnt, ll me, ll upto, vector<ll> &ai){
    if(pos == ai.size()){
        if(cnt % 2) return - me / upto;
        else return me / upto;
    }

    ll res = 0;
    res += go(pos + 1, cnt + 1, me, lcm(upto, ai[pos]), ai);
    res += go(pos + 1, cnt, me, upto, ai);
    return res;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        ll n, m, a, d;
        cin>>n>>m>>a>>d;
        ll ans = 0;
        vector<ll> ai;
        for(int i = 0; i < 5; i++) ai.pb(a + i * d);
        cout << find(m, ai) - find(n-1, ai) << endl;
        // cout << go(0,0,m,1, ai) - go(0,0,n-1,1,ai) << endl;

    }
    return 0;
}
