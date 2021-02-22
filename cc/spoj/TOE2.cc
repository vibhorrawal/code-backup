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

bool possible;

int winner(const vvc &b, char w){
    int r = 0, c = 0, d = 0;
    for (int i = 0; i < 3; i++) {
        if(b[i][0] == w and b[i][1] == w and b[i][2] == w) r++;
    }
    for (int j = 0; j < 3; j++) {
        if(b[0][j] == w and b[1][j] == w and b[2][j] == w) c++;
    }
    if(b[0][0] == w and b[1][1] == w and b[2][2] == w) d++;
    if(b[0][2] == w and b[1][1] == w and b[2][0] == w) d++;

    if(r > 1 or c > 1) possible = false;
    return r + c + d;
}

int count(const vvc &b, char c){
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cnt += b[i][j] == c;
        }
    }
    return cnt;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    vvc b(3, vc(3));
    while(1){
        REP(i,3) read(b[i]);
        if(b[0][0] == 'e') break;
        possible = true;

        int winnerx = winner(b, 'X'), winnero = winner(b, 'O');
        int x = count(b, 'X'), o = count(b, 'O');

        // if(winnerx > 1 or winnero > 1) possible = false;
        if(winnerx and winnero) possible = false;
        if(not winnerx and not winnero and not(x + o == 9)) possible = false;
        if(winnerx and x - o != 1) possible = false;
        if(winnero and x != o) possible = false;
        if(not(x - o == 1 or x - o == 0)) possible = false;

        if(possible) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }
    return 0;
}
