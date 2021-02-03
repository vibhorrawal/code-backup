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

const int SZ = 10000000;
vi generate_primes(){
  vector<bool> v(SZ, true);
  for(int i = 2; i * i <= SZ; i++){
    if(v[i] == false) continue;
    for(int p = 2 * i; p < SZ; p += i) v[p] = false;
  }
  vi res;
  for(int i = 2; i < SZ; i++) if(v[i]) res.pb(i);
  return res;
}
int32_t main(int argc, char const *argv[]){
  int n;
  vi p = generate_primes();
  while(cin >> n){
    for(int x : p){
      if(x > n) break;
      for(int y : p){
        if(y > n) break;
        for(int z : p){
          if(z > n) break;
          int target = n - ((ll) x + y + z);
          if(binary_search(p.begin(), p.end(), target)){
            cout << x << ' '<< y << ' ' << z << ' ' << target << endl;
            goto NEXT;
          }
        }
      }
    }
    cout << "Impossible" << endl;
    NEXT:
    int i;
  }
  return 0;
}
