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

/*
int rev(int a){
    int b = 0;
    while(a){
        b = (b * 10) + (a % 10);
        a /= 10;
    }
    return b;
}
*/

string sum(const string &a, const string &b){
    int i = sz(a)-1, j = sz(b)-1;
    string res;
    int c = 0;
    while(i >= 0 or j >= 0){
        int s = c + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
        c = s / 10;
        s %= 10;
        res += to_string(s);
    }
    if(c) res += to_string(c);
    reverse(all(res));
    return res;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        string a, b;
        cin>>a>>b;
        reverse(all(a));
        reverse(all(b));

        string res = sum(a, b);
        reverse(all(res));
        while(res[0] == '0') res.erase(res.begin());
        
        cout << res << endl;
    }
    return 0;
}
