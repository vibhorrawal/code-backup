#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<pii>> vvp;
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
#ifdef LOCAL
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define db(...) {}
#endif

int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};

const int E = 1e9;
bool is_inside(int x, int y, unordered_map<int, vector<pii>> &row){
    if(x < 1 or x > E or y < 1 or y > E) return false;
    for(auto &it : row[x]){
        if(it.first <= y and it.second <= y) return true;
    }
    return false;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int x0,y0, x1, y1;
    cin>>x0>>y0>>x1>>y1;
    // x0--,y0--, y0--, y1--;
    vi x, y; // queue
    map<pair<int,int>,int> dist;
    unordered_map<int, vector<pii>> row;
    x.pb(x0); y.pb(y0);
    dist[{x0, y0}] = 1;
    int n;
    cin>>n;
    REP(i,n) {
        int r, a, b;
        cin>>r>>a>>b;
        // r--,a--,b--;
        row[r].push_back({a, b});
    }
    queue<pii> q;
    q.push({x0, y0});
    while(sz(q)){

    }
    cout << "-1" << endl;
    return 0;
}
