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

inline bool gym(int n){
    return (n>>1) & 1;
}
inline bool contest(int n){ return n & 1; }

int main(){
    fastIO;
    int n;
    cin>>n;
    vi a(n);
    read(a);
    int dp[101][3];
    const int INF = 1e9 + 5;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 3; j++) {
                dp[i][j] = 0;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = gym(a[0]);
    dp[0][2] = contest(a[0]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        if(gym(a[i])) dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
        if(contest(a[i])) dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
    }
    cout << n - max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
    return 0;
}
/*
ll ans;
bool memo[101][2][2][101] = {0};

void dfs(vi &a, int i, bool yg, bool yc, ll cnt){
    if(ans == 0) return;
    if(i == sz(a)){
        ans = min(ans, cnt);
        return;
    }
    if(memo[i][yg][yc][cnt]) return;
    memo[i][yg][yc][cnt] = true;

    int t = a[i];
    if(not gym(t) and not contest(t))
        dfs(a, i+1, false, false, cnt + 1);
    else if(gym(t) and contest(t)){
        // if(yc and yg) dfs(a, i+1, false, false, cnt + 1);
        if(yc) dfs(a, i+1, true, false, cnt);
        else if(yg) dfs(a, i+1, false, true, cnt);
        else {
            dfs(a, i+1, true, false, cnt);
            dfs(a, i+1, false, true, cnt);
        }
    }
    else if(gym(t)){
        if(yg) dfs(a, i+1, false, false, cnt+1);
        else dfs(a, i+1, true, false, cnt);
    }
    else if(contest(t)){
        if(yc) dfs(a, i+1, false, false, cnt+1);
        else dfs(a, i+1, false, true, cnt);
    }
    else assert(false);
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n;
    cin>>n;
    vi a(n);
    read(a);
    ans = INT_MAX;
    dfs(a, 0, false, false, 0);
    cout << ans << endl;
    return 0;
}
*/
