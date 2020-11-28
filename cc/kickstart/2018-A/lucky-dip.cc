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
//
// Case #1: 2.500000
// Case #2: 6.000000
// Case #3: 80000.000000
// Case #4: 10.000000
// Case #5: 12.358400

void solve(){
  int n,k;
  cin>>n>>k;
  vi v(n);
  REP(i,n) cin>>v[i];
  vector<double> E(k+1);
  E[0] = accumulate(all(v), 0);
  E[0] /= n;
  for(int i = 1; i <= k; i++){
    for (int j = 0; j < n; j++) {
      E[i] += max(E[i-1], (double) v[j]);
    }
    E[i] /= n;
  }
  cout<< fixed << setprecision(6) << E[k];
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout<<"Case #"<<i<<": ";
    solve();
    cout<<"\n";
  }
  return 0;
}
