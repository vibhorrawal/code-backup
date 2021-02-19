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
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        int n;
        cin>>n;
        vi a(n);
        read(a);
        ll c[3] = {0};
        for (int i = 0; i < n; i++) {
            c[a[i] % 3]++;
        }
        ll req = n / 3;
        ll ans = 0;
        while(1){
            if(c[0] == req and c[1] == req and c[2] == req) break;
            for(int i = 0; i < 3; i++){
                ll del = max(0ll, c[i] - req);
                ans += del;
                c[i] -= del;
                c[(i + 1) % 3] += del;
            }
        }
        cout <<ans << endl;
    }
    return 0;
}
