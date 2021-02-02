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

class A{
public:
  int a,b;
  A(){
    a = 0, b = 0;
    cout << "def called" << endl;
  }
  A(int i, int j){
    a = i, b = j;
    cout << "arg called" << endl;
  }
};
bool cmp(A &a, A &b){
  return a.a < b.a;
}
int32_t main(int argc, char const *argv[]){
    vector<A> v;
    for (int i = 0; i < 100; i++) {
      A t = A(10,20);
      v.push_back(t);
    }

    cout << "sorting" << endl;

    sort(v.begin(), v.end(), cmp);
  return 0;
}
