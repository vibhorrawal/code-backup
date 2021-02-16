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

int main(){
  ll n;
  cin>>n;
  ll ans = 1;
  for(ll i = 2; i * i <= n; i++){
    if(n % i == 0){
      while(n % i == 0) n /= i;
      ans *= i;
    }
  }
  cout << ans * n << endl;
}
/*
int32_t main(int argc, char const *argv[]){
  fastIO;
  ll n;
  cin>> n;
  recheck:
  ll s = sqrt(n) + 1;
  for (ll i = 2; i <= s; i++) {
    if(n % (i * i) == 0) {
      n /= i;
      goto recheck;
    }
  }
  cout << n << endl;
  return 0;
}
*/