#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int msis(int a[], int n){
  int dp[n];
  REP(i,n) dp[i] = a[i];

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if(a[i] > a[j] && dp[i] < dp[j] + a[i])
        dp[i] = dp[j] + a[i];
    }
  }
  return *max_element(dp,dp+n);
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    cout<<msis(a,n)<<endl;
  }
  return 0;
}
