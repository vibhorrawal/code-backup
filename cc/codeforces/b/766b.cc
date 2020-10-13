#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(){
  fastIO;
  int n; cin>>n;
  vector<int> v(n);
  REP(i,n) cin>>v[i];
  sort(v.begin(), v.end());
  int count = 0;
  for(int i = 0; i < n-2; i++){
    if(v[i] + v[i+1] > v[i+2])
      count++;
  }
  db(count);
  cout<<(count ? "YES" : "NO")<<endl;
  return 0;
}
