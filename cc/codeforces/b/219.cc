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

void check(map<int,ll> &mp, ll p){
    string s = to_string(p);
    int cnt = 0, i = sz(s)-1;
    while(i >= 0 and s[i] == '9'){
        i--;
        cnt++;
    }
    mp[cnt] = p;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    ll p,D;
    cin>>p>>D;
    ll original = p, d = 1;
    int cnt = 0;
    map<int,long long> mp;
    check(mp, p);
    while(d <= original){
        ll sub = p - d * 10 + (d - 1);
        db(sub);
        if(original - (sub) <= D) {
            db(p,sub);
            p = sub;
            db(p);
            check(mp,p);
        }
        d *= 10;
    }
    ll ans = original;
    for (int i = 18; i >= 0; i--) {
        if(mp[i]) {
            ans = mp[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
