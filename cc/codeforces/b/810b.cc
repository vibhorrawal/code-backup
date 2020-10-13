#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
struct product{
  int k,l;
};
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,f;
  cin>>n>>f;
  std::vector<product> arr(n);
  REP(i,n){
    cin>>arr[i].k>>arr[i].l;
  }
  sort(arr.rbegin(), arr.rend(), [](product a, product b){
    return (min(2 * a.k, a.l) - min(a.k,a.l)) < (min(2*b.k, b.l) - min(b.k,b.l));
  });
  ll i = 0, ans = 0;
  for(; i < f; i++){
    ans += min(2 * arr[i].k, arr[i].l);
  }
  for(; i < n; i++)
     ans += min(arr[i].k, arr[i].l);
  cout << ans << endl;
  return 0;
}
