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

// int dfs(int i, int s[], int a[]){
//     if(a[i] == -1){
//         s[i] = 0;
//         return 0;
//     }
//     return s[i] = 1 + dfs(a[i], s, a);
// }
// int totalParents(int n, int x, int a[]){
//     vvi g(n);
//     for (int i = 0; i < n; i++) {
//         if(a[i] == -1) continue;
//         g[a[i]].pb(i);
//     }
//     vi vis(n), s(n);
//
//     for (int i = 0; i < n; i++) {
//         dfs()
//     }
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         ans += s[i] >= x;
//     }
//     return ans;
// }

int conversion(int n){
    int nn = n;
    int ans = -1;
    int d = 2;
    while(n != 1){
        while(n % d == 0) {
            n /= d;
            ans = d;
        }
        d++;
    }
    if(ans == nn) return -1;
    return ans;
}
int32_t main(int argc, char const *argv[]){
    int a[] = {-1,0,0};
    // cout<<totalParents(3,1,a);
    db(conversion(23));
}
