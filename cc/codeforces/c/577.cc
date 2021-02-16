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
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

vvi factors(int n){
    vvi res;
    for (int i = 2; i <= n; i++) {
        if(n % i) continue;
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        db(i, cnt);
        res.pb({i, cnt});
    }
    return res;
}

vi get_primes(int n){
    vi p(n + 1, true);
    for (int i = 2; i * <= n; i++) {
        if(not p[i]) continue;
        for (int j = i * i; j <= n; j+= i) {
            p[j] = false;
        }
    }
    vi res;
    for (int i = 2; i < n + 1; i++) {
        if(p[i]) res.pb(i);
    }
    return res;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    int n;
    cin>>n;
    // vvi f = factors(n);
    vi p = get_primes(n);
    string out;
    int cnt = 0;
    for(int x : p){
        ll d = x;
        while(n >= x) {
            out += to_string(x) + " ";
            x *= d;
            cnt++;
        }
    }
    cout << cnt << endl;
    cout << out << endl;
    return 0;
}
