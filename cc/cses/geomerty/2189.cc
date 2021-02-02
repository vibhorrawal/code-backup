// point location test
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

struct P{
  long long x, y;
  P operator-(const P &b) const {
    return P{x - b.x, y - b.y};
  }
  long long operator* (const P &b) const {
    return  x * b.y - y * b.x;
  }
  bool operator<(const P &b) const {
    return make_pair(x, y) < make_pair(b.x, b.y);
  }
  long long area(const P &b, const P &c) const {
    return (b - *this) * (c - *this);
  }
  void read(){
    cin >> x >> y;
  }
};

int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
      P p1,p2,p3;
      p1.read();
      p2.read();
      p3.read();

      ll sign = (p2 - p1) * (p3 - p1);
      if(sign < 0){
        cout << "RIGHT" << endl;
      }
      else if(sign > 0){
        cout << "LEFT" << endl;
      }
      else cout << "TOUCH" << endl;
  }
  return 0;
}
