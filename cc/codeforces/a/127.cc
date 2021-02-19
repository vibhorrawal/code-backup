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

double dist(int xa, int ya, int xb, int yb){
    double d = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
    return sqrt(d);
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, k;
    cin>>n>>k;
    vi x(n), y(n);
    REP(i,n) cin>>x[i]>>y[i];
    double ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans += dist(x[i], y[i], x[i+1], y[i+1]);
    }

    cout << fixed << setprecision(9) << (k * ans) / 50 << endl;
    return 0;
}
