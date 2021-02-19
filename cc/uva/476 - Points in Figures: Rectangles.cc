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
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

struct P {
    double x, y;
    void read(){
        cin>>x>>y;
    }
};

bool is_inside(pair<P,P> rect, double x, double y){
    if(x <= rect.first.x or rect.second.x <= x) return false;
    if(y <= rect.second.y or rect.first.y <= y) return false;
    return true;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    vector<pair<P,P>> rect;
    while(true){
        char c;
        cin>>c;
        if(c == '*') break;
        P p,q;
        p.read();
        q.read();
        rect.pb({p,q});
    }
    db(sz(rect));
    int p = 1;
    while (true) {
        P pnt;
        pnt.read();
        if(pnt.x == 9999.9 and pnt.y == 9999.9) break;
        bool inside = false;
        for(int i = 0; i < sz(rect); i++){
            if(is_inside(rect[i], pnt.x, pnt.y)){
                cout<<"Point " << p << " is contained in figure "<<i+1 << endl;
                inside = true;
                // break;
            }
        }
        if(not inside) cout << "Point " << p << " is not contained in any figure" << endl;
        p++;
    }
    return 0;
}
