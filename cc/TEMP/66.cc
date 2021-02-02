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

int maximumLearning(vector<int> iv, vector<int> aa, int W){
  int n = aa.size();
  vector<long> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = ((long)aa[i]) * 2;
  }
  vector<vector<long>> dp(n + 1, vector<long> (W + 1, 0));

  for(int i = 1; i < n + 1; i++){
      for(int j = 1; j < W + 1; j++){
        if(j >= a[i-1])
            dp[i][j] = max(dp[i-1][j], iv[i-1] + dp[i-1][j - a[i-1]]);
        else
            dp[i][j] = dp[i-1][j];
      }
  }
  return dp[n][W];
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int W = 15;
  vector<int> iv = {3,2,2};
  vector<int> a = {2,2,3,4};
  cout<<maximumLearning(iv, iv, 9);
  return 0;
}
