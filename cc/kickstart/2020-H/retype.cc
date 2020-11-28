#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

void solve(){
  ll n,k,s;
  cin>>n>>s>>k;
  ll restart = s-1 + 1 + n;
  ll redo = s-1 + 1 + (s-k-1) + n-k+1;
  db(restart);
  db(redo);
  cout << min(restart, redo);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" <<i<<": ";
    solve();
    cout << "\n";
  }
  return 0;
}
