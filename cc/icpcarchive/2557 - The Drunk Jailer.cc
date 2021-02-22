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

int count_primes(int n){
    vi p(n + 1, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if(p[i]== 0) continue;
        for (int j = i * 2; j <= n; j+= i) {
            p[j] = 0;
        }
    }
    return accumulate(all(p), 0);
}

int count_squares(int n){
    int i = 1, cnt = 0;
    while(i * i <= n) {
        cnt++;
        i++;
    }
    return cnt;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        int n;
        cin>>n;
        cout << count_squares(n) << endl;
    }
    return 0;
}
