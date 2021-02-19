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

string day(vi &a){
    return to_string(a[0]) + "-" + to_string(a[1]) + "-" + to_string(a[2]);
}

bool is_feb(int m){
    return m == 2;
}

bool month30(int m){
    return (m == 4 or m == 6 or m == 9 or m == 11);
}

bool month31(int m){
    return not month30(m) and not is_feb(m);
}

bool is_leap(int yr){
    if(yr % 400 == 0) return true;
    if(yr % 100 == 0) return false;
    return yr % 4 == 0;
}
string next(vi a){
    if(a[0] < 28) {
        a[0]++;
    }
    else if(month31(a[1])){
        a[0]++;
        if(a[0] == 32){
            a[0] = 1;
            a[1]++;
            if(a[1] == 13) {
                a[1] = 1;
                a[2]++;
            }
        }
    }
    else if(month30(a[1])){
        a[0]++;
        if(a[0] == 31){
            a[0] = 1;
            a[1]++;
            if(a[1] == 13) {
                a[1] = 1;
                a[2]++;
            }
        }
    }
    else if(is_feb(a[1])){
        if(is_leap(a[2])) {
            a[0]++;
            if(a[0] == 30){
                a[0] = 1;
                a[1]++;
            }
        }
        else {
            a[0] = 1;
            a[1]++;
        }
    }
    return day(a);
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    int n;
    while(cin>>n){
        if(not n) break;
        vvi a(n, vi(4));
        REP(i,n) read(a[i]);
        ll res = 0, cnt = 0;
        for (int i = 1; i < n; i++) {
            if(next(a[i-1]) == day(a[i])) {
                res += a[i][3] - a[i-1][3];
                cnt++;
            }
        }
        cout << cnt << ' ' << res << endl;
    }
    return 0;
}
