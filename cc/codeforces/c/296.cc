#include<bits/stdc++.h>
using namespace std;
#define int long long
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
  cerr << to_string(h); if(sizeof...(t)) cerr << " "; DBG(t...); }
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int32_t main(){
    fastIO;
    int n, m, k;
    cin>>n>>m>>k;
    vi v(n), l(m), r(m), d(m), x(k), y(k);
    read(v);
    db(v);
    REP(i, m) {
        cin>>l[i]>>r[i]>>d[i];
        l[i]--, r[i]--;
    }
    db(l);
    db(r);
    db(d);
    REP(i, k) {
        cin>>x[i]>>y[i];
        x[i]--,y[i]--;
    }
    db('-');
    db(x);
    db(y);
    vi mul(m + 1);
    int cnt = 0;
    for(int i = 0; i < k; i++){
        assert(0 <= x[i] and x[i] <= sz(mul));
        assert(0 <= y[i] + 1 and y[i] + 1 <= sz(mul));
        mul[x[i]]++;
        mul[y[i] + 1]--;
    }
    for(int i = 1; i <= m; i++){
        mul[i] += mul[i-1];
    }
    db(mul);
    for(int i = 0; i < m; i++) d[i] *= mul[i];
    db(d);
    vi t(n + 1);
    for(int i = 0; i < m; i++){
        db(i, l[i]);
        assert(0 <= l[i] and l[i] <= sz(t));
        assert(0 <= r[i] + 1 and r[i] + 1 <= sz(t));
        t[l[i]] += d[i];
        t[r[i] + 1] -= d[i];
    }
    db(t);
    for (int i = 0; i < n; i++) {
        cnt += t[i];
        v[i] += cnt;
    }
    cout<<to_string(v);
    cout<<endl;
    return 0;
}
