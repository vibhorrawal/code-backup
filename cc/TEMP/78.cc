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

inline bool isPowerOfTwo (int x) {
    return x && (!(x&(x-1)));
}
const int N = 1e6 + 1;

// vector<int> memo(N);
vi prime;
unordered_map<int,int> dp;
void fill_primes() {
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i] && (long long)i * i < N) {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < N; i++) {
        if(is_prime[i]) prime.pb(i);
    }
}

ll count_primes(ll k){
    ll res = 1;
    for(int x : prime){
        if(k == 1) break;
        if(k % x) continue;
        ll cnt = 1;
        while(k % x == 0){
            cnt++;
            k /= x;
        }
        res *= cnt;
        if(not isPowerOfTwo(res)) return res;
    }
    return res;
}

void precompute(){
    fill_primes();
    return;
    // db(prime.size());
    // memo[1] = 1;
    // ll res = 1;
    // for (int i = 2; i < N; i++) {
    //     ll cnt = count_primes(i);
    //     if(isPowerOfTwo(cnt)) res++;
    //     memo[i] = res;
    // }
    // db(N);
}

ll solve(ll n){
    if(n == 1) return 1;
    if(dp[n]) return dp[n];
    ll s = solve(n-1);
    ll cnt = count_primes(n);
    if(isPowerOfTwo(cnt)) s++;
    return dp[n] = s;
}
int32_t main(int argc, char const *argv[]){
    precompute();
    fastIO;
    T(){
        int n;
        cin>>n;
        cout << solve(n) << endl;
    }
    return 0;
}
