#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef pair<int,int> pii;
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define endl char(10)
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

int img = 0;

bool inside(int i, int j, int n){
    return 0 <= i and i < n and 0 <= j and j < n;
}
int dx[] = {0,0,-1,-1,-1,1,1,1};
int dy[] = {1,-1,-1,0,1,-1,0,1};
void dfs(int i, int j, vvc &v){
    int n = sz(v);
    v[i][j] = '0';
    for (int k = 0; k < 8; k++) {
        int xi = i + dx[k], yi = j + dy[k];
        if(not inside(xi, yi, n)) continue;
        if(v[xi][yi] == '1') dfs(xi, yi, v);
    }
}
void solve(int n){
    vector<vector<char>> v(n, vector<char>(n));
    REP(i,n) read(v[i]);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(v[i][j] == '1'){
                dfs(i,j,v);
                cnt++;
            }
        }
    }
    cout<<"Image number "<< ++img << " contains "<< cnt << " war eagles."<<endl;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n;
    while(cin>>n){
        solve(n);
    }
    return 0;
}
