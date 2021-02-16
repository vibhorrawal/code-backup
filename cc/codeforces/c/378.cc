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
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

vector<vector<char>> v;
vvi vis;
int n,m,k;

inline bool inside(int i, int j){
    return 0 <= i and i < n and 0 <= j and j < m;
}

vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};

void display(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<vis[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void dfs(int i, int j, int &remain){
    if(not inside(i,j)) return;
    if(remain <= 0) return;
    if(v[i][j] != '.' or vis[i][j]) return;
    db(remain, i, j);
    // display();
    vis[i][j] = true;
    remain--;
    for(auto it : d){
        db(i + it.first, j + it.second);
        dfs(i + it.first, j + it.second, remain);
    }
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    cin>>n>>m>>k;
    v = vector<vector<char>>(n, vector<char> (m));
    int S = 0;
    vis = vvi(n, vi(m, false));
    REP(i,n) read(v[i]);

    int ii,jj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(v[i][j] == '.'){
                S++;
                ii = i;
                jj = j;
            }
        }
    }
    int remain = S - k;
    dfs(ii,jj,remain);
    assert(not remain);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(v[i][j] != '.' or vis[i][j])
                cout << v[i][j];
            else cout << 'X';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
