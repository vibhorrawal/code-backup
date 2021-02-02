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

int getMostVisited(int n, vector<int> a){
  vector<int> v(n + 2, 0);
  for (int i = 1; i < n; i++) {
    int aa = a[i-1], b = a[i];
    if(aa > b) swap(aa, b);
    v[aa] += 1;
    v[b+1] -= 1;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    v[i] += v[i-1];
    ans = max(ans, v[i]);
  }
  return ans;
}

void superStack(vector<string> p){
  vector<int> v, z;
  for(auto a : p){
    if(a[1] == 'o'){
      if(z.size() > 1) z[z.size()-2] += z.back();
      v.pop_back();
      z.pop_back();
      if(v.size() == 0) {
        cout << "EMPTY" << endl;
      }
      else{
        cout << v.back() + z.back() << endl;
      }
    }
    else if(a[1] == 'u'){
      string x = a.substr(5, a.size());
      int k = stoi(x);
      v.push_back(k);
      z.push_back(0);
      cout << k << endl;
    }
    else{
      string x = a.substr(4, a.size());
      string q,w;
      int flag = 0;
      for(int i = 0; i < x.size(); i++){
        if(x[i] == ' '){
          flag = 1;
        }
        else if(flag == 0){
          q += x[i];
        }
        else w += x[i];
      }
      int ii = stoi(q), vv = stoi(w);
      z[ii-1] += vv;
      cout << v.back() + z.back() << endl;
    }
  }
}

int activateFountain(vector<int> v){
  int n = v.size();
  vector<int> z(n + 1, INT_MAX);
  z[0] = 0;
  for(int i = 0; i < n; i++){
    int f = i + 1;
    int mn = INT_MAX;
    for(int j = f; j >= max(0, f - v[i]-1); j--) mn = min(mn, z[j]);
    for(int j = f; j <= min(n, f + v[i]); j++) z[j] = min(mn + 1, z[j]);
  }
  cout << to_string(z) << endl;
  return *max_element(z.begin(), z.end());
}

int fun(vector<int>v){
    int n=v.size();
    vector<int>z(n+1,INT_MAX);
    z[0]=0;
    for(int i=0;i<n;i++){
        int f=i+1;
        int mn=INT_MAX;
        for(int j=f;j>=max(0,f-v[i]-1);j--)mn=min(mn,z[j]);
        for(int j=f;j<=min(n,f+v[i]);j++)z[j]=min(mn+1,z[j]);
    }
    cout << to_string(z) << endl;
    int mn=0;
    for(auto a:z){
        mn=max(mn,a);
    }
    return mn;
}

int32_t main(int argc, char const *argv[]){
  fastIO;
  cout << activateFountain({1,1,9}) << endl;
  db(2);
  cout << fun({1,1,9}) << endl;
  return 0;
}
