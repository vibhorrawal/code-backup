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

const int MX = 10;
struct Trie {
    struct Trie *child[MX];
    Trie(){
        for (int i = 0; i < MX; i++) {
            child[i] = NULL;
        }
    }
};

vector<int> convert(int x, int b){
    vector<int> res;
    int t = 9;
    while(t--){
        res.push_back(x % b);
        x /= b;
    }
    reverse(res.begin(), res.end());
    return res;
}

void insert(vector<int> b, Trie *root){
    for(int i : b){
        if(!root->child[i]) root->child[i] = new Trie();
        root = root->child[i];
    }
}

int find(vector<int> bb, int b, Trie *root){
    int res = 0;
    for(int i : bb){
        bool used = false;
        for(int c = b-1 - i; c >= 0; c--){
            // db(c);
            if(root->child[c]){
                // db(c);
                root = root->child[c];
                used = true;
                res += c;
                break;
            }
        }
        if(!used) for(int c = b - 1; c > b-1-i; c--){
            // db(c);
            if(root->child[c]){
                // db(c);
                root = root->child[c];
                used = true;
                res += c;
                break;
            }
        }
        assert(used);
        res *= b;
    }
    return res / b;
}

void print(Trie *root, int d, int b, int depth){
    // int res = 0;
    if(depth == 0) cout<< d << ' ';
    d *= 10;
    for (int i = 0; i < MX; i++) {
        if(root->child[i]){
            print(root->child[i], d + i, b, depth-1);
        }
    }
}
int solve(vector<int> v, int b){
    Trie *root = new Trie();
    int ans = 0;
    insert(convert(v[v.size()-1], b), root);
    v.pop_back();
    for(int x : v){
        int y = find(convert(x, b), b, root);
        db(x, y);
        ans = max(ans, x + y);
        insert(convert(x, b), root);
    }
    return ans;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    vector<int> v = {10,99,88,48,213};
    cout<<solve(v, 7)<<endl;
    return 0;
}
