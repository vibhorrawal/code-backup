#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

int trap(int a[], int n){
  int max_so_far = a[0];
  int left[n],right[n];
  for (int i = 0; i < n; i++) {
    max_so_far = max(max_so_far, a[i]);
    left[i] = max_so_far;
  }
  max_so_far = a[n-1];
  for(int i = n-1; i>=0;i--){
    max_so_far = max(max_so_far, a[i]);
    right[i] = max_so_far;
  }
  int ans = 0;
  for(int i = 1;i<n-1;i++){
    ans += min(left[i], right[i])-a[i];
  }
  return ans;
}
int main(int argc, char const *argv[]){
  T(){
    int n;cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    cout << trap(a,n) << endl;
  }
  return 0;
}
