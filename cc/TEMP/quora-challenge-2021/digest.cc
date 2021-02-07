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

bool common(vi &a, vi &b){
    int i = 0, j = 0;
    while(i < sz(a) and j < sz(b)){
        if(a[i] == b[j]) return true;
        if(a[i] < b[j]) i++;
        else j++;
    }
    return false;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    const int INF = 1e9 + 5;
    int n, m;
    cin>>n>>m;
    vi user_created_story(n+1);
    for(int i = 1; i <= n; i++) cin>>user_created_story[i];
    int p, q;
    cin>>p>>q;
    vvi user_follows_user(m+1);
    REP(t, p){
        int i, j;
        cin>>i>>j;
        user_follows_user[i].pb(j);
    }
    for(int i = 1; i <= m; i++) sort(all(user_follows_user[i]));
    
    vvi user_follows_story_by(m+1), user_follows_story(m+1);
    REP(t, q){
        int i, k;
        cin>>i>>k;
        user_follows_story_by[i].pb(user_created_story[k]);
        user_follows_story[i].pb(k);
    }
    for(int i = 1; i <= m; i++) sort(all(user_follows_story[i]));

    vvi a(m+1, vi(m+1)), b(m+1, vi(n+1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if(i == j) continue;
            if(binary_search(all(user_follows_user[i]), j)){
                a[i][j] = 3;
                continue;
            }
            for(int userj : user_follows_story_by[i]) {
                if(userj == j){
                    a[i][j] = 2;
                    break;
                }
            }
            if(a[i][j]) continue;
            if(common(user_follows_story[i], user_follows_story[j])){
                a[i][j] = 1;
                continue;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int story = 1; story <= n; story++) {
            if(user_created_story[story] == j) {
                b[j][story] = 2;
            }
            else{
                if(binary_search(all(user_follows_story[j]), story))
                    b[j][story] = 1;
            }
        }
    }
    vvi c(m+1, vector<int>(n+1, -INF)); // score[user][story]
    for (int user = 1; user <= m; user++) {
        for (int story = 1; story <= n; story++) {
            if(user_created_story[story] == user) {
                c[user][story] = -1;
            }
            else if(binary_search(all(user_follows_story[user]), story)){
                c[user][story] = -1;
            }
            else{
                int sum = 0;
                for (int j = 1; j <= m; j++) {
                    sum += a[user][j] * b[j][story];
                }
                c[user][story] = sum;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        // print top 3
        int max1, max2, max3;
        max1 = max2 = max3 = -INF;
        int id1, id2, id3;
        for (int story = 1; story <= n; story++) {
            if(c[i][story] > max1){
                max3 = max2;
                max2 = max1;
                max1 = c[i][story];

                id3 = id2;
                id2 = id1;
                id1 = story;
            }
            else if(c[i][story] > max2) {
                max3 = max2;
                max2 = c[i][story];

                id3 = id2;
                id2 = story;
            }
            else if(c[i][story] > max3){
                max3 = c[i][story];
                id3 = story;
            }
        }
        cout << id1 << ' ' << id2 << ' ' << id3 << endl;
    }
    return 0;
}
