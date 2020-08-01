#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

int min_distribution(int a[], int n, int k){
  sort(a,a+n);
  int ans, min_so_far = INT_MAX;
  for (int i = 0; i < n-k+1; i++) {
    min_so_far = a[i+k-1] - a[i];
    ans = min(min_so_far, ans);
  }
  return ans;
}
int32_t main(int32_t argc, char const *argv[]){
T(){
  int n,k;cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  cin>>k;
  cout<<min_distribution(a,n,k)<<endl;
}
  return 0;
}
