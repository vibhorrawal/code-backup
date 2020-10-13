#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

void solve(){
  int n, k;
  cin >> n >> k;
  vi v(n);
  REP(i,n) cin>>v[i];
  sort(v.rbegin(), v.rend());
  ll sum = 0;
  for (int i = 0; i <= k; i++) {
    sum += v[i];
  }
  cout << sum << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    solve();
  }
  return 0;
}
