// polygon area
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

struct P {
  ll x, y;
  void read(){
    cin >> x >> y;
  }
  P operator- (P b){
    return {x - b.x, y - b.y};
  }

  ll operator* (P b){
    return x * b.y - y * b.x;
  }

  ll area(P b, P c){
    return (b - *this) * (c - *this);
  }
};

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin >> n;
  P p[n];
  REP(i,n) p[i].read();
  ll area = 0;
  for (int i = 0; i < n; i++) {
    // area += p[0].area(p[i] - p[0], p[(i == n-1 ? 0 : i+1)] - p[0]);
    area += p[i] * p[(i == n-1 ? 0 : i+1)];
  }
  cout << abs(area) << endl;
  return 0;
}
