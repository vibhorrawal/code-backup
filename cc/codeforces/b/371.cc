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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int a, b;
  cin >> a >> b;
  int div[6] = {0};
  for(int x : {2,3,5}) {
    while(a % x == 0) {
      div[x]++;
      a /= x;
    }
    while(b % x == 0) {
      div[x]--;
      b /= x;
    }
  }
  if(a != b) {
    cout << "-1" << endl;
  }
  else {
    int ans = 0;
    for(int d : div) ans += abs(d);
    cout << ans << endl;
  }
}
