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
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

struct P{
    int x, y;
    void read(){
        cin>>x>>y;
    }
};

struct Rect {
    P l,r;
    void read(){
        l.read();
        r.read();
    }
};

bool non_intersect(Rect &a, Rect &b){
    for (int rep = 0; rep < 2; rep++) {
        if(b.r.x <= a.l.x or a.r.x <= b.l.x) return true;
        if(b.r.y <= a.l.y or a.r.y <= b.l.y) return true;
        swap(a, b);
    }
    return false;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        Rect a, b;
        a.read();
        b.read();
        if(non_intersect(a, b)){
            cout << "No Overlap" << endl;
        }
        else{
            cout << max(a.l.x, b.l.x) << ' ' << max(a.l.y, b.l.y)
            << ' ' << min(a.r.x, b.r.x) << ' ' << min(a.r.y, b.r.y) << endl;
        }
        if(tc) cout<<endl;
    }
    return 0;
}
