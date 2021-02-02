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

void dfs(int u, vector<vector<int>> &g, vector<bool> &vis, stack<int> &st){
  // if(vis[u]) return;
  vis[u] = true;
  for(int v : g[u]){
    if(not vis[v]) dfs(v,g,vis,st);
  }
  st.push(u);
}

int dfs2(int u, vector<vector<int>> &tr, vector<bool> &vis){
  if(vis[u]) return 0;
  int c = vis[u] == false;
  vis[u] = true;
  for(int v : tr[u]) c += dfs2(v, tr, vis);
  return c;
}

int connectedSum(int n, vector<int> from, vector<int> to){
  vector<vector<int>> g(n + 1), tr(n + 1);
  vector<int> in(n + 1);
  for(int i = 0; i < to.size(); i++){
    int u = from[i], v = to[i];
    g[u].push_back(v);
    in[v]++;
    // tr[v].push_back(u);
  }
  // stack<int> st;
  vector<bool> vis(n + 1, false);
  // for(int i = 1; i <= n; i++){
  //   if(not vis[i]) dfs(i, g, vis, st);
  // }

  // fill(vis.begin(), vis.end(), false);
  int ans = 0;

  for(int i = 1; i <= n; i++){
    if(in[i] == 0){
      ans += ceil(sqrt(dfs2(i, g, vis)));
    }
  }
  return ans;
  // while(st.size()){
  //   int u = st.top(); st.pop();
  //   if(vis[u]) continue;
  //   // db(u);
  //   double w = dfs2(u, g, vis);
  //   // cout<<w<<endl;
  //   ans += (int) ceil(sqrt(w));
  // }
  // return ans;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  vector<int> f = {6,9,11,15,13,12,15,1}, t = {5,9,9,15,14,16,16};
  cout<< connectedSum(16, f, t);
  return 0;
}
