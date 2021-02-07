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

void find(vi &p, int n){
    for (int i = 0; p[i] <= n>>1; i++) {
        if(binary_search(all(p), n - p[i])){
            cout << p[i] << ' ' << n - p[i] << '\n';
            return;
        }
    }
}
int32_t main(int argc, char const *argv[]){
  int n;
  vi p = generate_primes();
  while(cin >> n){
    if(n <= 7) cout << "Impossible.\n";
    else {
        if(n % 2){
            cout << "2 3 ";
            n -= 5;
            find(p, n);
        }
        else{
            cout << "2 2 ";
            n -= 4;
            find(p, n);
        }
    }
  }
  return 0;
}
