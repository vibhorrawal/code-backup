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

vi nxt;


int get_next(int v){
    if(v >= sz(nxt)) return v;
    if(nxt[v] == v) return v;
    return nxt[v] = get_next(nxt[v]);
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, m;
    cin>>n>>m;
    vi w(n + 1);
    // set<int> alive;
    nxt = vi(n + 1);
    for (int i = 1; i <= n; i++) {
        // alive.insert(i);
        nxt[i] = i;
    }
    REP(i,m){
        int l, r, x;
        cin>>l>>r>>x;
        int curr = get_next(l);
        while(curr <= r){
            if(curr == x) curr++;
            else {
                w[curr] = x;
                nxt[curr] = get_next(curr + 1);
            }
            curr = get_next(curr);
        }
    }

    for(int i = 1; i <= n; i++) cout<<w[i]<<' ';cout<<endl;
    return 0;
}
/*
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, m;
    cin>>n>>m;
    vi w(n + 1);
    set<int> alive;
    for (int i = 1; i <= n; i++) {
        alive.insert(i);
    }
    REP(i,m){
        int l, r, x;
        cin>>l>>r>>x;
        auto lt = alive.lower_bound(l);
        auto rt = alive.upper_bound(r);
        for (auto it = lt; it != rt; it++) {
            if(*it != x) w[*it] = x;
        }
        alive.erase(lt, rt);
        alive.insert(x);
    }

    for(int i = 1; i <= n; i++) cout<<w[i]<<' ';cout<<endl;
    return 0;
}
*/
