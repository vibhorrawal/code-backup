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
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  cout << min((a[1]-a[0]),n>2?a[2]-a[0]:INT_MAX)<<' '<<a[n-1]-a[0] << endl;
  for (int i = 1; i < n-1; i++) {
    cout<<min(a[i] - a[i-1],a[i+1]-a[i]) << ' ' << max(a[i]-a[0],a[n-1]-a[i])<<endl;
  }
  cout << min(a[n-1]-a[n-2],n>2?a[n-1]-a[n-3]:INT_MAX)<<' '<<a[n-1] - a[0] << endl;

  return 0;
}