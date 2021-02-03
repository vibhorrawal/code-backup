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
#define pb emplace_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

const int S = 1<<31;

void solve(int n, vi &v){
  vector<bool> check(n+1, true);
  check[0] = false;
  for(int x : v){
    for(int i = x; i <= n; i+= x) {
      check[i] = false;
    }
  }
  int ans = accumulate(check.begin(), check.end(), 0);
  cout << ans << endl;
}
int32_t main(int argc, char const *argv[]){
  int n, m;

  while(cin >> n >> m){
    // cin >> n >> m;
    vi v(m);
    read(v);
    solve(n, v);
  }
  return 0;
}
