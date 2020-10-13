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
  int sum = accumulate(a,a+n,0);
  sum = (sum + 0.5)/2;
  sort(a,a+n);
  int acc=0;
  for (int i = n-1; i>=0; i--) {
    acc += a[i];
    if(acc>sum) {
      cout << n - i << endl;
      return 0;
    }
  }
  return 0;
}
