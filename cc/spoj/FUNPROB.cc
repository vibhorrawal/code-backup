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

double solve(ll n, ll m){
    if(n > m) return 0;
    return double(m + 1 - n) / (m + 1);
}
int32_t main(int argc, char const *argv[]){
    while(1){
        ll n, m;
        cin>>n>>m;
        if(not n and not m) break;
        printf("%.6f\n", solve(n, m));
    }
    return 0;
}
