#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
// #define endl char(10)
// template<class T> void read(T& x) { cin >> x; }
// template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
// template<class T>string to_string(const vector<T> &v) {
//   string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
// void DBG() { cerr << "]" << endl; }
// template<class H, class... T> void DBG(H h, T... t) {
//   cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
// #define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)


int32_t main(int argc, char const *argv[]){
    int n;
    cin>>n;
    vi v(n), dp(n);
    // read(v);
    for(int i = 0; i < n; i++) cin>>v[i];
    dp = v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(v[j] == 0)
                continue;
            if(v[i] % v[j] == 0)
                dp[i] = max(dp[i], dp[j] + v[i]);
        }
    }
    cout << *max_element(all(dp)) << endl;
    return 0;
}
