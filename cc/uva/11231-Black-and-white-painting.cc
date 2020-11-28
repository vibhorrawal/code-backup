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
  int n,m,c;
  while(cin>>n>>m>>c){
    if(n == 0) break;
    ll ans = 0;
    if(c == 1){
      ans = (n-6)/2 * (m-6)/2;
      cout << ans << endl;
    }
    else{
      ans = (n-6)/2 * (m-7)/2 + (n-7)/2 * (m-6)/2;
      cout << ans << endl;
    }
  }
  return 0;
}
