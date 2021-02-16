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

int main(){
    ll n,k;
    cin>>n>>k;
    vi v(n), vis(n);
    read(v);
    sort(all(v));
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        ll x = v[i], l = 0;
        auto it = v.begin();
        while((it = lower_bound(all(v), x)) != v.end()){
            if(*it != x or vis[it-v.begin()]) break;
            x *= k;
            l++;
            vis[it-v.begin()] = 1;
        }
        vis[i] = 1;
        
        cnt += (l + 1)/2;
    }
    cout << cnt << endl;
}
/*
int32_t main(int argc, char const *argv[]){
    fastIO;
    ll n,k;
    cin>>n>>k;
    vi v(n), vis(n);
    read(v);
    sort(all(v));
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        auto it = lower_bound(all(v), v[i] * k);
        if(it == v.end()) {
            CNT:
            cnt++;
            vis[i] = 1;
            continue;
        }
        int id = it - v.begin();
        if(v[id] != v[i] * k) goto CNT;
        vis[id] = true;
        vis[i] = 1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
*/
