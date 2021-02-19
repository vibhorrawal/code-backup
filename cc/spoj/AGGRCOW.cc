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

bool f(int dist, vi &v, int c){
    int prev = INT_MIN, cnt = 0;
    for(int x : v){
        if(x >= prev + dist){
            cnt++;
            prev = x;
        }
    }
    return cnt >= c;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        int n, c;
        cin>>n>>c;
        vi v(n);
        read(v);
        sort(all(v));
        int l = 0, r = 1e9;
        int ans = 0;
        while(l <= r){
            int m = (l + r)/2;
            if(f(m, v, c)){
                l = m + 1;
                ans = m;
            }
            else r = m - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
