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
  cerr << to_string(h); if(sizeof...(t)) cerr << " "; DBG(t...); }
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, k;
    cin>>n>>k;
    vvi v(n, vi(2));
    REP(i,n) {
        cin>>v[i][0]; v[i][1] = i+1;
    }
    sort(all(v));
    vvi diff;
    while(k>0 and v[0][0] < v.back()[0]-1){
        int delta = min(1, (v.back()[0] - v[0][0])/2);
        if(delta == k) delta = 1;
        k -= delta;
        v[0][0] += delta;
        v.back()[0] -= delta;
        diff.pb({v.back()[1], v[0][1]});
        sort(all(v));
    }
    cout<<v.back()[0] - v[0][0] << ' ';
    cout << sz(diff) << endl;
    for(auto it : diff) cout<<to_string(it)<<endl;
    return 0;
}
