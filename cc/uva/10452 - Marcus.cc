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

string s = "IEHOVA";
int n, m;

bool inside(int j, int i){
    return 0 <= i and i < n and 0 <= j and j < m;
}

string command[3] = {"left", "right", "forth"};

int dx[3] = {-1, 1, 0};
int dy[3] = {0,0,-1};
void dfs(int x, int y, vvc &b, int pos){
    for(int i = 0; i < 3; i++){
        int xi = x + dx[i], yi = y + dy[i];
        if(not inside(xi,yi)) continue;
        if(pos == sz(s)){
            if(b[yi][xi] == '#'){
                cout<<command[i];
                return;
            }
        }
        else if(b[yi][xi] == s[pos]){
            cout<<command[i]<<' ';
            dfs(xi,yi,b,pos+1);
            return;
        }
    }
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        cin>>n>>m;
        vvc b(n, vc(m));
        REP(i,n) read(b[i]);

        int x, y = n-1;
        for(x = 0; x < m; x++) if(b[y][x] == '@') break;
        dfs(x,y,b,0);
        cout<<endl;
    }
    return 0;
}
