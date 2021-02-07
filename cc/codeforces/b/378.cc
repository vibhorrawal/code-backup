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
    int n;
    cin>>n;
    vvi a(n), b(n), res;
    REP(i, n) {
        int t;
        cin>>t;
        a[i] = {t, i, 1};
        cin>>t;
        b[i] = {t, i, 2};
        res.pb(a[i]);
        res.pb(b[i]);
    }
    sort(all(res));
    vi wa(n), wb(n);
    for(int i = 0; i < n/2; i++) wa[i] = wb[i] = 1;
    for(int i = 0; i < n; i++) {
        if(res[i][2] == 1) wa[res[i][1]] = 1;
        else wb[res[i][1]] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << wa[i];
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        cout << wb[i];
    }
    cout << endl;
    return 0;
}
