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
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int n;

bool inside(int i, int j){
    return 0 <= i and i < n and 0 <= j and j < n;
}

// int dx[8] = {-1,-1,-1,0,0,1,1,1};
// int dy[8] = {-1,0,1,-1,1,-1,0,1};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void fill(int i, int j, vvc &v){
    v[i][j] = '.';
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if(not inside(x,y)) continue;
        if(v[x][y] != '.') fill(x,y,v);
    }
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; t++){
        cin>>n;
        vvc v(n, vc(n));
        REP(i,n) read(v[i]);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(v[i][j] == 'x'){
                    cnt++;
                    fill(i,j,v);
                }
            }
        }
        cout << "Case "<<t<< ": "<< cnt << endl;
    }
    return 0;
}
