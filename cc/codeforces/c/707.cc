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

int main(){
    ll n;
    cin>>n;
    if(n < 3){
        cout << "-1" << endl;
        return 0;
    }
    /*
    n * n + m * m == k * k
    n2 = k2 - m2;
    n^2 = (k+m) * (k - m);
    ---
    k+m = n^2
    k-m = 1
    k = (1+n^2)/2
    m = (n^2-1)/2
    ---
    since we want them integers
    this above formula works for odd n

    For even let's again split
    k+m = n^2/2
    k-m  = 2
    k = 1/4 * n^2 + 1
    m = 1/4 * n^2 - 1

        https://codeforces.com/blog/entry/46681
    */
    ll k,m;
    if(n & 1){
        k = (1 + n * n)/2;
        m = k - 1;
    }
    else{
        k = (n * n)/4 + 1;
        m = k - 2;
    }

    cout << k << ' ' << m << endl;
}

/*
vi factors(ll n){
    vi f;
    db(n);
    for (ll i = 1; i <= sqrt(n); i++) {
        if(n % i) continue;
        db(i, n % i);
        f.pb(i);
        if(i != n/i) f.pb(n/i);
    }
    f.erase(f.begin());
    return f;
}
// k, a, a+1
ll n;

void check_a(vi &f){
    for(ll k : f){
        db(k);
        ll a = (k * k -1) / 2;

        ll A = k * (n / k);
        ll B = a * (n / k);
        ll C = (a + 1) * (n / k);
        db(A,B,C);
        if(A * A + B * B != C * C) continue;
        cout << B << ' '<< C << endl;
        exit(0);
    }
}

void check_b(vi &f){
    for(ll a : f){
        ll k = sqrt(1 + 2 * a);
        if(k * k != 1 + 2 * a) continue;
        ll A = k * (n / a);
        ll B = a * (n / a);
        ll C = (a + 1) * (n / a);
        if(A * A + B * B != C * C) continue;
        cout << A <<' '<< C << endl;
        exit(0);
    }
}

void check_c(vi &f) {
    for(ll a1 : f){
        ll a = a1 - 1;
        ll k = sqrt(1 + 2 * a);
        if(k * k != 1 + 2 * a) continue;
        ll A = k * (n / a1);
        ll B = (a) * (n / a1);
        ll C = a1 * (n / a1);
        if(A * A + B * B != C * C) continue;
        cout << A <<' '<< B << endl;
        exit(0);
    }
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    cin>>n;
    vi f = factors(n);
    // a * a + b * b = c * c
    check_a(f);
    check_b(f);
    check_c(f);
    cout << "-1" << endl;
    return 0;
}
*/
