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
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

struct P{
    double x, y;
    void read(){
        cin>>x>>y;
    }

    P operator- (const P &b) {
        return {x - b.x, y - b.y};
    }

    P operator+(const P &b){
        return {x + b.x, y + b.y};
    }

    bool operator==(const P &b){
        return x == b.x and y == b.y;
    }
};

string to_string(P &b){
    return to_string(b.x) + ", " + to_string(b.y);
}

void solve(P &b, P &a, P &c){
    P ans = (b - a) + (c - a) + a;
    cout << fixed << setprecision(3) <<  ans.x << ' ' << ans.y << endl;
}
const double eps = 1e-9;
int32_t main(int argc, char const *argv[]){
    fastIO;
    P b;
    while(cin>>b.x>>b.y){
        P a, c, d;
        // b.read();
        a.read();
        d.read();
        c.read();
        db(a);
        db(b);
        db(c);

        if(a == d)
            solve(b,a,c);
        else if(a == b)
            solve(c, a, d);
        else if(a == c)
            solve(b, a, d);
        else if(b == c)
            solve(a, b, d);
        else if(b == d)
            solve(a, b, c);
        else
            solve(a, c, b);

        /*
        double mac = (c.y - a.y) / (c.x - a.x + eps);
        double mab = (b.y - a.y) / (b.x - a.x + eps);

        double x = (mac * (c.x - b.x) + (b.y - c.y)) / (mab - mac + eps);
        double y = mab * (x - c.x) + c.y;
        db(x,y);
        */
        // cout /* << fixed << setprecision(9) */ << b.x + c.x - a.x << ' ' << b.y + c.y - a.y << endl;
    }
    return 0;
}
