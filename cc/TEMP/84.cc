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

int plantrip(vector<int> moneyDistributed, int numPairs, vector<vector<int>> coldWarMembers){
    vector<vector<int>> g(8);
    for(auto it : coldWarMembers){
        int u = it[0]-1, v = it[1]-1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<"[";
    for (int i = 0; i < g.size(); i++) {
        cout<<"[ ";
        for (int j = 0; j < sz(g[i]); j++) {
            cout<<g[i][j]<<", ";
        }
        cout<<"], ";
    }
    cout<<"]\n";
    int ans = 0;
    for (int bit = 0; bit < (1<<8); bit++) {
        int cost = 0;
        for (int i = 0; i < 8; i++) {
            bool possible = true;
            if((bit>>i) & 1){
                for(int v : g[i]) {
                    if((bit>>v) & 1) {
                        // goto HELL;
                        possible = false;
                        break;
                    }
                }
                if(not possible) break;
                cost += moneyDistributed[i];
            }
        }
        ans = max(ans, cost);
        // HELL:
        // int j;
    }
    return ans;
}

void solve(){
    vi a(8);
    read(a);
    int p;cin>>p;
    vvi v(p, vi(2));
    REP(i,p) read(v[i]);
    cout << plantrip(a, p, v) << endl;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    solve();
    return 0;
    vi a(8);
    read(a);
    int p;
    cin>>p;
    vvi g(8);
    REP(i,p){
        int x, y;
        cin>>x>>y;
        x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    int ans = 0;
    for (int bit = 0; bit < (1<<8); bit++) {
        int cost = 0;
        for (int i = 0; i < 8; i++) {
            if((bit>>i) & 1){
                for(int v : g[i]) {
                    if((bit>>v) & 1) goto HELL;
                }
                cost += a[i];
            }
        }
        ans = max(ans, cost);
        HELL:
        int j;
    }

    cout<<ans<<endl;
    return 0;
}
