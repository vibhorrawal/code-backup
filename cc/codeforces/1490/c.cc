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

bool is_int(ll n){
    ll sq = sqrt(n);
    return sq * sq == n;
}
void solve(ll N){
    double d = 1;
    d /= 3;
    ll a = pow(N, d);
    ll b = pow(N * 4, d);
    ll m = a;
    if(N < 54){
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                if(i * i * i + j * j * j == N){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        goto NOTP;
    }
    while(m <= b){
        if(N % m == 0) {
            ll num = m * m - N/m;
            if(num % 3) {
                m++;
                continue;
            }
            num /= 3;
            num *= 4;
            ll check = m * m - num;
            if(is_int(check)){
                cout << "YES" << endl;
                return;
            }
        }
        m++;
    }
    if(m > b){
        NOTP:
        cout << "NO" << endl;
        return;
    }

}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        ll x;
        cin>>x;
        solve(x);
    }
    return 0;
}
