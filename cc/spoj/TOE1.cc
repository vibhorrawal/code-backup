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

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
/*
int check(int i, int j, vvc &vis, vvc &b){
    db(i,j);
    if(vis[i][j]) return 0;
    if(b[i][j] == '.') return 0;
    int cnt = 1;
    vis[i][j] = 1;
    for (int k = 0; k < 8; k++) {
        int ii = i + dx[k], jj = j + dy[k];
        if(ii < 0 or ii >= 3 or jj < 0 or jj >= 3) continue;
        if(b[ii][jj] == '.' or vis[ii][jj]) continue;
        if(b[i][j] == b[ii][jj])
            cnt += check(ii,jj,vis, b);
    }
    return cnt;
}
void solve(){
    vvc b(3, vc(3, 0));
    vvc vis = b;
    REP(i,3) read(b[i]);
    int cnt = 0, x = 0, o = 0;

    // db(check(0,2,vis,b));
    // return;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(b[i][j] == 'X') x++;
            if(b[i][j] == 'O') o++;

        }
    }
    // db(cnt);
    for (int r = 0; r < 3; r++) {
        if(b[r][0] == b[r][1] and b[r][1] == b[r][2]) cnt++;
    }
    for (int c = 0; c < 3; c++) {
        if(b[0][c] == b[1][c] and b[1][c] == b[2][c]) cnt++;
    }
    cnt += b[0][0] == b[1][1] and b[1][1] == b[2][2];
    cnt += b[0][2] == b[1][1] and b[1][1] == b[2][0];

    if(cnt > 1 or (o > x)) {
        cout << "no" << endl;
        return;
    }
    cout << "yes" << endl;
}
*/

unordered_set<string> state;

string to_string(const vvc &b){
    string res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res += b[i][j];
        }
    }
    return res;
}
bool contains(const vvc &b){
    string s = to_string(b);
    return !state.insert(s).second;
}

bool is_valid(const vvc &b, bool is_x){
    char ch = !is_x ? 'X' : 'O';

    for (int r = 0; r < 3; r++) {
        if(b[r][0] == '.') continue;
        if(b[r][0] == b[r][1] and b[r][1] == b[r][2]) {
            if(b[r][0] == ch){
                contains(b);
            }
            return false;
        }
    }
    for (int c = 0; c < 3; c++) {
        if(b[0][c] == '.') continue;

        if(b[0][c] == b[1][c] and b[1][c] == b[2][c]) {
            if(b[0][c] == ch){
                contains(b);
            }
            return false;
        }
    }

    if(b[0][0] != '.' and b[0][0] == b[1][1] and b[1][1] == b[2][2]) {
        if(b[0][0] == ch){
            contains(b);
        }
        return false;
    }

    if(b[1][1] != '.' and b[0][2] == b[1][1] and b[1][1] == b[2][0]) {
        if(b[0][2] == ch){
            contains(b);
        }
        return false;
    }
    return true;
}
void build(vvc &b, bool is_x){
    if(!is_valid(b, is_x)) return;
    if(contains(b)) return;

    char c = is_x ? 'X' : 'O';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(b[i][j] != '.') continue;
            b[i][j] = c;
            build(b, not is_x);
            b[i][j] = '.';
        }
    }
}
void generate(){
    vvc b(3, vc(3, '.'));
    build(b, true);
}

string solve2(){
    vvc b(3, vc(3, 0));
    vvc vis = b;
    REP(i,3) read(b[i]);
    if(state.count(to_string(b))) return "yes";
    return "no";
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    generate();
    T(){
        cout << solve2();
        if(tc) cout << endl;
    }
    return 0;
}
