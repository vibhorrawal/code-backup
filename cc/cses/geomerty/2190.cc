// line segment intersection
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
  ll x,y;
  void read(){
    cin >> x >> y;
  }
  P operator- (P b){
    return {x - b.x, y - b.y};
  }

  ll operator* (P b) const {
    return x * b.y - y * b.x;
  }

  ll area (P b, P c){
    return (b - *this) * (c - *this);
  }
};

bool same_side(P p1, P p2, P p3, P p4){
  ll sign_p3 = (p2 - p1) * (p3 - p1);
  ll sign_p4 = (p2 - p1) * (p4 - p1);

  if(sign_p3 > 0 and sign_p4 > 0) return true;
  if(sign_p3 < 0 and sign_p4 < 0) return true;
  return false;
  // return not ((sign_p3 > 0) ^ (sign_p4 > 0));
  // ? what was the error here : UPDATE: since one can == 0 -> then this XOR technique won't work, better to use ifs
}

inline bool is_parallel(P p1, P p2, P p3, P p4){
  return (p2 - p1) * (p4 - p3) == 0;
}
inline bool bounding_box_disjoint(P p1, P p2, P p3, P p4){
  for (int rep = 0; rep < 2; rep++) {
    if(max(p1.x, p2.x) < min(p3.x, p4.x) or max(p1.y, p2.y) < min(p3.y, p4.y))
        return true;
      swap(p1,p3);
      swap(p2,p4);
  }
  return false;
}

void solve(){
  P p[4];
  REP(i,4) p[i].read();

  // check for bounding box intersection when lines are parallel
  if(is_parallel(p[0], p[1], p[2], p[3])){
    if(p[0].area(p[1], p[2]) != 0){
      cout << "NO" << endl;
      return;
    }
    if(bounding_box_disjoint(p[0], p[1], p[2], p[3])){
      cout << "NO" << endl;
      return;
    }
    cout << "YES" << endl;
    return;
  }

  // check for both ps on different side of LINE
  if(same_side(p[0], p[1], p[2], p[3])
      or same_side(p[2], p[3], p[0], p[1])){
      cout << "NO" << endl;
      return;
    }

    cout << "YES" << endl;
    return;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    solve();
  }
  return 0;
}
