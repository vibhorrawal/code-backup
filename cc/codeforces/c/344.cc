#include<bits/stdc++.h>
using namespace std;
// typedef unsigned __int128 ll;
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

#define ll long long

// ll solve(ll a, ll b){
//     if(a == 1 and b == 1){
//         return 1;
//     }
//     if(b == 1) return a;
//     if(a > b) return 1 + solve(a-b, b);
//     return 1 + solve(a, b - a);
// }

ll solve(ll a, ll b){
    ll cnt = 0;
    while(a > 1 and b > 1){
        // ll gcd = __gcd(a, b);
        // a /= gcd;
        // b /= gcd;
        if(a == 1 and b == 1) break;
        if(a > b) {
            ll div = a/b, rem = a % b;
            cnt += div;
            a = rem;
        }
        else /*if(b > a) */{
            ll div = b/a, rem = b % a;
            cnt += div;
            b = rem;
        }
        /*else assert(false);*/
    }
    if(a == 1 and b == 1) return cnt + 1;
    if(a != 1 and b == 1) return cnt + a - 1 + b;
    if(b != 1 and a == 1) return cnt + b - 1 + a;
    db(a, b);
    assert(false);
}
int main(){
    ll a, b;
    cin>>a>>b;
    cout << solve(a, b) << endl;
}

/*
struct F {
    ll n, d;
    F(ll a, ll b){
        ll gcd = __gcd(a, b);
        n = a/gcd;
        d = b/gcd;
    }
    bool operator< (const F &b) const {
        return n * b.d < b.n * d;
    }

};

F add(const F &a, const F &b) {
    return F(a.n * b.d + b.n * a.d, a.d * b.d);
}

F mul(const F &a, const F &b) {
    return F(a.n * b.n, a.d * b.d);
}

F inv(const F &a) {
    return F(a.d, a.n);
}

F series(const F &a, const F&b) {
    return add(a, b);
}

F parallel(const F &a, const F &b) {
    return mul(mul(a, b), inv(add(a, b)));
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    long long a, b;
    cin>>a>>b;
    F req = F(a,b);
    queue<F> q;
    set<F> vis;
    q.push({1,1});
    int s = 1;
    while(q.size()){
        int qs = sz(q);
        db(qs);
        while(qs--){
            auto it = q.front(); q.pop();
            // if(vis.count(it)) continue;
            // vis.insert(it);
            if(it.n == req.n and it.d == req.d) {
                cout << s << endl;
                return 0;
            }

            q.push(series(it, {1,1}));
            q.push(parallel(it, {1,1}));
        }
        s++;
        db(s);
    }
    assert(false);
    return 0;
}
*/
