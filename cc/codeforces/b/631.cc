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
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int main(){
    fastIO;
    int n, m, k;
    cin>>n>>m>>k;
    vi row(n), col(m), color(k + 1);

    REP(i,k){
        int t, rc;
        cin>>t>>rc>>color[i+1];
        rc--;
        if(t == 1) row[rc] = i + 1;
        else col[rc] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << color[max(row[i], col[j])] << ' ';
        }
        cout << endl;
    }
}
/*
int main(){
    fastIO;
    int n, m, k;
    cin>>n>>m>>k;
    vvi v(n, vi(m));
    unordered_map<int,pair<int,int>> row, col; // time, color

    REP(i, k){
        int val, rc, color;
        cin>>val>>rc>>color;
        rc--;
        if(val == 1){
            // row
            row[rc] = {i + 1, color};
        }
        else{
            col[rc] = {i + 1, color};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(not row.count(i) and not col.count(j)) continue;
            if(row[i].first > col[j].first) v[i][j] = row[i].second;
            else v[i][j] = col[j].second;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
*/

/*
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n, m, k;
    cin>>n>>m>>k;
    vvi v(n, vi(m));
    vvi in(k, vi(3));
    REP(i,k) read(in[i]);
    db(k);
    unordered_set<int> row, col;
    for(int i = k-1; i >= 0; i--){
        if(in[i][0] == 1){
            int r = in[i][1]-1, color = in[i][2];
            if(row.count(r)) continue;
            bool painted = false;
            for(int j = 0; j < m; j++){
                if(v[r][j]) continue;
                painted = true;
                v[r][j] = color;
            }
            if(not painted) row.insert(r);
        }
        else{
            int c = in[i][1]-1, color = in[i][2];
            if(col.count(c)) continue;
            bool painted = false;

            for (int ii = 0; ii < n; ii++) {
                if(v[ii][c]) continue;
                painted = true;
                v[ii][c] = color;
            }
            if(not painted) col.insert(c);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
*/
