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

vi factors(int n){
    vi v;
    for (int i = 2; i <= n; i++) {
        if(n % i) continue;
        // int m = n;
        while(n % i == 0) n /= i;
        // n = m;
        v.pb(i);
    }
    db(v);
    return v;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    int n;
    cin>>n;
    vi v(n);
    read(v);
    vi ff = factors(n);
    ff.pb(n);
    if(n % 2 == 0) ff.pb(4);
    bool flag = true, possible = false;;
    for (int i = 0; i < n; i++) {
        if(not v[i]) continue;
        for(int f : ff) {
            // i = 3, f = 3;
            db(f);
            flag = true;
            int d = n / f;
            if(f < 3) continue;
            for (int j = 0, cnt = 0; cnt < f; j += d, cnt++) {
                flag = flag and v[(i + j) % n];
            }
            // exit(0);
            if(flag) possible = true;
            if(possible) goto PRINT;
        }
    }
    PRINT:
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}
