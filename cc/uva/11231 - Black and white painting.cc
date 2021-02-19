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

ll boards(ll n, ll m){
    // if(n < 8 or m < 8) return 0;
    return (1 + (n - 7) * (m - 7)) / 2;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, m, c;
    while(cin>>n>>m>>c){
        if(n == 0 and m == 0 and c == 0) break;
        if(c == 1) cout << ((n-7) * (m - 7) + 1) / 2 << endl;
        else cout << (n - 7) * (m - 7) / 2 << endl;
    }
    return 0;
}
