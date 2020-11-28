#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin>>n;
    vi a(n);
    REP(i,n) cin>>a[i];
    ll ans = 1;
    for (int i = 1; i < n; i++) {
      if(a[i] < a[i-1]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
