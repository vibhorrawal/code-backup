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
    string s,t;
    cin>>s>>t;
    unordered_map<char,int> sm, tm;
    for(char c : s) sm[c]++;
    for(char c : t) tm[c]++;
    int yay = 0, whoops = 0;
    for(char c = 'a'; c <= 'z'; c++){
        char lo = c, up = toupper(c);
        int delta = min(sm[lo], tm[lo]);
        sm[lo] -= delta;
        tm[lo] -= delta;
        yay += delta;

        delta = min(sm[up], tm[up]);
        sm[up] -= delta;
        tm[up] -= delta;
        yay += delta;

        delta = min(sm[lo], tm[up]);
        sm[lo] -= delta;
        tm[up] -= delta;
        whoops += delta;

        delta = min(sm[up], tm[lo]);
        sm[up] -= delta;
        tm[lo] -= delta;
        whoops += delta;
    }
    cout << yay << ' ' << whoops << endl;
    return 0;
}
