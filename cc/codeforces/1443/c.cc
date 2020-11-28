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
    vi a(n), b(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    ll l = 1, r = *max_element(all(a));
    ll ans = r;
    while(l < r){
      ll mid = (l+r)/2;
      ll temp = 0;
      for (int i = 0; i < n; i++) {
        if(a[i] > mid) temp += b[i];
      }
      if(temp <= mid){
        r = mid;
        ans = mid;
      }
      else{
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
