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
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

vi gen(int n){
    vi v(5);
    v[0] = n / 5;
    for (int i = 1; i < 5; i++) {
        v[i] = (n / 5) + (n % 5 >= i);
    }
    return v;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, m;
    cin>>n>>m;
    vi an = gen(n), am = gen(m);
    ll ans = 0;;
    for (int i = 0; i < 5; i++) {
        ans += (ll) an[i] * am[(5 - i) % 5];
    }
    cout << ans << endl;
    return 0;
}