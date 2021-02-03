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
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int32_t main(int argc, char const *argv[]){
  fastIO;
  string s;
  cin>>s;
  int B = 0, S = 0, C = 0;
  for(char c : s) {
    if(c == 'B') B++;
    if(c == 'S') S++;
    if(c == 'C') C++;
  }

  int nb, ns, nc;
  cin>>nb>>ns>>nc;
  int pb, ps, pc;
  cin>>pb>>ps>>pc;
  ll r;
  cin >> r;

  ll cnt = 0;
  while(nb >= B and nc >= C and ns >= S){
    cnt++;
    nb -= B;
    nc -= C;
    ns -= S;
  }
  db(cnt);
  int cost_of_one = pb * B + pc * C + ps * S;
  db(cost_of_one);
  cnt += r / cost_of_one;
  r %= cost_of_one;
  db(cnt);
  db(r);
  int cost_b = max(0, pb * (B - nb));
  int cost_s = max(0, ps * (S - ns));
  int cost_c = max(0, pc * (C - nc));

  cnt += r >= cost_b + cost_c + cost_s;
  cout << cnt << endl;
  return 0;
}
