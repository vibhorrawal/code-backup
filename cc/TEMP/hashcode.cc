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

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    int D; // simulation time
    cin>>D;

    int I; // number of intersection
    cin>>I;
    vvi g(I);

    int S; // number of streets
    cin>>S;
    vector<string> street_name;


    int v; // number of cars
    cin>>v;

    int f; // bonus
    cin>>f;

    REP(si, S){
        int B, E; // I -> start to end
        cin>>B>>E;
        string name;
        cin>>name;
        street_name.push_back(name);
        g[E].pb(si);
        int L;
        cin>>L;
    }

    cout<<I<<endl;

    for (int i = 0; i < I; i++) {
        cout<<i<<endl;
        cout << g[i].size() << endl;
        for(int street : g[i]){
            cout << street_name[street] << ' ' << rand(1, D) << endl;
        }
    }
    return 0;
}
